#pragma once

#include <unordered_map>
#include <deque>
#include <stack>
#include <cmath>
#include <queue>
#include <iostream>
#include "Tokenizer.h"

class ReversePolishNotation {
	std::queue<Token> mQueue;
	const std::unordered_map<std::string, double>& mVariables;
public:
	ReversePolishNotation(const std::string& data,
		const std::unordered_map<std::string, double>& variables);

	double Evaluate() const;

	const std::queue<Token>& getQueue() const;
};