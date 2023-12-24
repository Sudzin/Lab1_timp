#include "modalphacipher.h"
#include <cmath>

ModalphaCipher::ModalphaCipher(int numcolumns) {
    this->numcolumns = numcolumns;
}

std::string ModalphaCipher::encrypt(const std::string& plaintext) {
    int numrows = std::ceil(static_cast<double>(plaintext.length()) / this->numcolumns);

    char table[numrows][this->numcolumns];
    int textindex = 0;

    // заполняем таблицу символами из plaintext
    for (int row = 0; row < numrows; ++row) {
        for (int column = 0; column < this->numcolumns; ++column) {
            if (textindex < plaintext.length()) {
                table[row][column] = plaintext[textindex++];
            } else {
                table[row][column] = '*'; // заполняем оставшееся пространство звездочками
            }
        }
    }

    // считываем зашифрованный текст по маршруту справа налево, сверху вниз
    std::string ciphertext;
    for (int column = this->numcolumns - 1; column >= 0; --column) {
        for (int row = 0; row < numrows; ++row) {
            if (table[row][column] != '*') {
                ciphertext += table[row][column];
            }
        }
    }

    return ciphertext;
}

std::string ModalphaCipher::decrypt(const std::string& ciphertext) {
    int numrows = std::ceil(static_cast<double>(ciphertext.length()) / this->numcolumns);

    char table[numrows][this->numcolumns];
    int textindex = 0;

    // заполняем таблицу символами из ciphertext
    for (int column = this->numcolumns - 1; column >= 0; --column) {
        for (int row = 0; row < numrows; ++row) {
            if (textindex < ciphertext.length()) {
                table[row][column] = ciphertext[textindex++];
            } else {
                table[row][column] = '*'; // заполняем оставшееся пространство звездочками
            }
        }
    }

    // считываем расшифрованный текст по маршруту сверху вниз, слева направо
    std::string plaintext;
    for (int row = 0; row < numrows; ++row) {
        for (int column = 0; column < this->numcolumns; ++column) {
            if (table[row][column] != '*') {
                plaintext += table[row][column];
            }
        }
    }

    return plaintext;
}
