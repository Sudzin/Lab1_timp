#include <iostream>
#include <string>
#include "modalphacipher.h"

int main() {
    int operation;
    do {
        std::cout << "введите операцию (0-выход, 1-шифрование, 2-дешифрование): ";
        std::cin >> operation;

        std::cin.ignore();

        if (operation == 1) {
            std::cout << "введите открытый текст: ";
            std::string plaintext;
            std::getline(std::cin, plaintext);

            std::cout << "введите количество столбцов таблицы: ";
            int numcolumns;
            std::cin >> numcolumns;

            std::cin.ignore();

            ModalphaCipher cipher(numcolumns);
            std::string ciphertext = cipher.encrypt(plaintext);
            std::cout << "зашифрованный текст: " << ciphertext << std::endl;
        } else if (operation == 2) {
            std::cout << "введите зашифрованный текст: ";
            std::string ciphertext;
            std::getline(std::cin, ciphertext);

            std::cout << "введите количество столбцов таблицы: ";
            int numcolumns;
            std::cin >> numcolumns;

            std::cin.ignore();

            ModalphaCipher cipher(numcolumns);
            std::string decryptedtext = cipher.decrypt(ciphertext);
            std::cout << "расшифрованный текст: " << decryptedtext << std::endl;
        }
    } while (operation != 0);

    return 0;
}
