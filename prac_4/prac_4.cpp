#include <iostream>
#include<fstream>
#include<string>

class Device {
protected:
	std::string m_devicename;
public:
	Device(const std::string& devicename): m_devicename(devicename){}
	void poll() {
		std::cout << m_devicename << std::endl;
	}
};


class ElectricEnergyMeters :public Device {
public:
	ElectricEnergyMeters(const std::string& devicename): Device(devicename){}
};

class DiscreteSignals:public Device {
public:
	DiscreteSignals(const std::string& devicename) : Device(devicename) {}
};

class HeatingManagement :public Device {
public:
	HeatingManagement(const std::string& devicename) : Device(devicename) {}
};


class Mercury :public ElectricEnergyMeters {
public:
	Mercury(const std::string& devicename) : ElectricEnergyMeters(devicename) {}
};

class Neva :public ElectricEnergyMeters {
public:
	Neva(const std::string& devicename) : ElectricEnergyMeters(devicename) {}
};

class Energomera :public ElectricEnergyMeters {
public:
	Energomera(const std::string& devicename) : ElectricEnergyMeters(devicename) {}
};


class Reallab :public DiscreteSignals {
public:
	Reallab(const std::string& devicename) : DiscreteSignals(devicename) {}
};

class Priborelectro :public DiscreteSignals {
public:
	Priborelectro(const std::string& devicename) : DiscreteSignals(devicename) {}
};

class Energyservice :public DiscreteSignals {
public:
	Energyservice(const std::string& devicename) : DiscreteSignals(devicename) {}
};

class Ouman :public HeatingManagement {
public:
	Ouman(const std::string& devicename) : HeatingManagement(devicename) {}
};
class Oven :public HeatingManagement {
public:
	Oven(const std::string& devicename) : HeatingManagement(devicename) {}
};

Device* deviceName(const std::string& Name) {
	Device* normName;
	switch (static_cast<int>((unsigned char)Name[0])) {
	case(77):
		normName = new Mercury(Name);
		break;
	case(78):
		normName = new Neva(Name);
		break;
	case(69):
		if (static_cast<int>((unsigned char)Name[5]) == 111) {
			normName = new Energomera(Name);
			break;
		}
		else {
			normName = new Energyservice(Name);
			break;
		}
	case(82):
		normName = new Reallab(Name);
		break;
	case(80):
		normName = new Priborelectro(Name);
		break;
	case(79):
		if (static_cast<int>((unsigned char)Name[1]) == 117) {
			normName = new Ouman(Name);
			break;
		}
		else {
			normName = new Oven(Name);
			break;
		}
	default:
		normName = nullptr;
	}
	return normName;
}

int main() {
	setlocale(LC_ALL, "RUS");
	std::string line;
	std::ifstream in("device.txt");
	while (std::getline(in, line)) {
		Device* normName = deviceName(line);
		if (normName != nullptr) {
			normName->poll();
		}
		else {
			std::cout << "Error" << std::endl;
		}
	}
	in.close();
}