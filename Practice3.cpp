#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
private:
    string plate;
    string brand;
    double pricePerDay;

public:
    Vehicle() {
        plate = "";
        brand = "";
        pricePerDay = 0;
    }

    Vehicle(string p, string b, double price) {
        plate = p;
        brand = b;
        pricePerDay = price;
    }

    string getPlate() { return plate; }
    string getBrand() { return brand; }
    double getPricePerDay() { return pricePerDay; }

    void setPlate(string p) { plate = p; }
    void setBrand(string b) { brand = b; }
    void setPricePerDay(double price) { pricePerDay = price; }

    virtual double calculateRentalFee(int days) = 0;

    virtual void displayInfo() {
        cout << "Plate: " << plate << endl;
        cout << "Brand: " << brand << endl;
        cout << "Price per day: " << pricePerDay << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int seats;

public:
    Car() : Vehicle() {
        seats = 0;
    }

    Car(string p, string b, double price, int s) : Vehicle(p, b, price) {
        seats = s;
    }

    int getSeats() { return seats; }
    void setSeats(int s) { seats = s; }

    double calculateRentalFee(int days) override {
        double fee = days * getPricePerDay();
        if (days >= 7)
            fee = fee * 0.9;   
        return fee;
    }

    void displayInfo() override {
        cout << "--- Car ---" << endl;
        Vehicle::displayInfo();
        cout << "Seats: " << seats << endl;
    }
};

class Motorbike : public Vehicle {
private:
    int engineCC;

public:
    Motorbike() : Vehicle() {
        engineCC = 0;
    }

    Motorbike(string p, string b, double price, int cc) : Vehicle(p, b, price) {
        engineCC = cc;
    }

    int getEngineCC() { return engineCC; }
    void setEngineCC(int cc) { engineCC = cc; }

    double calculateRentalFee(int days) override {
        double fee = days * getPricePerDay();
        if (days >= 5)
            fee = fee * 0.95;   
        return fee;
    }

    void displayInfo() override {
        cout << "--- Motorbike ---" << endl;
        Vehicle::displayInfo();
        cout << "Engine: " << engineCC << " cc" << endl;
    }
};

class Truck : public Vehicle {
private:
    double load;            
    double transportFee;    

public:
    Truck() : Vehicle() {
        load = 0;
        transportFee = 0;
    }

    Truck(string p, string b, double price, double l, double fee) : Vehicle(p, b, price) {
        load = l;
        transportFee = fee;
    }

    double getLoad() { return load; }
    double getTransportFee() { return transportFee; }

    void setLoad(double l) { load = l; }
    void setTransportFee(double fee) { transportFee = fee; }

    double calculateRentalFee(int days) override {
        return days * getPricePerDay() + transportFee;
    }

    void displayInfo() override {
        cout << "--- Truck ---" << endl;
        Vehicle::displayInfo();
        cout << "Load: " << load << " tons" << endl;
        cout << "Transport fee: " << transportFee << endl;
    }
};

int main() {
    vector<Vehicle*> list;
    list.push_back(new Car("51A-12345", "Toyota", 800000, 4));
    list.push_back(new Car("51B-67890", "Honda", 900000, 7));
    list.push_back(new Motorbike("59X1-1111", "Yamaha", 150000, 125));
    list.push_back(new Motorbike("59X2-2222", "Honda", 200000, 150));
    list.push_back(new Truck("51C-33333", "Hyundai", 1500000, 5, 500000));

    int days;
    cout << "Nhap so ngay thue: ";
    cin >> days;
    cout << endl;

    for (int i = 0; i < list.size(); i++) {
        list[i]->displayInfo();
        cout << "Rental fee (" << days << " days): "
             << list[i]->calculateRentalFee(days) << endl;
        cout << endl;
    }

    double total = 0;
    for (int i = 0; i < list.size(); i++)
        total += list[i]->calculateRentalFee(days);
    cout << "Tong doanh thu thue xe: " << total << endl;

    Vehicle* maxVehicle = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (list[i]->calculateRentalFee(days) > maxVehicle->calculateRentalFee(days))
            maxVehicle = list[i];
    }
    cout << "\nPhuong tien co phi thue cao nhat:" << endl;
    maxVehicle->displayInfo();
    cout << "Rental fee: " << maxVehicle->calculateRentalFee(days) << endl;

    for (int i = 0; i < list.size(); i++)
        delete list[i];

    return 0;
}