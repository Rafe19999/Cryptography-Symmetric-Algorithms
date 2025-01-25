#include<bits/stdc++.h>
using namespace std;

string s;
void value()
{
    char a ='a';
    for(int i=0;i<26;i++)
    {
        s.push_back(a);
        a++;
    }
}

int main(){
   value();
   string str,encrypted,decrypted;
   int k;
   cout<<"Enter the string: ";
   cin>>str;
   cout<<"Enter the key: ";
   cin>>k;
   for(int i=0;i<str.size();i++)
   {
       int t = s.find(str[i]);
       int m = (t+k)%26;
       encrypted.push_back(s[m]);
   }
   cout<<"the encrypted string is: "<<encrypted<<"\n";

   for(int i=0;i<encrypted.size();i++)
   {
       int t = s.find(encrypted[i]);
       int m = (t-k)%26;
       decrypted.push_back(s[m]);
   }
   cout<<"the decrypted string is: "<<decrypted<<"\n";
}
