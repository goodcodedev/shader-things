#version 330
uniform float iGlobalTime;
uniform vec3 uCameraPos;
uniform vec3 uCameraDir;
uniform vec2 uViewport;
in vec2 vPosition;
out vec4 frag_color;

float epsilon = 0.0001;
float minDist = 1.0;
float maxDist = 200.0;
int marchingSteps = 300;

struct external {
	float sdfDist;
} external;

float sdfDist(vec3 point) {
	return external.sdfDist;
}

/*
 * Normalized direction to march in from the eye point
 * for a single pixel.
 */
vec3 rayDirection(float fieldOfView, vec2 size, vec2 fragCoord) {
	vec2 xy = fragCoord - size / 2.0;
	float z = size.y / tan(radians(fieldOfView) / 2.0);
	return normalize(vec3(xy, -z));
}

/*
 * Returns a transform matrix that will transform
 * a ray from view space to world coordinates.
 */
mat3 viewMatrix(vec3 eye, vec3 center, vec3 up) {
	vec3 f = normalize(center - eye);
	vec3 s = cross(f, up);
	vec3 u = cross(s, f);
	return mat3(s, u, -f);
}

vec3 estimateNormal(vec3 point) {
	return normalize(vec3(
		sdfDist(vec3(point.x + epsilon, point.y, point.z)) - sdfDist(vec3(point.x - epsilon, point.y, point.z)),
		sdfDist(vec3(point.x, point.y + epsilon, point.z)) - sdfDist(vec3(point.x, point.y - epsilon, point.z)),
		sdfDist(vec3(point.x, point.y, point.z + epsilon)) - sdfDist(vec3(point.x, point.y, point.z - epsilon))
	));
}

/*
 * Lighting contribution of a single point light source
 * via phong illumination.
 * 
 */
vec3 phongContribForLight(vec3 diffuse, vec3 specular, float alpha,
		vec3 point, vec3 eye, vec3 lightPos, vec3 lightIntensity) {
	vec3 N = estimateNormal(point);
	vec3 L = normalize(lightPos - point);
	vec3 V = normalize(eye - point);
	vec3 R = normalize(reflect(L * -1.0, N));
	float dotLN = dot(L, N);
	float dotRV = dot(R, V);
	if (dotLN < 0.0) {
		/* Light not visible from this point on the surface */
		return vec3(0.0, 0.0, 0.0);
	}
	if (dotRV < 0.0) {
		/* Light reflection in opposite direction, apply only diffuse */
		return lightIntensity * (diffuse * dotLN);
	}
	return lightIntensity * (diffuse * dotLN + specular * pow(dotRV, alpha));
}

/*
 * Lighting via phong illumination
 * https://en.wikipedia.org/wiki/Phong_reflection_model#Description
 */
vec3 phongIllumination(vec3 ambient, vec3 diffuse, vec3 specular, 
		float alpha, vec3 point, vec3 eye) {
	vec3 ambientLight = vec3(0.5, 0.5, 0.5);
	vec3 color = ambientLight * ambient;
	vec3 light1Pos = vec3(4.0 * sin(iGlobalTime),
							2.0,
							4.0 * cos(iGlobalTime));
	vec3 light1Intensity = vec3(0.4, 0.4, 0.4);
	color += phongContribForLight(diffuse, specular, alpha,
									point, eye,
									light1Pos,
									light1Intensity);
	vec3 light2Pos = vec3(2.0 * sin(0.37 * iGlobalTime),
							2.0 * cos(0.37 * iGlobalTime),
							2.0);
	vec3 light2Intensity = vec3(0.4, 0.4, 0.4);
	color += phongContribForLight(diffuse, specular, alpha,
									point, eye,
									light2Pos,
									light2Intensity);
	return color;
}

float shortestDistance(vec3 eye, vec3 dir) {
	float depth = minDist;
	float end = maxDist;
	for (int i = 0; i < marchingSteps; i++) {
		float dist = sdfDist(eye + depth * dir);
		if (dist < epsilon) {
			return depth;
		}
		depth += dist;
		if (depth >= end) {
			/* Moved beyond end */
			return end;
		}
	}
	return end;
}

void main2() {
	float xc = (vPosition.x + 1.0) / 2;
	vec2 fragCoord = ((vPosition + vec2(1.0, -1.0)) * vec2(0.5, -0.5)) * uViewport;
	frag_color = vec4(
		fragCoord.x / uViewport.x,
		fragCoord.y / uViewport.y
		,0.0,1.0);
}

void main() {
	vec2 fragCoord = ((vPosition + vec2(1.0, -1.0)) * vec2(0.5, -0.5)) * uViewport;
	vec3 viewDir = rayDirection(45.0, uViewport, fragCoord);
	vec3 eye = uCameraPos;
	mat3 viewToWorld = viewMatrix(eye, uCameraPos + (uCameraDir * 4.0), vec3(0.0, 1.0, 0.0));
	vec3 worldDir = viewToWorld * viewDir;
	float dist = shortestDistance(eye, worldDir);
	if (dist > (maxDist - epsilon)) {
		/* No shape in ray */
		frag_color = vec4(0.0, 0.0, 0.0, 1.0);
	} else {
		vec3 p = eye + dist * worldDir;
		vec3 alpha = (estimateNormal(p) + vec3(1.0)) / 2.0;
		vec3 diffuse = alpha;
		vec3 specular = vec3(1.0, 1.0, 1.0);
		float shininess = 10.0;
		vec3 color = phongIllumination(alpha, diffuse, specular, shininess, p, eye);
		frag_color = vec4(color, 1.0);
	}
}