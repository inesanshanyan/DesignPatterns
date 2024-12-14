#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Subscriber {
public:
    virtual ~Subscriber() = default;
    virtual void update(int) = 0; 
};

class Friend : public Subscriber {
public:
    Friend(const std::string& name_) : name(name_) { }

    void update(int age) override {
        std::cout << name << " Birthday notification: " << age << "\n";
    }

private: 
    std::string name;    
};

class Facebook {
public:
    Facebook(int age_) : age(age_) { }

    void subscribe(std::shared_ptr<Subscriber> subscriber) {
        subscribers.push_back(subscriber);
    }

    void unsubscribe(std::shared_ptr<Subscriber> subscriber) {
        auto it = std::find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notifySubscribers() {
        for (const auto& subscriber : subscribers) {
            subscriber->update(age);
        }
    }

    void birthday() {
        age++;
        std::cout << "User's birthday:  " << age << "\n";
        notifySubscribers();
    }

    int getAge() const { return age; }


private:
    std::vector<std::shared_ptr<Subscriber>> subscribers; 
    int age; 
};


int main() {
    Facebook facebook(25); 

    auto Jean = std::make_shared<Friend>("Jean");
    auto Alice = std::make_shared<Friend>("Alice");
    auto Daniel = std::make_shared<Friend>("Daniel");

    facebook.subscribe(Jean);
    facebook.subscribe(Alice);
    facebook.subscribe(Daniel);

    facebook.birthday(); 

    std::cout << std::endl;
    std::cout << "Alice unsubscribed.\n";
    facebook.unsubscribe(Alice);

    facebook.birthday();

    return 0;
}
