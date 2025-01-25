
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tt "\t"
#define nl "\n"



int main()
{
    system("color B");
   ll r1, r2, r, s1=1, s2=0, s, t1=0 , t2=1, t, q, x, y;

   cin>> r1>>r2;
   x=r1;
   y=r2;


   cout<<tt<<"q"<<tt<<"r1"<<tt<<"r2"<<"r"<<tt<<"s1"<<tt<<"s2"<<tt<<"s"<<"t1"<<tt<<"t2"<<tt<<"t"<<nl;
   while(r2!=0)

   {
       q=r1/r2;
       cout<<tt<<q<<tt<<r1<<tt<<r2<<r<<tt<<s1<<tt<<s2<<tt<<s<<t1<<tt<<t2<<tt<<t<<nl;


   r=r1- (q*r2);
   t=t1- (q*t2);
   s=s1 - (q*s2);

   r1=r2;
   r2=r;

   s1=s2;
   s2=s;


   t1=t2;
   t2=t;

   }

   cout<<tt<<"q"<<tt<<"r1"<<tt<<"r2"<<"r"<<tt<<"s1"<<tt<<"s2"<<tt<<"s"<<"t1"<<tt<<"t2"<<tt<<"t"<<nl;

   cout<< "G. C. D. is : "<<r1<<nl;


  // verify

  if ((s1*x)+ (t1*y)==r1)

    {
    cout<<"Verified";
    }
    else
    {
    cout<<"NOT Verified";
    }
}
