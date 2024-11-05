#include <iostream>
#include <string>

using namespace std;

enum class Intensity { LIGHT, NORMAL, STRONG };
enum class SyrupType { MACADAMIA, VANILLA, COCONUT, CARAMEL, CHOCOLATE, POPCORN };
//Coffee
class Coffee {
protected:
    Intensity intensity;
    string name;

public:
    Coffee(const string& coffeeName, Intensity intensityLevel)
        : name(coffeeName), intensity(intensityLevel) {}

    virtual ~Coffee() = default;

    string getName() const { return name; }
    Intensity getIntensity() const { return intensity; }
};
//Americano
class Americano : public Coffee {
private:
    int mlOfWater;

public:
    Americano(Intensity intensityLevel, int waterAmount)
        : Coffee("Americano", intensityLevel), mlOfWater(waterAmount) {}

    int getMlOfWater() const { return mlOfWater; }
};
//Cappucino
class Cappuccino : public Coffee {
private:
    int mlOfMilk;

public:
    Cappuccino(Intensity intensityLevel, int milkAmount)
        : Coffee("Cappuccino", intensityLevel), mlOfMilk(milkAmount) {}

    int getMlOfMilk() const { return mlOfMilk; }
};
//PumpkinSpiceLatte
class PumpkinSpiceLatte : public Cappuccino {
private:
    int mgOfPumpkinSpice;

public:
    PumpkinSpiceLatte(Intensity intensityLevel, int milkAmount, int pumpkinSpiceAmount)
        : Cappuccino(intensityLevel, milkAmount), mgOfPumpkinSpice(pumpkinSpiceAmount) {
        name = "PumpkinSpiceLatte";
    }

    int getMgOfPumpkinSpice() const { return mgOfPumpkinSpice; }
};
//SyrupCappucino
class SyrupCappuccino : public Cappuccino {
private:
    SyrupType syrup;

public:
    SyrupCappuccino(Intensity intensityLevel, int milkAmount, SyrupType syrupType)
        : Cappuccino(intensityLevel, milkAmount), syrup(syrupType) {
        name = "SyrupCappuccino";
    }

    SyrupType getSyrup() const { return syrup; }
};
//main
int main() {
    Americano americano(Intensity::STRONG, 200);
    cout << "Coffee: " << americano.getName() << ", Water: " << americano.getMlOfWater() << "ml\n";

    Cappuccino cappuccino(Intensity::NORMAL, 150);
    cout << "Coffee: " << cappuccino.getName() << ", Milk: " << cappuccino.getMlOfMilk() << "ml\n";

    PumpkinSpiceLatte pumpkinLatte(Intensity::LIGHT, 150, 10);
    cout << "Coffee: " << pumpkinLatte.getName() << ", Milk: " << pumpkinLatte.getMlOfMilk() 
         << "ml, Pumpkin Spice: " << pumpkinLatte.getMgOfPumpkinSpice() << "mg\n";

    SyrupCappuccino syrupCappuccino(Intensity::NORMAL, 100, SyrupType::VANILLA);
    cout << "Coffee: " << syrupCappuccino.getName() << ", Milk: " << syrupCappuccino.getMlOfMilk() 
         << "ml, Syrup: " << static_cast<int>(syrupCappuccino.getSyrup()) << "\n";

    return 0;
}
