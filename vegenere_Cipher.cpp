#include<bits/stdc++.h>
using namespace std;

string s;

void value() {
    char a = 'A';
    for (int i = 0; i < 26; i++) {
        s.push_back(a);
        a++;
    }
}

string encrypt(const string& plaintext, const string& key) {
    string encrypted_text;
    int keyLength = key.length();

    for (int i = 0, j = 0; i < plaintext.length(); i++) {
        char plainChar = toupper(plaintext[i]);
        char keyChar = toupper(key[j % keyLength]);
        char encryptedChar = ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A';
        encrypted_text.push_back(encryptedChar);
        j++;
    }
    return encrypted_text;
}

string decrypt(const string& ciphertext, const string& key) {
    string decrypted_text;
    int keyLength = key.length();

    for (int i = 0, j = 0; i < ciphertext.length(); i++) {
        char cipherChar = toupper(ciphertext[i]);
        char keyChar = toupper(key[j % keyLength]);
        char decryptedChar = ((cipherChar - keyChar + 26) % 26) + 'A';
        decrypted_text.push_back(decryptedChar);
        j++;
    }
    return decrypted_text;
}

int main() {
    value();
    string plaintext = "MEETMEINTHEPARK";
    string key = "PASCAL";

    cout << "Plaintext: MEET ME IN THE PARK" << endl;
    cout << "Key: " << key << endl;

    string encrypted = encrypt(plaintext, key);
    cout << "The encrypted string: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "The decrypted string: " << decrypted << endl;

    return 0;
}
