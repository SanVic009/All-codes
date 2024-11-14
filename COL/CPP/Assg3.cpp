#include <iostream>

using namespace std;

// Base class Employee
class Employee {
private:
    string Ename;
    int EmpID;

public:
    Employee() : Ename("Rohan"), EmpID(1) {}

    Employee(string name, int id) : Ename(name), EmpID(id) {}

    virtual void accept() {
        cout << "Enter Employee Name: ";
        cin >> Ename;
        cout << "Enter Employee ID: ";
        cin >> EmpID;
    }

    virtual void display() {
        cout << "Employee Name: " << Ename << endl;
        cout << "Employee ID: " << EmpID << endl;
    }

    virtual void earnings() = 0;
};

// Derived class SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double weeklySalary;

public:
    SalariedEmployee() : weeklySalary(0) {}

    SalariedEmployee(string name, int id, double salary) : Employee(name, id), weeklySalary(salary) {}

    void accept() {
        Employee::accept();
        cout << "Enter Weekly Salary: ";
        cin >> weeklySalary;
    }

    void display() {
        Employee::display();
        cout << "Weekly Salary: " << weeklySalary << endl;
    }

    void earnings() {
        cout << "Earnings: " << weeklySalary << endl;
    }
};

// Derived class HourlyEmployee
class HourlyEmployee : public Employee {
private:
    double wage;
    double hours;

public:
    HourlyEmployee() : wage(0), hours(0) {}

    HourlyEmployee(string name, int id, double w, double h) : Employee(name, id), wage(w), hours(h) {}

    void accept() {
        Employee::accept();
        cout << "Enter Wage: ";
        cin >> wage;
        cout << "Enter Hours Worked: ";
        cin >> hours;
    }

    void display() {
        Employee::display();
        cout << "Wage: " << wage << endl;
        cout << "Hours Worked: " << hours << endl;
    }

    void earnings() {
        double hourlySalary;
        if (hours <= 40) {
            hourlySalary = hours * wage;
        } else {
            hourlySalary = 40 * wage + ((hours - 40) * wage) * 1.5;
        }
        cout << "Earnings: " << hourlySalary << endl;
    }
};

// Derived class CommissionEmployee
class CommissionEmployee : public Employee {
private:
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee() : grossSales(0), commissionRate(0) {}

    CommissionEmployee(string name, int id, double sales, double rate) : Employee(name, id), grossSales(sales), commissionRate(rate) {}

    void accept() {
        Employee::accept();
        cout << "Enter Gross Sales: ";
        cin >> grossSales;
        cout << "Enter Commission Rate: ";
        cin >> commissionRate;
    }

    void display() {
        Employee::display();
        cout << "Gross Sales: " << grossSales << endl;
        cout << "Commission Rate: " << commissionRate << endl;
    }

    void earnings(){
        double commissionSalary = grossSales * commissionRate;
        cout << "Earnings: " << commissionSalary << endl;
    }
};

int main() {
    int choice;
    bool cont = true;

    while (cont) {
        cout << "\nSelect Employee Type:" << endl;
        cout << "1. Salaried Employee" << endl;
        cout << "2. Hourly Employee" << endl;
        cout << "3. Commission Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{ 
                SalariedEmployee salariedEmp;
                salariedEmp.accept();
                cout << "\nEmployee Details:" << endl;
                salariedEmp.display();
                salariedEmp.earnings();
                break;
            }

            case 2: {
                HourlyEmployee hourlyEmp;
                hourlyEmp.accept();
                cout << "\nEmployee Details:" << endl;
                hourlyEmp.display();
                hourlyEmp.earnings();
                break;
            }

            case 3: {
                CommissionEmployee commissionEmp;
                commissionEmp.accept();
                cout << "\nEmployee Details:" << endl;
                commissionEmp.display();
                commissionEmp.earnings();
                break;
            }

            case 4:
                cont = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
