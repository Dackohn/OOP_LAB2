#include <iostream>
#include <string>

using namespace std;

enum class Intensity { LIGHT, NORMAL, STRONG };
enum class SyrupType { MACADAMIA, VANILLA, COCONUT, CARAMEL, CHOCOLATE, POPCORN };

class Coffee {
protected:
    Intensity intensity;
    const string name;

public:
    Coffee(const string& coffeeName, Intensity intensityLevel)
        : name(coffeeName), intensity(intensityLevel) {}

    virtual ~Coffee() = default;

    string getName() const { return name; }
    Intensity getIntensity() const { return intensity; }
    void setIntensity(Intensity newIntensity) { intensity = newIntensity; }

    virtual void printDetails() const {
        cout << "Coffee: " << name << endl;
        cout << "Coffee intensity: ";
        switch (intensity) {
            case Intensity::LIGHT: cout << "LIGHT"; break;
            case Intensity::NORMAL: cout << "NORMAL"; break;
            case Intensity::STRONG: cout << "STRONG"; break;
        }
        cout << endl;
    }
};

class Americano : public Coffee {
private:
    int mlOfWater;

public:
    Americano(Intensity intensityLevel, int waterAmount)
        : Coffee("Americano", intensityLevel), mlOfWater(waterAmount) {}

    int getMlOfWater() const { return mlOfWater; }
    void setMlOfWater(int waterAmount) { mlOfWater = waterAmount; }

    void printDetails() const override {
        Coffee::printDetails();
        cout << "Americano water: " << mlOfWater << " ml" << endl;
        cout << "\n" << endl;
    }
};

class Cappuccino : public Coffee {
private:
    int mlOfMilk;

public:
    Cappuccino(Intensity intensityLevel, int milkAmount)
        : Coffee("Cappuccino", intensityLevel), mlOfMilk(milkAmount) {}

    int getMlOfMilk() const { return mlOfMilk; }
    void setMlOfMilk(int milkAmount) { mlOfMilk = milkAmount; }

    void printDetails() const override {
        Coffee::printDetails();
        cout << "Cappuccino milk: " << mlOfMilk << " ml" << endl;
        cout << "\n" << endl;
    }
};

class PumpkinSpiceLatte : public Cappuccino {
private:
    int mgOfPumpkinSpice;

public:
    PumpkinSpiceLatte(Intensity intensityLevel, int milkAmount, int pumpkinSpiceAmount)
        : Cappuccino(intensityLevel, milkAmount), mgOfPumpkinSpice(pumpkinSpiceAmount) {}

    int getMgOfPumpkinSpice() const { return mgOfPumpkinSpice; }
    void setMgOfPumpkinSpice(int pumpkinSpiceAmount) { mgOfPumpkinSpice = pumpkinSpiceAmount; }

    void printDetails() const override {
        Coffee::printDetails();
        cout << "Pumpkin Spice amount: " << mgOfPumpkinSpice << " mg" << endl;
        cout << "\n" << endl;
    }
};

class SyrupCappuccino : public Cappuccino {
private:
    SyrupType syrup;

public:
    SyrupCappuccino(Intensity intensityLevel, int milkAmount, SyrupType syrupType)
        : Cappuccino(intensityLevel, milkAmount), syrup(syrupType) {}

    SyrupType getSyrup() const { return syrup; }
    void setSyrup(SyrupType syrupType) { syrup = syrupType; }

    void printDetails() const override {
        Coffee::printDetails();
        cout << "Syrup type: ";
        switch (syrup) {
            case SyrupType::MACADAMIA: cout << "Macadamia"; break;
            case SyrupType::VANILLA: cout << "Vanilla"; break;
            case SyrupType::COCONUT: cout << "Coconut"; break;
            case SyrupType::CARAMEL: cout << "Caramel"; break;
            case SyrupType::CHOCOLATE: cout << "Chocolate"; break;
            case SyrupType::POPCORN: cout << "Popcorn"; break;
        }
        cout << endl;
        cout << "\n" << endl;
    }
};

int main() {
    Americano americano(Intensity::STRONG, 200);
    americano.printDetails();

    Cappuccino cappuccino(Intensity::NORMAL, 150);
    cappuccino.printDetails();

    PumpkinSpiceLatte pumpkinLatte(Intensity::LIGHT, 150, 10);
    pumpkinLatte.printDetails();

    SyrupCappuccino syrupCappuccino(Intensity::NORMAL, 100, SyrupType::VANILLA);
    syrupCappuccino.printDetails();

    return 0;
}
