#include "iostream"

class Shape {
public:
	virtual Shape* clone() const = 0; 
	virtual void info() const = 0; 
	virtual ~Shape() { }			
};



class Rectangle : public Shape {
private:
	double width;
	double height;

public:
	Rectangle(int w, int h) : width(w), height(h) {}

	Shape* clone() const override {
		return new Rectangle(*this);
	}

	void info() const override {
		std::cout << "Rectangle with width " << width << " and height " << height << std::endl;
	}
};


class Circle : public Shape {
private:
	double radius;

public:
	Circle(int r) : radius(r) {}

	Shape* clone() const override {
		return new Circle(*this);
	}

	void info() const override {
		std::cout << "Circle with radius " << radius << std::endl;
	}
};


int main() {

    Circle circlePrototype(3);
    Rectangle rectanglePrototype(10, 15);

    
    Shape* shape1 = circlePrototype.clone();
    Shape* shape2 = rectanglePrototype.clone();

    shape1->info(); 
    shape2->info(); 
     
    return 0;

}