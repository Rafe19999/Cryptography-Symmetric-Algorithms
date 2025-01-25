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

string encrypt(const string& str, int key1, int key2) {
    string encrypted_text;
    for (int i = 0; i < str.size(); i++) {

            int t = s.find(str[i]);
            int m = ((key1 * t) + key2) % 26;
            encrypted_text.push_back(s[m]);

    }
    return encrypted_text;
}

string decrypt(const string& encrypted, int key1, int key2) {
    int inv_key1 = 0;
    for (int i = 0; i < 26; i++) {
        if ((key1 * i) % 26 == 1) {
            inv_key1 = i;
            break;
        }
    }
    string decrypted_text;
    for (int i = 0; i < encrypted.size(); i++) {
            int t = s.find(encrypted[i]);
            int m = ((t - key2+26) * inv_key1) % 26;
            decrypted_text.push_back(s[m]);
    }
    return decrypted_text;
}

int main() {
    value();
    string str;
    int key1,key2;

    cout<<"Enter the string: ";
    cin>>str;
    cout<<"Enter the key1: ";
    cin>>key1;
    cout<<"Enter the key2: ";
    cin>>key2;

    string encrypted = encrypt(str, key1, key2);
    cout << "Encrypted Message: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key1, key2);
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}

