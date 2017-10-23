#pragma once
#include "shader.hpp"

Expression* box3d(Expression *width, Expression *height, Expression *depth, Expression *point);
Expression* sphere3d(Expression *radius, Expression *point);
Expression* unionSdf(Expression *distA, Expression *distB);
Expression* diffSdf(Expression *distA, Expression *distB);
Expression* intersectSdf(Expression *distA, Expression *distB);
Expression* floatWave(Expression *from, Expression *to, Expression *adjustment);