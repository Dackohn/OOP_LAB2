#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
#include <string>

namespace Coffee {

enum class Intensity { LIGHT, NORMAL, STRONG };
enum class SyrupType { MACADAMIA, VANILLA, COCONUT, CARAMEL, CHOCOLATE, POPCORN };

class Coffee {
protected:
    Intensity intensity;
    const std::string name;

public:
    Coffee(const std::string& coffeeName, Intensity intensityLevel)
        : name(coffeeName), intensity(intensityLevel) {}

    virtual ~Coffee() = default;

    virtual Coffee& make() const {
        std::cout << "Making " << name << std::endl;
        std::cout << "Intensity set to ";
        switch (intensity) {
            case Intensity::LIGHT: std::cout << "LIGHT"; break;
            case Intensity::NORMAL: std::cout << "MEDIUM"; break;
            case Intensity::STRONG: std::cout << "STRONG"; break;
        }
        std::cout << std::endl;
        return const_cast<Coffee&>(*this);
    }

    virtual void printDetails() const {
        std::cout << "Coffee: " << name << std::endl;
        std::cout << "Coffee intensity: ";
        switch (intensity) {
            case Intensity::LIGHT: std::cout << "LIGHT"; break;
            case Intensity::NORMAL: std::cout << "NORMAL"; break;
            case Intensity::STRONG: std::cout << "STRONG"; break;
        }
        std::cout << std::endl;
    }
};

class Americano : public Coffee {
private:
    int mlOfWater;

public:
    Americano(Intensity intensityLevel, int waterAmount)
        : Coffee("Americano", intensityLevel), mlOfWater(waterAmount) {}

    Americano& make() const override {
        Coffee::make();
        std::cout << "Adding " << mlOfWater << " mls of water" << std::endl;
        return const_cast<Americano&>(*this);
    }

    void printDetails() const override {
        Coffee::printDetails();
        std::cout << "Americano water: " << mlOfWater << " ml" << std::endl;
    }
};

class Cappuccino : public Coffee {
private:
    int mlOfMilk;

public:
    Cappuccino(Intensity intensityLevel, int milkAmount)
        : Coffee("Cappuccino", intensityLevel), mlOfMilk(milkAmount) {}

    Cappuccino& make() const override {
        Coffee::make();
        std::cout << "Adding " << mlOfMilk << " mls of milk" << std::endl;
        return const_cast<Cappuccino&>(*this);
    }

    void printDetails() const override {
        Coffee::printDetails();
        std::cout << "Cappuccino milk: " << mlOfMilk << " ml" << std::endl;
    }
};

class PumpkinSpiceLatte : public Cappuccino {
private:
    int mgOfPumpkinSpice;

public:
    PumpkinSpiceLatte(Intensity intensityLevel, int milkAmount, int pumpkinSpiceAmount)
        : Cappuccino(intensityLevel, milkAmount), mgOfPumpkinSpice(pumpkinSpiceAmount) {}

    PumpkinSpiceLatte& make() const override {
        Cappuccino::make();
        std::cout << "Adding " << mgOfPumpkinSpice << " mls of pumpkin spice" << std::endl;
        return const_cast<PumpkinSpiceLatte&>(*this);
    }

    void printDetails() const override {
        Coffee::printDetails();
        std::cout << "Pumpkin Spice amount: " << mgOfPumpkinSpice << " mg" << std::endl;
    }
};

class SyrupCappuccino : public Cappuccino {
private:
    SyrupType syrup;

public:
    SyrupCappuccino(Intensity intensityLevel, int milkAmount, SyrupType syrupType)
        : Cappuccino(intensityLevel, milkAmount), syrup(syrupType) {}

    SyrupCappuccino& make() const override {
        Cappuccino::make();
        std::cout << "Adding syrup type: ";
        switch (syrup) {
            case SyrupType::MACADAMIA: std::cout << "Macadamia"; break;
            case SyrupType::VANILLA: std::cout << "Vanilla"; break;
            case SyrupType::COCONUT: std::cout << "Coconut"; break;
            case SyrupType::CARAMEL: std::cout << "Caramel"; break;
            case SyrupType::CHOCOLATE: std::cout << "Chocolate"; break;
            case SyrupType::POPCORN: std::cout << "Popcorn"; break;
        }
        std::cout << std::endl;
        return const_cast<SyrupCappuccino&>(*this);
    }

    void printDetails() const override {
        Coffee::printDetails();
        std::cout << "Syrup type: ";
        switch (syrup) {
            case SyrupType::MACADAMIA: std::cout << "Macadamia"; break;
            case SyrupType::VANILLA: std::cout << "Vanilla"; break;
            case SyrupType::COCONUT: std::cout << "Coconut"; break;
            case SyrupType::CARAMEL: std::cout << "Caramel"; break;
            case SyrupType::CHOCOLATE: std::cout << "Chocolate"; break;
            case SyrupType::POPCORN: std::cout << "Popcorn"; break;
        }
        std::cout << std::endl;
    }
};

} 

#endif
