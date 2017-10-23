#include "sdf-shader.hpp"

Expression* box3d(Expression *width, Expression *height, Expression *depth, Expression *point) {
	return braced(
		fcall("length", {
			fcall("max", {
				*fcall("abs", {point}) - vec3({width, height, depth}),
				vec3({floatc(0.0), floatc(0.0), floatc(0.0)})
			})
		})
	);
}

Expression* sphere3d(Expression *radius, Expression *point) {
	return *fcall("length", {point}) - radius;
}

Expression* unionSdf(Expression *distA, Expression *distB) {
	return fcall("min", {distA, distB});
}

Expression* diffSdf(Expression *distA, Expression *distB) {
	return fcall("max", {distA, new UnaryMinus(distB)});
}

Expression* intersectSdf(Expression *distA, Expression *distB) {
	return fcall("max", {distA, distB});
}

Expression* floatWave(Expression *from, Expression *to, Expression *adjustment) {
	Expression *adjSin = *fcall("sin", {ref("iGlobalTime")}) + adjustment;
	Expression *halved = *adjSin * floatc(0.5);
	Expression *moved = *halved + floatc(0.5);
	return *from + braced(*braced(*from - to) * braced(moved));
}