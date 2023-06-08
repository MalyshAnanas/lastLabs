#include <iostream>

template<typename>
class vector {

};
template<>
class vector<bool> {
private:
	size_t lenght{ 0 };
	char* MasMas = new char[0];
public:
	vector<bool>() = default;
	~vector() { delete[] MasMas; }
	vector<bool>& operator =(const vector<bool>& PoP) {
		vector<bool> temp = PoP;
		std::swap(MasMas, temp.MasMas);
		lenght = temp.lenght;
		return *this;
	}
	bool operator [](unsigned int index) { // Oператор получения
		int bup = index / 8;
		int bip = index % 8;
		return static_cast<bool>((MasMas[bup] >> bip) & 0b00000001);
	}
	size_t size() { //Метод size
		return lenght;
	}
	void push_back(bool PoP) { //Метод добавления в конец вектора
		int bup = lenght / 8;
		int bip = lenght % 8;
		if (bip == 0) {
			char* temp = new char[bup + 1];
			for (int i = 0; i < bup; i++) {
				temp[i] = MasMas[i];
			}
			delete MasMas;
			MasMas = temp;
			bibitchange(lenght, PoP);
		}
		else { bibitchange(lenght, PoP); }
		lenght++;
	}
	void bibitchange(unsigned int chindex, bool iTi) { //Метод изменения значения по индексу
		int bup = chindex / 8;
		int bip = chindex % 8;
		int a = 1 << bip;
		if (iTi == 0) { MasMas[bup] = MasMas[bup] & ~(a);}
		if (iTi == 1) { MasMas[bup] = MasMas[bup] | (a);	}
	}
	void insert(unsigned int chindex, bool AtI) { //Метод insert
		int bip = lenght % 8;
		int bup = lenght / 8;
		if (bip == 0) {
			char* temp = new char[ bup+ 1];
			for (int i = 0; i < lenght; i++) {
				temp[i] = MasMas[i];
			}
			delete MasMas;
			MasMas = temp;
		}
		for (int i = lenght; i > chindex; i--) {
			bibitchange(i, operator[](i - 1));
		}
		bibitchange(chindex, AtI);
		lenght++;
	}
	void erase(unsigned int index1) { //Метод erase
		for (int i = index1; i < lenght-1; i++) {
			bibitchange(i, operator[](i + 1));
		}
		lenght--;
	}
	void erase(unsigned int index1, unsigned int index2) {
		int a = lenght - index2 + 1;
		for (int i = index1; i <= a; i++) {
			bibitchange(i, operator[](i+lenght-index2));
		}
		lenght -= index2-index1 + 1;
	}
};

int main(){
	vector<bool> Frog;
	Frog.push_back(1);
	Frog.push_back(0);
	Frog.push_back(0);
	Frog.push_back(0);
	for (int i = 0; i < Frog.size(); i++) {
		std::cout << Frog[i];
	}
	std::cout << std::endl;
	Frog.bibitchange(3, 1);
	for (int i = 0; i < Frog.size(); i++) {
		std::cout << Frog[i];
	}
	std::cout << std::endl;
	Frog.insert(1, 1);
	for (int i = 0; i < Frog.size(); i++) {
		std::cout << Frog[i];
	}
	std::cout << std::endl;
	Frog.erase(2, 3);
	for (int i = 0; i < Frog.size(); i++) {
		std::cout << Frog[i];
	}
	std::cout << std::endl;
}
