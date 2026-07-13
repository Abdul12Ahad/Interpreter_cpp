#pragma once

#include<string>
#include <vector>
#include "../token/Token.h"
#include <unordered_map>

class Scanner
{
    private:
        std::string source;
        std::vector<Token> tokens;
        std::unordered_map<std::string, TokenType> keywords;

        int start = 0;
        int current = 0;
        int line = 1;

        bool isAtEnd();
        
        char advance();

        void addToken(TokenType type);

        void scanToken();

        bool match(char expected);

        bool isDigit(char c);

        char peek();

        char peekNext();

        void number();

        bool isAlpha(char c);

        bool isAlphaNumeric(char c);

        void identifier();

        void string();

    public:
        Scanner(std::string source);
        std::vector<Token> scanTokens();
};