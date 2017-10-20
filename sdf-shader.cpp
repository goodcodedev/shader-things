#include "sdf-shader.hpp"

Expression* box3d(Expression *width, Expression *height, Expression *point) {
	return braced(
		fcall("length", {
			fcall("max", {
				*fcall("abs", {point}) - vec2({width, height})
			})
		})
	);
}