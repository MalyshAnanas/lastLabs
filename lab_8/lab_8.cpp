#include<iostream>

template<typename type>
class Stek {
private:
	type* m_data = nullptr;
	unsigned int m_size;
	unsigned int m_elements=0;
public:
	Stek(int size): m_size(size){
		m_data = new type[m_size];
	}
	int size() {
		return m_size;
	}
	bool empty() {
		if (m_elements == 0) { return 1; }
		return 0;
	}
	void push(type elem) {
		if (m_elements < m_size) { 
			m_data[m_elements] = elem; 
			m_elements++;
		}
		else{
			throw std::out_of_range("push");
		}
	}
	type pop() {
		if (m_elements != 0) {
			m_elements--;
			return m_data[m_elements-1];
		}
		else {
			throw std::out_of_range("pop");
		}
	}
	type top() {
		if (m_elements != 0) {
			return m_data[m_elements-1];
		}
		else {
			throw std::logic_error("top");
		}
	}
};

int main() {
	Stek<int> stete(5);
	stete.push(1);
	stete.push(2);
	stete.push(3);
	stete.push(4);
	stete.push(5);
	try {
		stete.push(6);
	}
	catch (const std::out_of_range& error) {
		std::cout << "out of range" << std::endl;
	}
}