#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string cccd;
    string phone;
    string address;

public:
    Employee() {
        cccd = "";
        phone = "";
        address = "";
    }

    Employee(string c, string p, string a) {
        cccd = c;
        phone = p;
        address = a;
    }

    string getCccd() { return cccd; }
    string getPhone() { return phone; }
    string getAddress() { return address; }

    void setCccd(string c) { cccd = c; }
    void setPhone(string p) { phone = p; }
    void setAddress(string a) { address = a; }

    virtual double calculateSalary(int month, int year) = 0;

    // Lương cả năm = cộng lương 12 tháng (tự gọi đúng hàm của lớp con)
    double calculateYearlySalary(int year) {
        double total = 0;
        for (int m = 1; m <= 12; m++)
            total += calculateSalary(m, year);
        return total;
    }

    virtual void display() {
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee() = default;
};

class HourlyEmployee : public Employee {
private:
    int hours;
    double salaryPerHour;
    int month, year;

public:
    HourlyEmployee() : Employee() {
        hours = 0;
        salaryPerHour = 0;
        month = 0;
        year = 0;
    }

    HourlyEmployee(string c, string p, string a,
                   int h, double s, int m, int y)
        : Employee(c, p, a) {
        hours = h;
        salaryPerHour = s;
        month = m;
        year = y;
    }

    int getHours() { return hours; }
    double getSalaryPerHour() { return salaryPerHour; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void setHours(int h) { hours = h; }
    void setSalaryPerHour(double s) { salaryPerHour = s; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return hours * salaryPerHour;
        return 0;
    }

    void display() override {
        cout << "--- Hourly Employee ---" << endl;
        Employee::display();
        cout << "Hours: " << hours << endl;
        cout << "Salary per hour: " << salaryPerHour << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month, year;

public:
    MonthlyEmployee() : Employee() {
        monthlySalary = 0;
        month = 0;
        year = 0;
    }

    MonthlyEmployee(string c, string p, string a,
                    double s, int m, int y)
        : Employee(c, p, a) {
        monthlySalary = s;
        month = m;
        year = y;
    }

    double getMonthlySalary() { return monthlySalary; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void setMonthlySalary(double s) { monthlySalary = s; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return monthlySalary;
        return 0;
    }

    void display() override {
        cout << "--- Monthly Employee ---" << endl;
        Employee::display();
        cout << "Monthly salary: " << monthlySalary << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month, year;

public:
    DailyEmployee() : Employee() {
        numberOfDays = 0;
        salaryPerDay = 0;
        month = 0;
        year = 0;
    }

    DailyEmployee(string c, string p, string a,
                  int d, double s, int m, int y)
        : Employee(c, p, a) {
        numberOfDays = d;
        salaryPerDay = s;
        month = m;
        year = y;
    }

    int getNumberOfDays() { return numberOfDays; }
    double getSalaryPerDay() { return salaryPerDay; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void setNumberOfDays(int d) { numberOfDays = d; }
    void setSalaryPerDay(double s) { salaryPerDay = s; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return numberOfDays * salaryPerDay;
        return 0;
    }

    void display() override {
        cout << "--- Daily Employee ---" << endl;
        Employee::display();
        cout << "Number of days: " << numberOfDays << endl;
        cout << "Salary per day: " << salaryPerDay << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
    }
};

int main() {
    HourlyEmployee h("001", "0901", "HCM", 160, 50000, 10, 2026);
    MonthlyEmployee m("002", "0902", "Dong Nai", 15000000, 10, 2026);
    DailyEmployee d("003", "0903", "Ha Noi", 22, 400000, 10, 2026);

    Employee* employees[] = {&h, &m, &d};

    for (Employee* e : employees) {
        e->display();
        cout << "Salary (10/2026): " << e->calculateSalary(10, 2026) << endl;
        cout << "Salary (11/2026): " << e->calculateSalary(11, 2026) << endl;
        cout << "Yearly salary (2026): " << e->calculateYearlySalary(2026) << endl;
        cout << endl;
    }
    return 0;
}