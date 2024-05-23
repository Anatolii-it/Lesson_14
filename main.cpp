#include "lib.h"

int main() {
    int rows, cols;
    int** array;

    readArrayFromFile("input.txt", rows, cols, array);

    sortColumns(rows, cols, array);

    writeArrayToFile("output.txt", rows, cols, array);

    freeArray(rows, array);

    return 0;
}