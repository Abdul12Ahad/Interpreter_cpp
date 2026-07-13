#pragma once

#include<string>
#include "TokenType.h"

class Token
{
    public:
        TokenType type;
        std::string lexeme;
        int line;

        Token(TokenType type,
            std::string lexeme,
            int line
        )
        {
            this->type = type;
            this->lexeme = lexeme;
            this->line = line;
        }
        std::string toString() const
        {
             return tokenTypeToString(type)
             + " "
             + lexeme
             + " Line: "
             + std::to_string(line);
        }
};