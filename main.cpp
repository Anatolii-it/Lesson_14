#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Contact {
    string name;
    string lname;
    string prim;
    string phoneNumber;
};

class PhoneBook {
private:
    vector<Contact> contacts;
    const string filename = "phonebook.bin";

public:
    PhoneBook() {
        loadFromFile();
    }

    ~PhoneBook() {
        saveToFile();
    }

    void addContact(const string& name, const string& lname, const string& prim, const string& phoneNumber) {
        contacts.push_back({ name, lname, prim, phoneNumber });
        cout << "Контакт додано успішно.\n";
    }

    void displayAllContacts() const {
        if (contacts.empty()) {
            cout << "Телефонна книга порожня.\n";
            return;
        }
        for (const auto& contact : contacts) {
            cout << "Ім'я: " << contact.name << ", Прізвище: " << contact.lname << '\n';
            cout << "Телефон: " << contact.phoneNumber << ", Примітки: " << contact.prim << '\n';
        }
    }

    void searchContact(const string& name) const {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Знайдено контакт - Ім'я: " << contact.name << ", Прізвище: " << contact.lname << '\n';
                cout << "Телефон: " << contact.phoneNumber << ", Примітки: " << contact.prim << '\n';
                return;
            }
        }
        cout << "Контакт з іменем " << name << " не знайдено.\n";
    }

    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                cout << "Контакт видалено успішно.\n";
                return;
            }
        }
        cout << "Контакт з іменем " << name << " не знайдено.\n";
    }

    void editContact(const string& name) {
        for (auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Редагування контакту - Ім'я: " << contact.name << '\n';
                cout << "Введіть нове ім'я (залиште порожнім, щоб не змінювати): ";
                string newName;
                getline(cin, newName);
                if (!newName.empty()) contact.name = newName;

                cout << "Введіть нове прізвище (залиште порожнім, щоб не змінювати): ";
                string newLname;
                getline(cin, newLname);
                if (!newLname.empty()) contact.lname = newLname;

                cout << "Введіть новий номер телефону (залиште порожнім, щоб не змінювати): ";
                string newPhoneNumber;
                getline(cin, newPhoneNumber);
                if (!newPhoneNumber.empty()) contact.phoneNumber = newPhoneNumber;

                cout << "Введіть нові примітки (залиште порожнім, щоб не змінювати): ";
                string newPrim;
                getline(cin, newPrim);
                if (!newPrim.empty()) contact.prim = newPrim;

                cout << "Контакт успішно відредаговано.\n";
                return;
            }
        }
        cout << "Контакт з іменем " << name << " не знайдено.\n";
    }

private:
    void saveToFile() const {
        ofstream file(filename, ios::binary | ios::out);
        if (!file) {
            cerr << "Помилка збереження у файл.\n";
            return;
        }

        size_t size = contacts.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for (const auto& contact : contacts) {
            size_t nameLength = contact.name.size();
            size_t lnameLength = contact.lname.size();
            size_t primLength = contact.prim.size();
            size_t phoneLength = contact.phoneNumber.size();

            file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
            file.write(contact.name.data(), nameLength);

            file.write(reinterpret_cast<const char*>(&lnameLength), sizeof(lnameLength));
            file.write(contact.lname.data(), lnameLength);

            file.write(reinterpret_cast<const char*>(&primLength), sizeof(primLength));
            file.write(contact.prim.data(), primLength);

            file.write(reinterpret_cast<const char*>(&phoneLength), sizeof(phoneLength));
            file.write(contact.phoneNumber.data(), phoneLength);
        }

        file.close();
    }

    void loadFromFile() {
        ifstream file(filename, ios::binary | ios::in);
        if (!file) {
            cout << "Не вдалося відкрити файл для читання, можливо, він не існує.\n";
            return;
        }

        size_t size = 0;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));

        contacts.resize(size);

        for (auto& contact : contacts) {
            size_t nameLength = 0;
            size_t lnameLength = 0;
            size_t primLength = 0;
            size_t phoneLength = 0;

            file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
            contact.name.resize(nameLength);
            file.read(&contact.name[0], nameLength);

            file.read(reinterpret_cast<char*>(&lnameLength), sizeof(lnameLength));
            contact.lname.resize(lnameLength);
            file.read(&contact.lname[0], lnameLength);

            file.read(reinterpret_cast<char*>(&primLength), sizeof(primLength));
            contact.prim.resize(primLength);
            file.read(&contact.prim[0], primLength);

            file.read(reinterpret_cast<char*>(&phoneLength), sizeof(phoneLength));
            contact.phoneNumber.resize(phoneLength);
            file.read(&contact.phoneNumber[0], phoneLength);
        }

        file.close();
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;
    string name, lname, prim, phoneNumber;

    do {
        cout << "\n1. Додати контакт\n2. Пошук контакту\n3. Відобразити всі контакти\n4. Видалити контакт\n5. Редагувати контакт\n6. Вийти\n";
        cout << "Введіть ваш вибір: ";
        cin >> choice;
        cin.ignore(); // Для очищення буферу вводу після вводу числа

        switch (choice) {
        case 1:
            cout << "Введіть ім'я: ";
            getline(cin, name);
            cout << "Введіть призвище: ";
            getline(cin, lname);
            cout << "Введіть примітку: ";
            getline(cin, prim);
            cout << "Введіть номер телефону: ";
            getline(cin, phoneNumber);
            phoneBook.addContact(name, lname, prim, phoneNumber);
            break;
        case 2:
            cout << "Введіть ім'я для пошуку: ";
            getline(cin, name);
            phoneBook.searchContact(name);
            break;
        case 3:
            phoneBook.displayAllContacts();
            break;
        case 4:
            cout << "Введіть ім'я для видалення: ";
            getline(cin, name);
            phoneBook.deleteContact(name);
            break;
        case 5:
            cout << "Введіть ім'я для редагування: ";
            getline(cin, name);
            phoneBook.editContact(name);
            break;
        case 6:
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 6);

    return 0;
}
