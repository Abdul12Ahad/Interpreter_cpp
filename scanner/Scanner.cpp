#include "Scanner.h"
#include<iostream>

Scanner::Scanner(std::string source)
{
    this->source = source;

    keywords["and"]    = TokenType::AND;
    keywords["class"]  = TokenType::CLASS;
    keywords["else"]   = TokenType::ELSE;
    keywords["false"]  = TokenType::FALSE_;
    keywords["for"]    = TokenType::FOR;
    keywords["fun"]    = TokenType::FUN;
    keywords["if"]     = TokenType::IF;
    keywords["nil"]    = TokenType::NIL;
    keywords["or"]     = TokenType::OR;
    keywords["print"]  = TokenType::PRINT;
    keywords["return"] = TokenType::RETURN;
    keywords["super"]  = TokenType::SUPER;
    keywords["this"]   = TokenType::THIS;
    keywords["true"]   = TokenType::TRUE_;
    keywords["var"]    = TokenType::VAR;
    keywords["while"]  = TokenType::WHILE;
}

bool Scanner::isAtEnd()
{
    return current>=source.length();
}

char Scanner::advance()
{
    return source[current++];
}

void Scanner::addToken(TokenType type)
{
    std::string text = source.substr(start,current-start);

    tokens.push_back(
        Token(type,text,line)
    );
}

void Scanner::scanToken()
{
    char c = advance();

    switch(c)
    {
        case '(':
            addToken(TokenType::LEFT_PAREN);
            break;

        case ')':
            addToken(TokenType::RIGHT_PAREN);
            break;

        case '+':
            addToken(TokenType::PLUS);
            break;

        case '-':
            addToken(TokenType::MINUS);
            break;

        case '*':
            addToken(TokenType::STAR);
            break;

        case '/':
            if(match('/'))
            {
                while(peek() != '\n' && !isAtEnd())
                {
                    advance();
                }
            }
            else
            {
                addToken(TokenType::SLASH);
            }
            break;

        case ';':
            addToken(TokenType::SEMICOLON);
            break;

        case '"':
            string();
            break;

        case '=':
            addToken(
                match('=')
                    ? TokenType::EQUAL_EQUAL
                    : TokenType::EQUAL
            );
            break;

        case '!':
            addToken(
                match('=')
                    ? TokenType::BANG_EQUAL
                    : TokenType::BANG
            );
            break;

        case '>':
            addToken(
                match('=')
                    ? TokenType::GREATER_EQUAL
                    : TokenType::GREATER
            );
            break;

        case '<':
            addToken(
                match('=')
                    ? TokenType::LESS_EQUAL
                    : TokenType::LESS
            );
            break;

        case '{':
            addToken(TokenType::LEFT_BRACE);
            break;

        case '}':
            addToken(TokenType::RIGHT_BRACE);
            break;

        case ' ':
        case '\r':
        case '\t':
            break;

        case '\n':
            line++;
            break;

        default:
            if(isDigit(c))
            {
                number();
            }
            else if(isAlpha(c))
            {
                identifier();
            }
            else
            {
                std::cout
                << "[Line "
                << line
                << "] Unexpected character: "
                << c
                << std::endl;
            }
            break;
    }
}

std::vector<Token> Scanner::scanTokens()
{
    while(!isAtEnd())
    {
        start = current;

        scanToken();
    }

    tokens.push_back(
        Token(
            TokenType::EOF_TOKEN,
            "",
            line
        )
    );

    return tokens;
}

bool Scanner::match(char expected)
{
    if(isAtEnd())
        return false;

    if(source[current]!=expected)
        return false;

    current++;

    return true;
}

bool Scanner::isDigit(char c)
{
    return c >= '0' && c <= '9';
}

char Scanner::peek()
{
    if(isAtEnd())
        return '\0';

    return source[current];
}

void Scanner::number()
{
    while(isDigit(peek()))
    {
        advance();
    }

    if(peek()=='.' && isDigit(peekNext()))
    {
        advance();

        while(isDigit(peek()))
        {
            advance();
        }
    }

    addToken(TokenType::NUMBER);
}

bool Scanner::isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
            c == '_';
}

bool Scanner::isAlphaNumeric(char c)
{
    return isAlpha(c) || isDigit(c);
}

void Scanner::identifier()
{
    while(isAlphaNumeric(peek()))
    {
        advance();
    }

    std::string text =
        source.substr(start, current - start);

    auto it = keywords.find(text);

    if(it != keywords.end())
    {
        addToken(it->second);
    }
    else
    {
        addToken(TokenType::IDENTIFIER);
    }
}

void Scanner::string()
{
    while(peek() != '"' && !isAtEnd())
    {
        if(peek() == '\n')
        {
            line++;
        }

        advance();
    }

    if(isAtEnd())
    {
        std::cout << "Unterminated string." << std::endl;
        return;
    }

    advance();

    addToken(TokenType::STRING);
}

char Scanner::peekNext()
{
    if(current + 1 >= source.length())
        return '\0';

    return source[current + 1];
}