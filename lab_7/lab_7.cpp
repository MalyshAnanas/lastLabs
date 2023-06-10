#include<iostream>
#include <string>

class Shape {
protected:
	int m_x;
	int m_y;
	std::string m_color;
public:
	Shape(const std::string& color, int x, int y): m_color(color), m_x(x), m_y(y) {
	}
	virtual int bublik() {
		return 0;
	}
};

class Circle :public Shape {
protected:
	int m_radius;
public:
	Circle(const std::string& color, int x, int y, int radius):Shape(color, x, y), m_radius(radius) {}
	int bublik() override {
		int S = acos(-1) * m_radius * m_radius;
		return S;
	}
};

class Triangle : public Shape {
protected:
	int m_side1;
	int m_side2;
	int m_a;
public:
	Triangle(const std::string& color, int x, int y, int side1, int side2, int a) : Shape(color, x, y), m_side1(side1), m_side2(side2), m_a(a) {}
		int bublik() override {
			int S = (sin(m_a) * m_side1 * m_side2) / 2;
			return S;
		}
};

class Rectangle : public Shape {
protected:
	int m_side1;
	int m_side2;
public:
	Rectangle(const std::string& color, int x, int y, int side1, int side2) : Shape(color, x, y), m_side1(side1), m_side2(side2){}
	int bublik() override {
		int S =  m_side1 * m_side2;
		return S;
	}
};

int main() {
	Rectangle rec("blue", 9, 10, 5, 7);
	std::cout << rec.bublik() << std::endl;
	Triangle tri("blue", 1, 2, 5, 8, 1.23);
	std::cout << tri.bublik() << std::endl;
	Circle cir("blue", 3, 4, 11);
	std::cout << cir.bublik() << std::endl;
}