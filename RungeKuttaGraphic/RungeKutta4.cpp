#include "RungeKutta4.h"

RungeKutta4::RungeKutta4(const std::string& function)
	: mVariables{ { "x", 0 }, { "y", 0 } }, mRPN(function, mVariables) {

}
std::vector<MathPoint> RungeKutta4::Calculate(double step, size_t steps_count, 
		double start_arg_value, double start_func_value) {
	std::vector<MathPoint> points;
	points.emplace_back(start_arg_value, start_func_value);
	for (size_t index_step = 0; index_step < steps_count; ++index_step) {
		mVariables["x"] = start_arg_value;
		mVariables["y"] = start_func_value;
		double k1 = step * mRPN.Evaluate();
		mVariables["x"] += (step / 2);
		mVariables["y"] += (k1 / 2);
		double k2 = step * mRPN.Evaluate();
		mVariables["y"] -= (k1 / 2);
		mVariables["y"] += (k2 / 2);
		double k3 = step * mRPN.Evaluate();
		mVariables["x"] += (step / 2);
		mVariables["y"] -= (k2 / 2);
		mVariables["y"] += k3;
		double k4 = step * mRPN.Evaluate();
		start_arg_value += step;
		start_func_value += (1.0 / 6 * (k1 + 2 * k2 + 2 * k3 + k4));
		points.emplace_back(start_arg_value, start_func_value);
	}
	return points;
}
