#include <iostream>

const int MAX_STUDENTS = 100;
const int MAX_SUBJECTS = 10;
const int MAX_NAME_LENGTH = 50;
const int MAX_GRADES = 2;

class Subject {
public:
    char name[MAX_NAME_LENGTH];

    Subject() {
        name[0] = '\0';
    }

    Subject(const char* name) {
        int i = 0;
        while (name[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
            this->name[i] = name[i];
            ++i;
        }
        this->name[i] = '\0';
    }
};

class Student {
public:
    char name[MAX_NAME_LENGTH];
    int grades[MAX_SUBJECTS][MAX_GRADES];

    Student() {
        name[0] = '\0';
        for (int i = 0; i < MAX_SUBJECTS; ++i) {
            for (int j = 0; j < MAX_GRADES; ++j) {
                grades[i][j] = -1;  // -1 означає, що оцінка відсутня
            }
        }
    }

    Student(const char* name) {
        int i = 0;
        while (name[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
            this->name[i] = name[i];
            ++i;
        }
        this->name[i] = '\0';
        for (int j = 0; j < MAX_SUBJECTS; ++j) {
            for (int k = 0; k < MAX_GRADES; ++k) {
                grades[j][k] = -1;
            }
        }
    }

    void addGrade(int subjectIndex, int grade, int gradeIndex) {
        if (gradeIndex < MAX_GRADES) {
            grades[subjectIndex][gradeIndex] = grade;
        }
    }

    double averageGrade(int subjectIndex) const {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < MAX_GRADES; ++i) {
            if (grades[subjectIndex][i] != -1) {
                sum += grades[subjectIndex][i];
                count++;
            }
        }
        return count > 0 ? sum / count : 0.0;
    }

    double overallAverageGrade() const {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < MAX_SUBJECTS; ++i) {
            for (int j = 0; j < MAX_GRADES; ++j) {
                if (grades[i][j] != -1) {
                    sum += grades[i][j];
                    count++;
                }
            }
        }
        return count > 0 ? sum / count : 0.0;
    }
};

class Group {
public:
    char name[MAX_NAME_LENGTH];
    Student students[MAX_STUDENTS];
    Subject subjects[MAX_SUBJECTS];
    int studentCount;
    int subjectCount;

    Group(const char* name) : studentCount(0), subjectCount(0) {
        int i = 0;
        while (name[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
            this->name[i] = name[i];
            ++i;
        }
        this->name[i] = '\0';
    }

    void addStudent(const Student& student) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = student;
        }
    }

    void addSubject(const Subject& subject) {
        if (subjectCount < MAX_SUBJECTS) {
            subjects[subjectCount++] = subject;
        }
    }

    void printGrades() const {
        std::cout << "Оцінки:\n";
        for (int i = 0; i < studentCount; ++i) {
            std::cout << students[i].name << ":\n";
            for (int j = 0; j < subjectCount; ++j) {
                std::cout << "  " << subjects[j].name << ": ";
                for (int k = 0; k < MAX_GRADES; ++k) {
                    if (students[i].grades[j][k] != -1) {
                        std::cout << students[i].grades[j][k] << " ";
                    }
                    else {
                        std::cout << "N/A ";
                    }
                }
                std::cout << "(середнє: " << students[i].averageGrade(j) << ")\n";
            }
        }
    }

    void printAverageGrades() const {
        std::cout << "Середні оцінки:\n";
        for (int i = 0; i < studentCount; ++i) {
            std::cout << students[i].name << ": " << students[i].overallAverageGrade() << "\n";
        }
    }

    void printSubjectAverages() const {
        std::cout << "Середнє значення по предметах:\n";
        for (int j = 0; j < subjectCount; ++j) {
            double sum = 0;
            int count = 0;
            for (int i = 0; i < studentCount; ++i) {
                for (int k = 0; k < MAX_GRADES; ++k) {
                    if (students[i].grades[j][k] != -1) {
                        sum += students[i].grades[j][k];
                        count++;
                    }
                }
            }
            if (count > 0) {
                std::cout << subjects[j].name << ": " << (sum / count) << "\n";
            }
            else {
                std::cout << subjects[j].name << ": N/A\n";
            }
        }
    }

    void printGroupAverage() const {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < studentCount; ++i) {
            sum += students[i].overallAverageGrade();
            count++;
        }
        std::cout << "Середні по групі: " << (sum / count) << "\n";
    }

    void printMinMaxGrades() const {
        for (int j = 0; j < subjectCount; ++j) {
            int minGrade = 101;
            int maxGrade = -1;
            const char* minStudent = nullptr;
            const char* maxStudent = nullptr;
            for (int i = 0; i < studentCount; ++i) {
                for (int k = 0; k < MAX_GRADES; ++k) {
                    if (students[i].grades[j][k] != -1) {
                        if (students[i].grades[j][k] < minGrade) {
                            minGrade = students[i].grades[j][k];
                            minStudent = students[i].name;
                        }
                        if (students[i].grades[j][k] > maxGrade) {
                            maxGrade = students[i].grades[j][k];
                            maxStudent = students[i].name;
                        }
                    }
                }
            }
            std::cout << subjects[j].name << ":\n";
            if (minStudent) {
                std::cout << "  Min: " << minGrade << " (" << minStudent << ")\n";
            }
            else {
                std::cout << "  Min: N/A\n";
            }
            if (maxStudent) {
                std::cout << "  Max: " << maxGrade << " (" << maxStudent << ")\n";
            }
            else {
                std::cout << "  Max: N/A\n";
            }
        }
    }
};

void loadStudents(Group& group) {
    int numStudents;
    std::cout << "Введіть кількість учнів: ";
    std::cin >> numStudents;
    std::cin.ignore();

    for (int i = 0; i < numStudents; ++i) {
        char name[MAX_NAME_LENGTH];
        std::cout << "Введіть ім'я учня: ";
        std::cin.getline(name, MAX_NAME_LENGTH);
        group.addStudent(Student(name));
    }
}

void loadSubjects(Group& group) {
    int numSubjects;
    std::cout << "Введіть кількість предметів: ";
    std::cin >> numSubjects;
    std::cin.ignore();

    for (int i = 0; i < numSubjects; ++i) {
        char name[MAX_NAME_LENGTH];
        std::cout << "Введіть назву предмету: ";
        std::cin.getline(name, MAX_NAME_LENGTH);
        group.addSubject(Subject(name));
    }
}

void loadGrades(Group& group) {
    std::cout << "Введення оцінок для кожного студента:\n";
    for (int i = 0; i < group.studentCount; ++i) {
        std::cout << "Оцінки для " << group.students[i].name << ":\n";
        for (int j = 0; j < group.subjectCount; ++j) {
            for (int k = 0; k < MAX_GRADES; ++k) {
                int grade;
                std::cout << "  " << group.subjects[j].name << " (оцінка " << (k + 1) << "): ";
                std::cin >> grade;
                group.students[i].addGrade(j, grade, k);
            }
        }
    }
}

int main() {
    char groupName[MAX_NAME_LENGTH];
    std::cout << "Введіть назву групи: ";
    std::cin.getline(groupName, MAX_NAME_LENGTH);

    Group group(groupName);

    loadStudents(group);
    loadSubjects(group);
    loadGrades(group);

    group.printGrades();
    group.printAverageGrades();
    group.printSubjectAverages();
    group.printGroupAverage();
    group.printMinMaxGrades();

    return 0;
}
