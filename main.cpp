#include<iostream>

#include "token/Token.h"

int main()
{
    Token token(
        TokenType::PLUS,
        "+",
        1
    );
    
    std::cout << token.toString() << std::endl;
}