#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
using namespace std;

bool isValid(const wstring& s)
{
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned operation;
    wcout<<L"Введите ключ: ";
    wcin>>key;
    if (!isValid(key)) {
        wcerr<<L"Неправильный ключ\n";
        return 1;
    }
    modAlphaCipher cipher(key);
    do {
        wcout<<L"(0-выход, 1-зашифровать, 2-расшифровать): ";
        wcin>>operation;
        if (operation > 2) {
            wcout<<L"Ошибка\n";
        } else if (operation >0) {
            wcout<<L"Введите текст: ";
            wcin>>text;
            if (isValid(text)) {
                if (operation==1) {
                    wcout<<L"Зашифрованный текст: "<<cipher.encrypt(text)<<endl;
                } else {
                    wcout<<L"Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<L"Неправильно введённый текст\n";
            }
        }
    } while (operation!=0);
    return 0;
}
