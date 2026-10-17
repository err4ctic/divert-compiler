#include <cctype>
#include <cstddef>
#include "../include/lexer.h"


Lexer::Lexer(){};
// Analyse the source code, and return lexemes in a vector.
std::vector<Lexer::Token> Lexer::Analysis(const std::string& source) 
{ 
	std::size_t length = source.length();
	for (;position < length;)
	{
		char c = source[position];
		if (std::isspace(static_cast<unsigned char>(c)))
		{
			position++;
			continue;
		}
		else if (std::isdigit(static_cast<unsigned char>(c)))
		{
			ReadNumber(source);
		}
		else if (std::isalpha(static_cast<unsigned char>(c)))
		{
			ReadWord(source);
		}
		else
		{
			ReadOperator(source);
		}
	}
	return tokens; 
}

void Lexer::ReadNumber(const std::string& source)
{
	int start = position;
	while (
		position < source.length() &&
		std::isdigit(static_cast<unsigned char>(source[position])
	))
	{
		position++;
	}
	std::string literal = source.substr(start, position-start);
	tokens.push_back(Token{TokenType::LiteralInt, literal});
}

void Lexer::ReadWord(const std::string& source)
{
	// Read the word and store the identifer/literal into a token struct, and push to
	// the vector.
	while (std::isalpha(static_cast<unsigned char>(source[position])))
	{
		int start = position;
		
	}
}

void Lexer::ReadOperator(const std::string& source)
{
}