#include "Tokenizer.h"

void SkipSpaces(std::stringstream& stream) {
	while (stream.peek() != EOF && std::isspace(stream.peek())) {
		stream.get();
	}
}

Tokens ParseToTokens(const std::string& data, const std::unordered_map<std::string, double>& variables) {
	Tokens tokens;
	std::stringstream buffer(data);
	bool may_unary = true;
	while (buffer.peek() != EOF) {
		SkipSpaces(buffer);
		if (buffer.peek() == EOF) {
			break;
		}
		std::stringstream current_token;
		MyTokenType token_type;
		if (std::isdigit(buffer.peek())) {
			token_type = MyTokenType::NUMBER;
			while (buffer.peek() != EOF && (std::isdigit(buffer.peek()) || buffer.peek() == ',' || buffer.peek() == '.')) {
				current_token << static_cast<char>(buffer.get());
			}
			may_unary = false;
		} else if (std::isalpha(buffer.peek())) {
			token_type = MyTokenType::VARIABLE;
			while (buffer.peek() != EOF && std::isalpha(buffer.peek())) {
				current_token << static_cast<char>(buffer.get());
			}
			may_unary = false;
			if (variables.find(current_token.str()) == variables.end()) {
				throw std::runtime_error("Error while tokenizing");
			}
		} else if (buffer.peek() == '(') {
			token_type = MyTokenType::OPEN_BRACKET;
			current_token << static_cast<char>(buffer.get());
			may_unary = true;
		} else if (buffer.peek() == ')') {
			token_type = MyTokenType::CLOSE_BRACKET;
			current_token << static_cast<char>(buffer.get());
			may_unary = false;
		} else if (!may_unary) {
			token_type = MyTokenType::OPERATION;
			current_token << static_cast<char>(buffer.get());
			may_unary = true;
		} else if (may_unary) {
			token_type = MyTokenType::UNARY_OPERATION;
			current_token << static_cast<char>(buffer.get());
			may_unary = false;
		}
		if (current_token.peek() != EOF) {
			tokens.emplace_back(current_token.str(), token_type);
		}
	}
	return tokens;
}
