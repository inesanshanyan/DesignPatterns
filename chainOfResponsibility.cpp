#include <iostream>
#include <memory>

class Handler {
public:
    virtual ~Handler() = default;

    void setNext(std::shared_ptr<Handler> next_){
        next = next_;
    }

    virtual void handleRequest(const std::string& request){
        if(next){
            next->handleRequest(request);
        }
        else {
            std::cout << "No handler availble for : " << request << std::endl;
        }
    }

protected:
    std::shared_ptr<Handler> next = nullptr;

};

class Tokenizer : public Handler {
public:
    virtual void handleRequest(const std::string& request) override {
        if(request == "tokenizer"){
            std::cout << "Handling tokenizer: " << request << std::endl;
        }
        else {
            Handler::handleRequest(request);
        }
    }
};

class Syntax : public Handler {
public:
    virtual void handleRequest(const std::string& request) override {
        if(request == "syntax"){
            std::cout << "Handling syntax: " << request << std::endl;
        }
        else {
            Handler::handleRequest(request);
        }
    }
};

class Semantic : public Handler {
public:
    virtual void handleRequest(const std::string& request) override {
        if(request == "semantic"){
            std::cout << "Handling semantic: " << request << std::endl;
        }
        else {
            Handler::handleRequest(request);
        }
    }
};


int main() {
    auto tokenizer = std::make_shared<Tokenizer>();
    auto syntax = std::make_shared<Syntax>();
    auto semantic = std::make_shared<Semantic>();

    tokenizer->setNext(syntax);
    syntax->setNext(semantic);

    tokenizer->handleRequest("tokenizer");
    tokenizer->handleRequest("syntax");
    tokenizer->handleRequest("semantic"); 
    tokenizer->handleRequest("unknown"); 

    return 0;
}
