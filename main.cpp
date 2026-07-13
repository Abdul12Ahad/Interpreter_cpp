#include <iostream>

#include "scanner/Scanner.h"

int main()
{
    std::string source = R"(

    class Person {

        var age = 20;
        var pi = 3.1415;

        print "Hello World";

        if(age >= 18)
        {
            print "Adult";
        }

        // This is a comment

        while(age > 0)
        {
            age = age - 1;
        }

    }

    )";

    Scanner scanner(source);

    std::vector<Token> tokens = scanner.scanTokens();

    for(const auto &token : tokens)
    {
        std::cout << token.toString() << std::endl;
    }

    return 0;
}