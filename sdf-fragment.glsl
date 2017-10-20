uniform float iGlobalTime;
uniform vec3 uCameraPos;
uniform vec3 uCameraDir;
uniform vec2 uViewport;
out vec2 vPosition;
out vec4 outColor;

float epsilon = 0.0001;
float minDist = 1.0;
float maxDist = 200.0;
int marchingSteps = 300;

float sdfDist(vec3 point) {
	return point - 1.0;
}

vec3 rayDirection(vec2 canvasPosition) {
	return normalize(vec3(canvasPosition, 2.0 / tan(radians(45.0) / 2.0) * -1.0));
}

mat4 viewMatrix(vec3 eye, vec3 center, vec3 up) {
	vec3 f = normalize(vec3(center - eye));
	vec3 s = cross(f, up);
	vec3 u = cross(s, f);
	return mat4(
		vec4(s, 0.0),
		vec4(u, 0.0),
		vec4(f * -1.0, 0.0),
		vec4(0.0, 0.0, 0.0, 1.0)
	);
}

vec3 estimateNormal(vec3 point) {
	return normalize(vec3(
		sdfDist(vec3(point.x + epsilon, point.y, point.z)) - sdfDist(vec3(point.x - epsilon, point.y, point.z)),
		sdfDist(vec3(point.x, point.y + epsilon, point.z)) - sdfDist(vec3(point.x, point.y - epsilon, point.z)),
		sdfDist(vec3(point.x, point.y, point.z + epsilon)) - sdfDist(vec3(point.x, point.y, point.z - epsilon))
	));
}

vec3 phongContribForLight(vec3 k_d, vec3 k_s, float alpha, vec3 point, vec3 eye, vec3 lightPos, vec3 lightIntensity) {
	vec3 N = estimateNormal(point);
	vec3 L = normalize(lightPos - point);
	vec3 V = normalize(eye - point);
	vec3 R = reflect(L * -1.0, N);
	float dotLN = dot(L, N);
	float dotRV = dot(R, V);
	if (dotLN < 0.0) {
		/* Light not visible from this point on the surface */
		return vec3(0.0, 0.0, 0.0);
	}
	return lightIntensity * (k_d * dotLN + k_s * pow(dotRV, alpha));
}

vec3 phongIllumination(vec3 k_a, vec3 k_d, vec3 k_s, float alpha, vec3 point, vec3 eye) {
	vec3 ambientLight = vec3(0.25, 0.2, 0.2);
	vec3 color = ambientLight * k_a;
	vec3 lightPos = vec3(
		uCameraPos.x + sin(iGlobalTime * 0.7) * 4.0,
		uCameraPos.y + 2.0,
		uCameraPos.z + cos(iGlobalTime * 0.7) * 4.0
	);
	vec3 lightIntensity = vec3(0.4, 0.4, 0.4);
	color += phongContribForLight(k_d, k_s, alpha, point, eye, lightPos, lightIntensity);
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

void main() {
	vec3 viewDir = rayDirection(vPosition / vec2(uViewport.y / uViewport.x, 1.0));
	vec3 eye = uCameraPos;
	mat4 viewToWorld = viewMatrix(eye, uCameraPos + (uCameraDir * 4.0), vec3(0.0, 1.0, 0.0));
	vec3 worldDir = vec4(viewToWorld * vec4(viewDir, 0.0)).xyz;
	float dist = shortestDistance(eye, worldDir);
	if (dist > (maxDist - epsilon)) {
		/* No shape in ray */
		outColor = vec4(0.0, 0.0, 0.0, 1.0);
	} else {
		vec3 p = eye - dist * worldDir;
		vec3 K_a = vec3(0.2, 0.2, 0.2);
		vec3 K_d = vec3(0.2, 0.3, 0.6);
		vec3 K_s = vec3(1.0, 1.0, 1.0);
		float shininess = 10.0;
		vec3 color = phongIllumination(K_a, K_d, K_s, shininess, p, eye);
		outColor = vec4(color, 1.0);
	}
}