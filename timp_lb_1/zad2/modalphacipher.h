#ifndef modalphacipher_h
#define modalphacipher_h

#include <string>

class ModalphaCipher {
private:
    int numcolumns;

public:
    ModalphaCipher(int numcolumns);
    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);
};

#endif // modalphacipher_h
