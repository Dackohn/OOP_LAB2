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

    virtual Coffee& make() const {
        cout << "Making " << name << endl;
        cout << "Intensity set to ";
        switch (intensity) {
            case Intensity::LIGHT: cout << "LIGHT"; break;
            case Intensity::NORMAL: cout << "MEDIUM"; break;
            case Intensity::STRONG: cout << "STRONG"; break;
        }
        cout << endl;
        return const_cast<Coffee&>(*this);
    }

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

    Americano& make() const override {
        Coffee::make();
        cout << "Adding " << mlOfWater << " mls of water" << endl;
        return const_cast<Americano&>(*this);
    }

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

    Cappuccino& make() const override {
        Coffee::make();
        cout << "Adding " << mlOfMilk << " mls of milk" << endl;
        return const_cast<Cappuccino&>(*this);
    }

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

    PumpkinSpiceLatte& make() const override {
        Cappuccino::make();
        cout << "Adding " << mgOfPumpkinSpice << " mls of pumpkin spice" << endl;
        return const_cast<PumpkinSpiceLatte&>(*this);
    }

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

    SyrupCappuccino& make() const override {
        Cappuccino::make();
        cout << "Adding syrup type: ";
        switch (syrup) {
            case SyrupType::MACADAMIA: cout << "Macadamia"; break;
            case SyrupType::VANILLA: cout << "Vanilla"; break;
            case SyrupType::COCONUT: cout << "Coconut"; break;
            case SyrupType::CARAMEL: cout << "Caramel"; break;
            case SyrupType::CHOCOLATE: cout << "Chocolate"; break;
            case SyrupType::POPCORN: cout << "Popcorn"; break;
        }
        cout << endl;
        return const_cast<SyrupCappuccino&>(*this);
    }

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
    PumpkinSpiceLatte pumpkinLatte(Intensity::NORMAL, 100, 50);
    pumpkinLatte.make();

    return 0;
}
