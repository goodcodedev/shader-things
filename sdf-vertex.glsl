attribute vec2 position;
out vec2 vPosition;

void main() {
	gl_Position = vec4(position, 0.0, 1.0);
	vPosition = position;
}