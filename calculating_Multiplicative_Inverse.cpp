#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,inv_k;
    cout<< "Enter the key: ";
    cin>>k;
    for(int i=0;i<26;i++)
    {
        if((k*i)%26 ==1)
        {
           inv_k = i;
           break;
        }
    }
    cout<<"the multiplicative inverse of the key is: "<<inv_k;
}
