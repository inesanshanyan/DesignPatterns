#include <iostream>
#include <memory>

class TrafficLightState {
public:
    virtual ~TrafficLightState() = default;
    virtual void changeLight() = 0; 

};

class TrafficLight {
public:
    TrafficLight(std::shared_ptr<TrafficLightState> initState) : state(initState) {}

    void setState(std::shared_ptr<TrafficLightState> newState) {
        state = newState;
    }

    void changeLight() {
        state->changeLight();
    }

private:
    std::shared_ptr<TrafficLightState> state;
};

class GreenLight : public TrafficLightState {
public:
    void changeLight() override {
        std::cout << "Green light\n";
    }
};

class YellowLight : public TrafficLightState {
public:
    void changeLight() override {
        std::cout << "Yellow light\n";
    }
};

class RedLight : public TrafficLightState {
public:
    void changeLight() override {
        std::cout << "Red light\n";
    }
};

int main() {
    auto greenState = std::make_shared<GreenLight>();
    TrafficLight trafficLight(greenState);

    trafficLight.changeLight();  
    trafficLight.setState(std::make_shared<YellowLight>());
    trafficLight.changeLight();  
    trafficLight.setState(std::make_shared<RedLight>());
    trafficLight.changeLight(); 

    return 0;
}
