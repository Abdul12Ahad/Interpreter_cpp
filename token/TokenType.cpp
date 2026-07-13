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

        case TokenType::VAR:
            return "VAR";

        case TokenType::IF:
            return "IF";

        case TokenType::PRINT:
            return "PRINT";

        case TokenType::LEFT_BRACE:
            return "LEFT_BRACE";

        case TokenType::RIGHT_BRACE:
            return "RIGHT_BRACE";

        case TokenType::STRING:
            return "STRING";

        case TokenType::GREATER:
            return "GREATER";

        case TokenType::GREATER_EQUAL:
            return "GREATER_EQUAL";

        case TokenType::LESS:
            return "LESS";

        case TokenType::LESS_EQUAL:
            return "LESS_EQUAL";

        case TokenType::BANG:
            return "BANG";

        case TokenType::BANG_EQUAL:
            return "BANG_EQUAL";

        case TokenType::EOF_TOKEN:
            return "EOF";
    }

    return "UNKNOWN";
}