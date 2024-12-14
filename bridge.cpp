#include <iostream>
#include <memory>

class Device {
public:
    virtual ~Device() = default;
    virtual bool isEnabled() = 0;

    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual int getVolume() = 0;
    virtual void setVolume(int) = 0;

    virtual int getChannel() = 0;
    virtual void setChannel(int) = 0;

protected:
    bool enabled;
    int volume;
    int channel;

};

class Radio : public Device {
public:
    Radio() {
        enabled = false; 
        volume = 25;
        channel = 40;
    }

    bool isEnabled() override {
        return enabled;
    }

    void enable() override { 
        enabled = true; 
        std::cout << "Radio enabled\n"; 
    }

    void disable() override { 
        enabled = false; 
        std::cout << "Radio disabled\n"; 
    }

    int getVolume() override { 
        return volume; 
    }
    void setVolume(int volume_) override { 
        volume = volume_; 
        std::cout << "Radio volume: " << volume << "\n"; 
    }
    int getChannel() override { 
        return channel; 
    }
    void setChannel(int channel_) override { 
        channel = channel_; 
        std::cout << "Radio channel: " << channel << "\n"; 
    }
};


class Remote {
public:
    Remote(std::shared_ptr<Device> device_) : device(device_) {}

    void power() {
        if (device->isEnabled()) {
            device->disable();
        } else {
            device->enable();
        }
    }

    void volumeDown() {
        device->setVolume(device->getVolume() - 1);
    }

    void volumeUp() {
        device->setVolume(device->getVolume() + 1);
    }

    void channelDown() {
        device->setChannel(device->getChannel() - 1);
    }

    void channelUp() {
        device->setChannel(device->getChannel() + 1);
    }

protected:
    std::shared_ptr<Device> device;
};

class AdvancedRemote : public Remote {
public:
    AdvancedRemote(std::shared_ptr<Device> device_) : Remote(device_) {}

    void mute() {
        device->setVolume(0);
        std::cout << "Device muted\n";
    }
};

int main() {
    std::shared_ptr<Device> radio = std::make_shared<Radio>();
    Remote remote(radio);
    AdvancedRemote advancedRemote(radio);

    std::cout << "Remote, radio:\n";
    remote.power();
    remote.volumeUp();
    remote.channelDown();

    std::cout << std::endl;

    std::cout << "Avandced remote, readio: \n";
    advancedRemote.power();
    advancedRemote.volumeDown();
    advancedRemote.mute();

    return 0;
}
