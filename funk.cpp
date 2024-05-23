#include "lib.h"



void readArrayFromFile(const string& filename, int& rows, int& cols, int**& array) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл " << filename << endl;
        exit(1);
    }

    inputFile >> rows >> cols;

    array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputFile >> array[i][j];
        }
    }

    inputFile.close();
}

void writeArrayToFile(const string& filename, int rows, int cols, int** array) {
    std::ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Не вдалося створити файл " << filename << endl;
        exit(1);
    }

    outputFile << rows << " " << cols << endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outputFile << array[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();
}

void sortColumns(int rows, int cols, int** array) {
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows - 1; ++i) {
            for (int k = i + 1; k < rows; ++k) {
                if (array[i][j] > array[k][j]) {
                    int temp = array[i][j];
                    array[i][j] = array[k][j];
                    array[k][j] = temp;
                }
            }
        }
    }
}

void freeArray(int rows, int** array) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}
