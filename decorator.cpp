#include <iostream>
#include <string>
#include <memory>

class Tree {
public: 
    virtual ~Tree() = default;
    virtual std::string getDescription() = 0;
    virtual int getCost() = 0;
};

class SimpleTree : public Tree {
public: 
    std::string getDescription() override {
        return "Simple tree ";
    }

    int getCost() override {
        return 50;
    }
};

class BaseDecorator : public Tree {
protected: 
    std::unique_ptr<Tree> tree;

public:
    BaseDecorator(std::unique_ptr<Tree> tree_) : tree(std::move(tree_)) { }
};

class ChristmasBallsDecorator : public BaseDecorator {
public:
    ChristmasBallsDecorator(std::unique_ptr<Tree> tree_) : BaseDecorator(std::move(tree_)) { }

    std::string getDescription() override {
        return tree->getDescription() + ", decorated with christmas balls";
    }

    int getCost() override {
        return tree->getCost() + 25;
    }

};

class StarDecorator : public BaseDecorator {
public:
    StarDecorator(std::unique_ptr<Tree> tree_) : BaseDecorator(std::move(tree_)) { }

    std::string getDescription() override {
        return tree->getDescription() + ", decorated with star";
    }

    int getCost() override {
        return tree->getCost() + 10;
    }

};

class ChristmasLightsDecorator : public BaseDecorator {
public:
    ChristmasLightsDecorator(std::unique_ptr<Tree> tree_) : BaseDecorator(std::move(tree_)) { }

    std::string getDescription() override {
        return tree->getDescription() + ", decorated with christmas lights";
    }

    int getCost() override {
        return tree->getCost() + 15;
    }

};

int main() {
    std::unique_ptr<Tree> tree = std::make_unique<ChristmasLightsDecorator>(
                                    std::make_unique<StarDecorator>(
                                    std::make_unique<ChristmasBallsDecorator>(
                                    std::make_unique<SimpleTree>())));

    std::cout << "Description: " << tree->getDescription() << std::endl;
    std::cout << "Cost: $" << tree->getCost() << std::endl;

    return 0;
}
