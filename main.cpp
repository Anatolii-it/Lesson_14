#include "lib.h"

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile) {
        cerr << "Не вдалося відкрити файл input.txt" << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Не вдалося створити файл output.txt" << endl;
        return 1;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    string line;
    while (getline(inputFile, line)) {
        lineCount++;
        for (char ch : line) {
            charCount++;
            if (isDigit(ch)) {
                digitCount++;
            }
            else if (isVowel(ch)) {
                vowelCount++;
            }
            else if (isConsonant(ch)) {
                consonantCount++;
            }
        }
        charCount++;
    }

    if (charCount > 0) {
        charCount--;
    }

    outputFile << "Кількість символів: " << charCount << endl;
    outputFile << "Кількість рядків: " << lineCount << endl;
    outputFile << "Кількість голосних літер: " << vowelCount << endl;
    outputFile << "Кількість приголосних літер: " << consonantCount << endl;
    outputFile << "Кількість цифр: " << digitCount << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
