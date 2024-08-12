#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Contact {
    std::string name;
    std::string phoneNumber;
};

class PhoneBook {
private:
    std::vector<Contact> contacts;
    const std::string filename = "phonebook.bin";

public:
    PhoneBook() {
        loadFromFile();
    }

    ~PhoneBook() {
        saveToFile();
    }

    void addContact(const std::string& name, const std::string& phoneNumber) {
        contacts.push_back({ name, phoneNumber });
        std::cout << "Контакт додано успішно.\n";
    }

    void displayAllContacts() const {
        if (contacts.empty()) {
            std::cout << "Телефонна книга порожня.\n";
            return;
        }
        for (const auto& contact : contacts) {
            std::cout << "Ім'я: " << contact.name << ", Номер телефону: " << contact.phoneNumber << '\n';
        }
    }

    void searchContact(const std::string& name) const {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                std::cout << "Знайдено контакт - Ім'я: " << contact.name << ", Номер телефону: " << contact.phoneNumber << '\n';
                return;
            }
        }
        std::cout << "Контакт з іменем " << name << " не знайдено.\n";
    }

    void deleteContact(const std::string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                std::cout << "Контакт видалено успішно.\n";
                return;
            }
        }
        std::cout << "Контакт з іменем " << name << " не знайдено.\n";
    }

private:
    void saveToFile() const {
        std::ofstream file(filename, std::ios::binary | std::ios::out);
        if (!file) {
            std::cerr << "Помилка збереження у файл.\n";
            return;
        }

        size_t size = contacts.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for (const auto& contact : contacts) {
            size_t nameLength = contact.name.size();
            size_t phoneLength = contact.phoneNumber.size();

            file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
            file.write(contact.name.data(), nameLength);

            file.write(reinterpret_cast<const char*>(&phoneLength), sizeof(phoneLength));
            file.write(contact.phoneNumber.data(), phoneLength);
        }

        file.close();
    }

    void loadFromFile() {
        std::ifstream file(filename, std::ios::binary | std::ios::in);
        if (!file) {
            std::cout << "Не вдалося відкрити файл для читання, можливо, він не існує.\n";
            return;
        }

        size_t size = 0;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));

        contacts.resize(size);

        for (auto& contact : contacts) {
            size_t nameLength = 0;
            size_t phoneLength = 0;

            file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
            contact.name.resize(nameLength);
            file.read(&contact.name[0], nameLength);

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
    std::string name, phoneNumber;

    do {
        std::cout << "\n1. Додати контакт\n2. Пошук контакту\n3. Відобразити всі контакти\n4. Видалити контакт\n5. Вийти\n";
        std::cout << "Введіть ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введіть ім'я: ";
            std::cin.ignore(); // Для очищення буферу вводу
            std::getline(std::cin, name);
            std::cout << "Введіть номер телефону: ";
            std::getline(std::cin, phoneNumber);
            phoneBook.addContact(name, phoneNumber);
            break;
        case 2:
            std::cout << "Введіть ім'я для пошуку: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            phoneBook.searchContact(name);
            break;
        case 3:
            phoneBook.displayAllContacts();
            break;
        case 4:
            std::cout << "Введіть ім'я для видалення: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            phoneBook.deleteContact(name);
            break;
        case 5:
            std::cout << "Вихід з програми.\n";
            break;
        default:
            std::cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 5);

    return 0;
}
