#pragma once

#include "ReversePolishNotation.h"

struct MathPoint {
	double x;
	double y;
	MathPoint(double x, double y) : x(x), y(y) {}
};

class RungeKutta4 {
	std::unordered_map<std::string, double> mVariables;
	ReversePolishNotation mRPN;
public:
	RungeKutta4(const std::string& function);
	std::vector<MathPoint> Calculate(double step, size_t steps_count, double start_arg_value, double start_func_value);
};