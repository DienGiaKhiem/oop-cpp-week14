#include <iostream>
#include <string>
using namespace std;

class Employee {
    private:
    string cccd;
    string name;
    double salary;
    public:
    Employee(){
        cccd = "";
        name = "";
        salary = 0;
    }

    Employee(string c, string n, double s){
        cccd = c;
        name = n;
        salary = s;
    }

    string GetCCCD(){
        return cccd;
    }

    string GetName(){
        return name;
    }

    double GetSalary(){
        return salary;
    }

    void SetCCCD(double c){
        cccd = c;
    }

    void SetName(string n){
        name = n;
    }

    void SetSalary(double s){
        salary = s;
    }

    void display(){
        cout << "CCCD: " << GetCCCD() << endl;
        cout << "Name: " << GetName() << endl;
        cout << "Salary: " << GetSalary() << endl;
    }
};

class HourlyEmployee : public Employee{
    private:
    double hour;
    double salaryhour;
    int month;
    int year;
    public:
    HourlyEmployee() : Employee(){
        hour = 0;
        salaryhour = 0;
        month = 0;
        year = 0;
    }

    HourlyEmployee(string c, string n, double s, double h, double sh, int m, int y) : Employee(c, n, s){
        hour = h;
        salaryhour = sh;
        month = m;
        year = y;
    }
};

int main(){
    Employee e1;
    Employee e2("079222333", "Dien Gia Khiem", 2007);
    return 0;
}