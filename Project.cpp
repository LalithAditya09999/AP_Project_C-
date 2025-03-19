#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Base Class: Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Doctor Class
class Doctor : public Person {
    string specialization;
    int doctorID;
public:
    Doctor(string n, int a, string spec, int id) : Person(n, a), specialization(spec), doctorID(id) {}
    void display() override {
        cout << "Doctor ID: " << doctorID << "\n";
        Person::display();
        cout << "Specialization: " << specialization << "\n";
    }
    void saveToFile() {
        ofstream file("doctors.txt", ios::app);
        if (file.is_open()) {
            file << doctorID << "," << name << "," << age << "," << specialization << "\n";
            file.close();
        } else {
            cerr << "Error opening file!" << endl;
        }
    }
};

// Patient Class
class Patient : public Person {
    int patientID;
    string ailment;
public:
    Patient(string n, int a, int id, string ail) : Person(n, a), patientID(id), ailment(ail) {}
    void display() override {
        cout << "Patient ID: " << patientID << "\n";
        Person::display();
        cout << "Ailment: " << ailment << "\n";
    }
    void saveToFile() {
        ofstream file("patients.txt", ios::app);
        if (file.is_open()) {
            file << patientID << "," << name << "," << age << "," << ailment << "\n";
            file.close();
        } else {
            cerr << "Error opening file!" << endl;
        }
    }
};

// Appointment Class
class Appointment {
    int patientID;
    int doctorID;
    string date;
public:
    Appointment(int pID, int dID, string d) : patientID(pID), doctorID(dID), date(d) {}
    void display() {
        cout << "Appointment Details:\nPatient ID: " << patientID << "\nDoctor ID: " << doctorID << "\nDate: " << date << "\n";
    }
    void saveToFile() {
        ofstream file("appointments.txt", ios::app);
        if (file.is_open()) {
            file << patientID << "," << doctorID << "," << date << "\n";
            file.close();
        } else {
            cerr << "Error opening file!" << endl;
        }
    }
};

// Main Function
int main() {
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;
    
    int choice;
    do {
        cout << "\nHospital Management System\n";
        cout << "1. Add Doctor\n2. Add Patient\n3. Schedule Appointment\n4. View Doctors\n5. View Patients\n6. View Appointments\n7. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, spec;
            int age, id;
            cout << "Enter Doctor Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter Age: "; cin >> age;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Specialization: "; cin.ignore(); getline(cin, spec);
            Doctor d(name, age, spec, id);
            d.saveToFile();
            doctors.push_back(d);
        } else if (choice == 2) {
            string name, ailment;
            int age, id;
            cout << "Enter Patient Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter Age: "; cin >> age;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Ailment: "; cin.ignore(); getline(cin, ailment);
            Patient p(name, age, id, ailment);
            p.saveToFile();
            patients.push_back(p);
        } else if (choice == 3) {
            int pID, dID;
            string date;
            cout << "Enter Patient ID: "; cin >> pID;
            cout << "Enter Doctor ID: "; cin >> dID;
            cout << "Enter Date (YYYY-MM-DD): "; cin.ignore(); getline(cin, date);
            Appointment a(pID, dID, date);
            a.saveToFile();
            appointments.push_back(a);
        } else if (choice == 4) {
            for (auto &d : doctors) d.display();
        } else if (choice == 5) {
            for (auto &p : patients) p.display();
        } else if (choice == 6) {
            for (auto &a : appointments) a.display();
        }
    } while (choice != 7);
    
    return 0;
}

