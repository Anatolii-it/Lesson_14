#include <iostream>
using namespace std;

class Student {
private:
    char fullName[100];
    char birthDate[11];
    char phoneNumber[15];
    char city[50];
    char country[50];
    char universityName[100];
    char universityCity[50];
    char universityCountry[50];
    char groupNumber[10];

public:
    
    Student() {}

    
    void input() {
        cout << "Введіть ПІБ: ";
        cin.getline(fullName, 100);
        cout << "Введіть дату народження (дд.мм.рррр): ";
        cin.getline(birthDate, 11);
        cout << "Введіть контактний телефон: ";
        cin.getline(phoneNumber, 15);
        cout << "Введіть місто: ";
        cin.getline(city, 50);
        cout << "Введіть країну: ";
        cin.getline(country, 50);
        cout << "Введіть назву закладу: ";
        cin.getline(universityName, 100);
        cout << "Введіть місто навчання: ";
        cin.getline(universityCity, 50);
        cout << "Введіть країну навчання: ";
        cin.getline(universityCountry, 50);
        cout << "Введіть номер групи: ";
        cin.getline(groupNumber, 10);
    }

    
    void display() const {
        cout << "ПІБ: " << fullName << endl;
        cout << "Дата народження: " << birthDate << endl;
        cout << "Контактний телефон: " << phoneNumber << endl;
        cout << "Місто проживання: " << city << endl;
        cout << "Країна проживання: " << country << endl;
        cout << "Назва навчального закладу: " << universityName << endl;
        cout << "Місто навчального закладу: " << universityCity << endl;
        cout << "Країна навчального закладу: " << universityCountry << endl;
        cout << "Номер групи: " << groupNumber << endl;
    }

    const char* getFullName() const { return fullName; }
    const char* getBirthDate() const { return birthDate; }
    const char* getPhoneNumber() const { return phoneNumber; }
    const char* getCity() const { return city; }
    const char* getCountry() const { return country; }
    const char* getUniversityName() const { return universityName; }
    const char* getUniversityCity() const { return universityCity; }
    const char* getUniversityCountry() const { return universityCountry; }
    const char* getGroupNumber() const { return groupNumber; }
};

int main() {
    Student student;
    student.input();
    student.display();
    return 0;
}
