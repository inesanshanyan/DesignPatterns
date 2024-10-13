#include <iostream>
#include <memory>
#include <string>

class Drawing {
public:
    virtual void draw() = 0;
    virtual ~Drawing() = default;

};

class OilColors : public Drawing {
public:
    void draw() override {
        std::cout << "Drawing with oil colors" << std::endl;
    }
};

class Watercolor : public Drawing {
public:
    void draw() override {
        std::cout << "Drawing with watercolor" << std::endl;
    }
};

class ColorPencils : public Drawing {
public:
    void draw() override {
        std::cout << "Drawing with color pencils" << std::endl;
    }
};

class DrawingFactory {
public:
    virtual Drawing* createDrawing() = 0;
    virtual ~DrawingFactory() = default; 
};

class OilColorFactory : public DrawingFactory {
public:
    Drawing* createDrawing() override {
        return new OilColors();
    }
};

class WatercolorFactory : public DrawingFactory {
public:
    Drawing* createDrawing() override {
        return new Watercolor();
    }
};

class ColorPencilsFactory : public DrawingFactory {
public:
    Drawing* createDrawing() override {
        return new ColorPencils();
    }
};

int main() {
    std::cout << "Enter a drawing type \nexamples: oilcolors watercolor colorpencils\n";
    std::string drawingType;
    std::cin >> drawingType;

    DrawingFactory* drawingFactory = nullptr;
    if (drawingType == "oilcolors") {
        drawingFactory = new OilColorFactory();
    } else if (drawingType == "watercolor") {
        drawingFactory = new WatercolorFactory();
    } else if (drawingType == "colorpencils"){
        drawingFactory = new ColorPencilsFactory();
    } else {
        std::cout << "Unknown drawing type\n";
        return 1;
    }

    Drawing* drawing = drawingFactory->createDrawing();
    drawing->draw();

    delete drawingFactory;
    delete drawing; 

    return 0;
}
