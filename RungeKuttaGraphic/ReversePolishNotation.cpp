#include "ReversePolishNotation.h"

ReversePolishNotation::ReversePolishNotation(const std::string& data,
	const std::unordered_map<std::string, double>& variables)
	: mVariables(variables) {
	static const std::unordered_map<std::string, size_t> priorities{ { "+", 0 },{ "-", 0 },{ "*", 1 },{ "/", 1 },{ "^", 2 } };
	auto tokens = ParseToTokens(data, variables);
	std::cout << "Tokens " << std::endl;
	for (auto& token : tokens) {
		std::cout << token.value << std::endl;
	}
	std::cout << std::endl;
	std::stack<Token> operations;
	for (auto& token : tokens) {
		//std::cout << "WRK " << token.value << std::endl;
		if (token.token_type == MyTokenType::NUMBER || token.token_type == MyTokenType::VARIABLE) {
			mQueue.push(token);
		}
		else if (token.token_type == MyTokenType::OPERATION) {
			//std::cout << "OP" << std::endl;
			while (!operations.empty() && operations.top().token_type == MyTokenType::OPERATION
				&& priorities.at(operations.top().value) >= priorities.at(token.value)) {
				mQueue.push(operations.top());
				operations.pop();
			}
			operations.emplace(token);
		}
		else if (token.token_type == MyTokenType::OPEN_BRACKET) {
			operations.emplace(token);
		}
		else if (token.token_type == MyTokenType::CLOSE_BRACKET) {
			while (!operations.empty() && operations.top().token_type == MyTokenType::OPERATION) {
				mQueue.push(operations.top());
				operations.pop();
			}
			operations.pop();	// Open bracket
		}
		else if (token.token_type == MyTokenType::UNARY_OPERATION) {
			mQueue.emplace(token);
		}
	}
	while (!operations.empty()) {
		mQueue.push(operations.top());
		operations.pop();
	}
}

double ReversePolishNotation::Evaluate() const {
	auto queue = mQueue;
	std::stack<double> stack;
	while (!queue.empty()) {
		auto& current = queue.front();
		if (current.token_type == MyTokenType::VARIABLE) {
			bool unary_changed = false;
			if (current.value[0] == '-') {
				unary_changed = true;
			}
			if (!std::isalpha(current.value[0])) {
				current.value = current.value.substr(1);
			}
			if (unary_changed) {
				stack.emplace(-1 * mVariables.at(current.value));
			}
			else {
				stack.emplace(mVariables.at(current.value));
			}
		} else if (current.token_type == MyTokenType::NUMBER) {
			stack.emplace(std::stod(current.value));
		} else if (current.token_type == MyTokenType::OPERATION) {
			double second = stack.top();
			stack.pop();
			double first = stack.top();
			stack.pop();
			if (current.value == "+") {
				stack.push(first + second);
			} else if (current.value == "-") {
				stack.push(first - second);
			} else if (current.value == "*") {
				stack.push(first * second);
			} else if (current.value == "/") {
				stack.push(first / second);
			} else if (current.value == "^") {
				stack.push(std::pow(first,  second));
			}
		}
		else if (current.token_type == MyTokenType::UNARY_OPERATION) {
			auto value = current.value;
			queue.pop();
			queue.front().value = value + queue.front().value;
			continue;
		}
		else {
			throw std::runtime_error("Error while evaluating");
		}
		queue.pop();
	}
	if (stack.size() != 1 || !queue.empty()) {
		throw std::runtime_error("Error while ending evaluating");
	}
	return stack.top();
}

const std::queue<Token>& ReversePolishNotation::getQueue() const {
	return mQueue;
}