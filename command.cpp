#include <iostream>
#include <memory>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class Document { //reciever
public:
    void save() {
        std::cout << "Document saved.\n";
    }
};

class SaveCommand : public Command {
public:
    SaveCommand(std::shared_ptr<Document> document_) : document(document_) {}

    void execute() override {
        document->save();
    }

private:
    std::shared_ptr<Document> document; 
};

class Invoker {
public:
    virtual ~Invoker() = default;
    virtual void press() = 0;
};

class Button : public Invoker {
public:
    Button(std::shared_ptr<Command> command_) : command(command_) {}

    void press() override {
        std::cout << "Button pressed.\n";
        command->execute();
    }

private:
    std::shared_ptr<Command> command;
};

class Shortcut : public Invoker {
public:
    Shortcut(std::shared_ptr<Command> command_) : command(command_) {}

    void press() override {
        std::cout << "Shortcut key pressed.\n";
        command->execute();
    }

private:
    std::shared_ptr<Command> command;
};

int main() {
    auto document = std::make_shared<Document>();

    auto saveCommand = std::make_shared<SaveCommand>(document);

    Button buttonInvoker(saveCommand);
    buttonInvoker.press(); 

    Shortcut shortcutInvoker(saveCommand);
    shortcutInvoker.press();  
    
    return 0;
}
