#include <iostream>
#include <string>
#include <map>
#include <memory>

class Sandwich{
public:
    Sandwich() {
        ingredients["bread"] = 0;
        ingredients["meat"] = 0;
        ingredients["sauce"] = 0;
        ingredients["greens"] = 0;
    }

    void addIngredient(const std::string &ingredient) {
        if (ingredients.find(ingredient) != ingredients.end()) {
            ++ingredients[ingredient]; 
        }
        else {
            std::cerr << "The ingredient does not exist\n";
        }
    }

    void showSandwich() const {
        std::cout << "Sandwich:\n";
        for (const auto &item : ingredients) {
            if (item.second > 0) {
                std::cout << item.first << ": " << item.second << std::endl;
            }
        }
    }
private:
    std::map<std::string, int> ingredients; 
};

class SandwichBuilder {
public:
    SandwichBuilder() {
        sandwich = std::make_shared<Sandwich>();
    }
    virtual ~SandwichBuilder() = default;

    virtual void addBread() = 0;
    virtual void addMeat() = 0;
    virtual void addSauce() = 0;
    virtual void addGreens() = 0;

    std::shared_ptr<Sandwich> getSandwich() { 
        return sandwich; 
    }

protected:
    std::shared_ptr<Sandwich> sandwich;

};


class ConcreteSandwitchBuilder : public SandwichBuilder {
public:
    void addBread() override { 
        sandwich->addIngredient("bread");
    }
    void addMeat() override { 
        sandwich->addIngredient("meat"); 
    }
    void addSauce() override { 
        sandwich->addIngredient("sauce"); 
    }
    void addGreens() override { 
        sandwich->addIngredient("greens"); 
    }
};


int main() {
    ConcreteSandwitchBuilder builder;
    builder.addBread();
    builder.addMeat();
    builder.addSauce();
    builder.addGreens();
    builder.addBread();


    std::shared_ptr<Sandwich> sandwich = builder.getSandwich();

    sandwich->showSandwich();

    return 0;
}
