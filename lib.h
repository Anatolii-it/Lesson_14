#ifndef LIB_H
#define LIB_H
#include <fstream>
#include <iostream>

using namespace std;

void readArrayFromFile(const string& filename, int& rows, int& cols, int**& array);
void writeArrayToFile(const string& filename, int rows, int cols, int** array);
void sortColumns(int rows, int cols, int** array);
void freeArray(int rows, int** array);

#endif  LIB_H
