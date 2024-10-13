#include <iostream>

class Parser {
public:
    static Parser* getInstance() {
        if (!parser) {
            parser = new Parser();
        }
        return parser;
    }

    void parse(/*const std::vector<TokenType>& tokens*/) {
        std::cout << "tokens have been parsed\n";
    }

private:
    Parser() = default;
    static Parser* parser;

};

Parser* Parser::parser = nullptr;

int main() {
    Parser* parser1 = Parser::getInstance();
    parser1->parse();

    Parser* parser2 = Parser::getInstance();
    parser2->parse();

    if (parser1 == parser2) {
        std::cout << "parsers are equal" << std::endl;
    }

    return 0;
}

