#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Drinks {
private:
    double price;
    int quantity;
    int day, month, year;

public:
    Drinks() {
        price = 0;
        quantity = 0;
        day = 0;
        month = 0;
        year = 0;
    }

    Drinks(double p, int q, int d, int m, int y) {
        price = p;
        quantity = q;
        day = d;
        month = m;
        year = y;
    }

    double getPrice() { return price; }
    int getQuantity() { return quantity; }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    double calculateRevenue() {
        return price * quantity;
    }

    virtual void display() {
        cout << "Price: " << price << ", Quantity: " << quantity
             << ", Date: " << day << "/" << month << "/" << year << endl;
    }
};

class Coffee : public Drinks {
public:
    Coffee() : Drinks() {}
    Coffee(double p, int q, int d, int m, int y) : Drinks(p, q, d, m, y) {}

    void display() {
        cout << "Coffee - ";
        Drinks::display();
    }
};

class Tea : public Drinks {
public:
    Tea() : Drinks() {}
    Tea(double p, int q, int d, int m, int y) : Drinks(p, q, d, m, y) {}

    void display() {
        cout << "Tea - ";
        Drinks::display();
    }
};

class Smoothies : public Drinks {
public:
    Smoothies() : Drinks() {}
    Smoothies(double p, int q, int d, int m, int y) : Drinks(p, q, d, m, y) {}

    void display() {
        cout << "Smoothies - ";
        Drinks::display();
    }
};

class Juices : public Drinks {
public:
    Juices() : Drinks() {}
    Juices(double p, int q, int d, int m, int y) : Drinks(p, q, d, m, y) {}

    void display() {
        cout << "Juices - ";
        Drinks::display();
    }
};

class Foods {
private:
    double price;
    int quantity;
    int day, month, year;

public:
    Foods() {
        price = 0;
        quantity = 0;
        day = 0;
        month = 0;
        year = 0;
    }

    Foods(double p, int q, int d, int m, int y) {
        price = p;
        quantity = q;
        day = d;
        month = m;
        year = y;
    }

    double getPrice() { return price; }
    int getQuantity() { return quantity; }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    double calculateRevenue() {
        return price * quantity;
    }

    virtual void display() {
        cout << "Price: " << price << ", Quantity: " << quantity
             << ", Date: " << day << "/" << month << "/" << year << endl;
    }
};

class Cake : public Foods {
public:
    Cake() : Foods() {}
    Cake(double p, int q, int d, int m, int y) : Foods(p, q, d, m, y) {}

    void display() {
        cout << "Cake - ";
        Foods::display();
    }
};

class Breads : public Foods {
public:
    Breads() : Foods() {}
    Breads(double p, int q, int d, int m, int y) : Foods(p, q, d, m, y) {}

    void display() {
        cout << "Breads - ";
        Foods::display();
    }
};

int main() {
    Drinks* drinks[5];
    drinks[0] = new Coffee(25000, 10, 16, 10, 2026);
    drinks[1] = new Tea(20000, 5, 16, 10, 2026);
    drinks[2] = new Smoothies(35000, 4, 16, 10, 2026);
    drinks[3] = new Juices(30000, 3, 16, 10, 2026);
    drinks[4] = new Coffee(25000, 8, 17, 10, 2026);  

    // Danh sach do an
    Foods* foods[3];
    foods[0] = new Cake(40000, 6, 16, 10, 2026);
    foods[1] = new Breads(15000, 10, 16, 10, 2026);
    foods[2] = new Cake(40000, 2, 17, 10, 2026);     

    for (int i = 0; i < 5; i++)
        drinks[i]->display();
    for (int i = 0; i < 3; i++)
        foods[i]->display();

    // Nhap ngay can tinh doanh thu
    int d, m, y;
    cout << "Nhap ngay (d m y): ";
    cin >> d >> m >> y;

    double totalDrinks = 0;
    double totalFoods = 0;

    for (int i = 0; i < 5; i++) {
        if (drinks[i]->getDay() == d && drinks[i]->getMonth() == m && drinks[i]->getYear() == y)
            totalDrinks += drinks[i]->calculateRevenue();
    }

    for (int i = 0; i < 3; i++) {
        if (foods[i]->getDay() == d && foods[i]->getMonth() == m && foods[i]->getYear() == y)
            totalFoods += foods[i]->calculateRevenue();
    }

    cout << fixed << setprecision(0);
    cout << "Doanh thu ngay " << d << "/" << m << "/" << y << endl;
    cout << "- Drinks: " << totalDrinks << endl;
    cout << "- Foods: " << totalFoods << endl;

    for (int i = 0; i < 5; i++)
        delete drinks[i];
    for (int i = 0; i < 3; i++)
        delete foods[i];

    return 0;
}