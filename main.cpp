#include <iostream>
#include <memory>
#include <gtest/gtest.h>
using namespace std;

// Base class
class Vehicle {
public:
    virtual string drive() const = 0;
    virtual ~Vehicle() = default;
};

// Concrete classes
class Car : public Vehicle {
public:
    string drive() const override {
        return "Driving a Car";
    }
};

class Bike : public Vehicle {
public:
    string drive() const override {
        return "Riding a Bike";
    }
};

class Truck : public Vehicle {
public:
    string drive() const override {
        return "Driving a Truck";
    }
};

// Factory
class VehicleFactory {
public:
    static unique_ptr<Vehicle> createVehicle(const string& type) {
        if (type == "Car") return make_unique<Car>();
        else if (type == "Bike") return make_unique<Bike>();
        else if (type == "Truck") return make_unique<Truck>();
        else return nullptr;
    }
};

// GTest cases
TEST(VehicleTest, CarDrive) {
    auto car = VehicleFactory::createVehicle("Car");
    EXPECT_EQ(car->drive(), "Driving a Car");
}

TEST(VehicleTest, BikeDrive) {
    auto bike = VehicleFactory::createVehicle("Bike");
    EXPECT_EQ(bike->drive(), "Riding a Bike");
}

TEST(VehicleTest, TruckDrive) {
    auto truck = VehicleFactory::createVehicle("Truck");
    EXPECT_EQ(truck->drive(), "Driving a Truck");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
