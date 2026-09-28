#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <cctype>

// Token types enumerator.
enum class TokenType {
  // Datatypes.
  DatatypeInt,
  DatatypeFloat,
  DatatypeString,
  DatatypeBool,

  // Keywords
  KeywordFor,
  KeywordIn,
  KeywordRange,
  KeywordTrue,
  KeywordFalse,
  KeywordPrint,

  // Identifier
  Identifier,

  // Literals
  LiteralInt,
  LiteralString,
  LiteralFloat,

  // Arithmetic operators.
  ArithmeticSum,
  ArithmeticDifference,
  ArithmeticProduct,
  ArithmeticDivision,
  ArithmeticRemainder,
  ArithmeticExponent,

  // Comparison operators.
  CompSmaller,
  CompGreater,
  CompEqual,
  CompGreaterEqual,
  CompSmallerEqual,
  CompNotEqual,

  // Assignment.
  Assignment,

  // Punctuation.
  PuncBracketOpen,
  PuncBracketClose,
  PuncCurlyOpen,
  PuncCurlyClose,
  PuncSemiColon,
  PuncComma,

  // End of file.
  EndOfFile,

  // Invalid token.
  InvalidToken
};

// Lexer class.
class Lexer {
public:
  struct Token
  {
    TokenType type;
    std::string literal;
  };

private:
  // Token struct.
  std::size_t position = 0;
  int line = 0;
  int column = 0;
  std::vector<Token> tokens;

  void ReadNumber(const std::string& source);

  void ReadWord(const std::string& source);

public:
  // Constructor.
  Lexer();

  // Analyse the source and return a vector of tokens.
  std::vector<Token> Analysis(const std::string& source);
};