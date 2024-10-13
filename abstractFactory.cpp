#include <iostream>

class Monitor {
public:
    virtual void assemble() = 0; 
    virtual ~Monitor() = default;
};

class GPU {
public:
    virtual void assemble() = 0;
    virtual ~GPU() = default;
};

class MsiMonitor : public Monitor {
public:
    void assemble() override {
        std::cout << "MSI Monitor" << std::endl;
    }
};

class MsiGPU : public GPU {
public:
    void assemble() override {
        std::cout << "MSI GPU" << std::endl;
    }
};

class AsusMonitor : public Monitor {
public:
    void assemble() override {
        std::cout << "ASUS Monitor" << std::endl;
    }
};

class AsusGPU : public GPU {
public:
    void assemble() override {
        std::cout << "ASUS GPU" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual Monitor* createMonitor() = 0; 
    virtual GPU* createGPU() = 0;    
};

class MsiFactory : public AbstractFactory {
public:
    Monitor* createMonitor() override {
        return new MsiMonitor();
    }
    GPU* createGPU() override {
        return new MsiGPU();
    }
};

class AsusFactory : public AbstractFactory {
public:
    Monitor* createMonitor() override {
        return new AsusMonitor();
    }
    GPU* createGPU() override {
        return new AsusGPU();
    }
};

int main() {
    AbstractFactory* msiFactory = new MsiFactory();
    Monitor* msiMonitor = msiFactory->createMonitor();
    GPU* msiGPU = msiFactory->createGPU();

    msiMonitor->assemble();
    msiGPU->assemble();     

    delete msiMonitor;
    delete msiGPU;
    delete msiFactory;

    AbstractFactory* asusFactory = new AsusFactory();
    Monitor* asusMonitor = asusFactory->createMonitor();
    GPU* asusGPU = asusFactory->createGPU();

    asusMonitor->assemble(); 
    asusGPU->assemble();     

    delete asusMonitor;
    delete asusGPU;
    delete asusFactory;

    return 0;
}
