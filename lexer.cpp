#include "lexer.h"
#include <cstddef>

// Lexer constructor.
Lexer::Lexer(){};

// Analyse the source code, and return lexemes in a vector.
std::vector<Lexer::Token> Lexer::Analysis(const std::string& source) 
{ 
  std::size_t length = source.length();

  // Running a loop on the source code to check each character.
  for (;position < length;)
  {
    char c = source[position];
    
    // Check if the character is whitespace.
    if (std::isspace(static_cast<unsigned char>(c)))
    {
      // If whitespace, move to the next character.
      position++;
      continue;
    }
    else if (std::isdigit(static_cast<unsigned char>(c)))
    {
      // Is a digit, read whether int or float, and add to the 
      ReadNumber(source);
    }
    else if (std::isalpha(static_cast<unsigned char>(c)))
    {
      // Is an alphabet.
    }
    else
    {
      // Is an operator.
    }
  }

  return tokens; 
}

// Read a number if it starts with an int.
void Lexer::ReadNumber(const std::string& source)
{
  // Read the number and store the float/int literal into a token struct,
  // and push to the vector.
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

// Read a word if starts with a char.
void Lexer::ReadWord(const std::string& source)
{
  // Read the word and store the identifer/literal into a token struct, and push to
  // the vector.
  while (std::isalpha(static_cast<unsigned char>(source[position])))
  {
    
  }
}