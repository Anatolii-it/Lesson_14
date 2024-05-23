#include "lib.h"


bool isVowel(char ch) {
    ch = tolower(static_cast<unsigned char>(ch));
    return ch == 'а' || ch == 'е' || ch == 'є' || ch == 'и' || ch == 'і' || ch == 'ї' || ch == 'о' || ch == 'у' || ch == 'ю' || ch == 'я';
}

bool isConsonant(char ch) {
    ch = tolower(static_cast<unsigned char>(ch));
    return (ch >= 'а' && ch <= 'я') && !isVowel(ch);
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}
