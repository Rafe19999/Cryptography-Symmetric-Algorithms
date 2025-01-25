#include<bits/stdc++.h>
using namespace std;

string s;

void value() {
    char a = 'a';
    for (int i = 0; i < 26; i++) {
        s.push_back(a);
        a++;
    }
}

string encrypt(const string& str, int key) {
    string encrypted_text;
    for (int i = 0; i < str.size(); i++) {
        int t = s.find(str[i]);
        int m = (t + key) % 26;
        encrypted_text.push_back(s[m]);
        key = t;
    }
    return encrypted_text;
}

string decrypt(const string& encrypted, int key) {
    string decrypted_text;
    for (int i = 0; i < encrypted.size(); i++) {
        int t = s.find(encrypted[i]);
        int m = (t - key + 26) % 26;
        decrypted_text.push_back(s[m]);
        key = m;
    }
    return decrypted_text;
}

int main() {
    value();
    string str;
    int key;

    cout << "Enter the string: ";
    cin >> str;
    cout << "Enter the key: ";
    cin >> key;

    string encrypted = encrypt(str, key);
    cout << "The encrypted string: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "The decrypted string: " << decrypted << endl;

    return 0;
}

