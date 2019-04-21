#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <exception>

enum class MyTokenType : int {
	NUMBER = 0, OPERATION, VARIABLE, OPEN_BRACKET, CLOSE_BRACKET, UNARY_OPERATION
};

struct Token {
	std::string value;
	MyTokenType token_type;
	Token(std::string value, MyTokenType token_type)
		: value(std::move(value)), token_type(token_type) {
	}
};

using Tokens = std::vector<Token>;

Tokens ParseToTokens(const std::string& data, const std::unordered_map<std::string, double>& variables);
