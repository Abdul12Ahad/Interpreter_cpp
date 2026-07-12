#include "TokenType.h"

std::string tokenTypeToString(TokenType type)
{
    switch(type)
    {
        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";

        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";

        case TokenType::PLUS:
            return "PLUS";

        case TokenType::MINUS:
            return "MINUS";

        case TokenType::STAR:
            return "STAR";

        case TokenType::SLASH:
            return "SLASH";

        case TokenType::IDENTIFIER:
            return "IDENTIFIER";

        case TokenType::NUMBER:
            return "NUMBER";

        case TokenType::EOF_TOKEN:
            return "EOF";
    }

    return "UNKNOWN";
}