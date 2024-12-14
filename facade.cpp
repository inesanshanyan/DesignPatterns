#include <iostream>
#include <string>

class TV {
public:
    void turnOn() {
        std::cout << "TV: on\n";
    }
    void turnOff() {
        std::cout << "TV: off\n";
    }
};

class VolumeControl {
public:
    void setVolume(int volume) {
        std::cout << "Setting volume: " << volume << "\n";
    }
};

class HDMI {
public:
    void setHDMI() {
        std::cout << "Setting HDMI\n";
    }
};

class MovieFinder {
public:
    void findMovie(const std::string& movie) {
        std::cout << "Finding movie: " << movie << "\n";
    }
};


class WatchMovieFacade {
public:
    WatchMovieFacade(TV& tv, VolumeControl& volume, HDMI& hdmi, MovieFinder& movieFinder)
        : tv(tv), volumeControl(volume), hdmi(hdmi), movieFinder(movieFinder) { }

    void watchMovie(const std::string& movie) {
        tv.turnOn();
        hdmi.setHDMI();
        volumeControl.setVolume(50); 
        movieFinder.findMovie(movie);
        std::cout << "Movie " << movie << " is ready to watch\n";
    }

    

private:
    TV& tv;
    VolumeControl& volumeControl;
    HDMI& hdmi;
    MovieFinder& movieFinder;
};

// Client
int main() {
    TV tv;
    VolumeControl volumeControl;
    HDMI hdmi;
    MovieFinder movieFinder;

    WatchMovieFacade movie(tv, volumeControl, hdmi, movieFinder);

    movie.watchMovie("Pearl Harbor");

    return 0;
}
