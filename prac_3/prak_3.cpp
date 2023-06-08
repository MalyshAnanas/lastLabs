#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

class KinematicSolver {
private:
	double m_L1;
	double m_L2;
	double m_L12 = 0;
	double m_x = 0;
	double m_y = 0;
	double m_Ax = 0;
	double m_Ay = 0;
	double m_alpha = 0 ;
	double m_beta = 0;
public:
	KinematicSolver(double L1, double L2) : m_L1(L1), m_L2 (L2){
	}
	void Solve(double x, double y) {
		m_x = x;
		m_y = y;
		double pi = 3.1415926535;
		m_L12 = std::pow(std::pow(m_x, 2) + std::pow(m_y, 2),0.5);
		if (m_L12 > (m_L1 + m_L2)) { std::cout << "Mnogovato budet" << std::endl; }
		else {
			double a = (std::pow(m_L12, 2) + std::pow(m_L1, 2) - std::pow(m_L2, 2)) / (2 * m_L12 * m_L1);
			double b = (std::pow(m_L2, 2) + std::pow(m_L1, 2) - std::pow(m_L12, 2)) / (2 * m_L2 * m_L1);
			m_alpha = ((acos(a) + atan(y / x)) * 180) / pi;
			m_beta = (180) - (acos(b) * 180) / pi;
			if (m_beta < 0.0000001) { m_beta = 0; }
			std::cout << m_alpha << std::endl;
			std::cout << m_beta << std::endl;
		}
	}
	double alpha() {
		return m_alpha;
	}
	double beta() {
		return m_beta;
	}

};
int main(){
	double L1;
	double L2;
	std::cout << "Write length" << std::endl;
	std::cin >> L1;
	std::cin >> L2;
	double X1=1;
	double Y1=1;
	double pi = 3.1415926535;

	KinematicSolver KinematicSolver(L1, L2);
	std::cout << "Write X and Y" << std::endl;
	std::cin >> X1;
	std::cin >> Y1;
	KinematicSolver.Solve(X1, Y1);
	double alpha = (KinematicSolver.alpha()*pi)/180;
	double beta = pi - (KinematicSolver.beta() * pi) / 180;
	std::cout << alpha << std::endl;
	double y = L1 * sin(alpha);
	double x;
	if (sin(alpha) >= 0) {
		x = L1 * cos(alpha);
		y = L1 * sin(alpha);
	}
	else {
		double B = sqrt(pow(x, 2) + pow(y, 2));
		alpha = acos(x / B) + acos((pow(L1, 2) - pow(L2, 2) + (B * B)) / (2 * B * L1));
		beta = -beta;
		x = L1 * cos(alpha);
		y = L1 * sin(alpha);
	}
	//double x = L1 * cos(alpha);
	double newalpha = (KinematicSolver.alpha());
	double newbeta = (KinematicSolver.beta());
	std::cout << "x:" << x << std::endl;
	std::cout << "y:" << y << std::endl;
	//if (x < 0.0000000000000000001) { x = 0; }

	sf::RenderWindow window(sf::VideoMode(1500, 1000), "");
	sf::RectangleShape rectangle1(sf::Vector2f(L1, 10));
	std::cout << alpha << std::endl;
	std::cout << beta << std::endl;
	rectangle1.setRotation(-newalpha);
	rectangle1.setPosition(750, 500);
	rectangle1.setFillColor(sf::Color::White);
	sf::RectangleShape rectangle2(sf::Vector2f(L2, 10));
	rectangle2.setRotation(newbeta-newalpha);
	std::cout << "x:" << x << std::endl;
	std::cout << "y:" << y << std::endl;
	rectangle2.setPosition(x + 750, -y + 500);
	rectangle2.setFillColor(sf::Color::Blue);
	sf::CircleShape O(10);
	O.setPosition(750,500);
	O.setFillColor(sf::Color::Red);

	sf::CircleShape P(10);
	P.setPosition(750 + x, 500 - y);
	P.setFillColor(sf::Color::Yellow);

	sf::CircleShape M(10);
	M.setPosition(750 + X1, 500 - Y1);
	M.setFillColor(sf::Color::Green);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) { window.close(); }
		}
		window.clear();
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(O);
		window.draw(P);	
		window.draw(M);
		window.display();
	}
}
