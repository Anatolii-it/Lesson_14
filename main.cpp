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
        cout << "������ ϲ�: ";
        cin.getline(fullName, 100);
        cout << "������ ���� ���������� (��.��.����): ";
        cin.getline(birthDate, 11);
        cout << "������ ���������� �������: ";
        cin.getline(phoneNumber, 15);
        cout << "������ ����: ";
        cin.getline(city, 50);
        cout << "������ �����: ";
        cin.getline(country, 50);
        cout << "������ ����� �������: ";
        cin.getline(universityName, 100);
        cout << "������ ���� ��������: ";
        cin.getline(universityCity, 50);
        cout << "������ ����� ��������: ";
        cin.getline(universityCountry, 50);
        cout << "������ ����� �����: ";
        cin.getline(groupNumber, 10);
    }

    
    void display() const {
        cout << "ϲ�: " << fullName << endl;
        cout << "���� ����������: " << birthDate << endl;
        cout << "���������� �������: " << phoneNumber << endl;
        cout << "̳��� ����������: " << city << endl;
        cout << "����� ����������: " << country << endl;
        cout << "����� ����������� �������: " << universityName << endl;
        cout << "̳��� ����������� �������: " << universityCity << endl;
        cout << "����� ����������� �������: " << universityCountry << endl;
        cout << "����� �����: " << groupNumber << endl;
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
