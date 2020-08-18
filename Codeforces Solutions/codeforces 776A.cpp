#include<bits/stdc++.h>
#include<stdio.h>
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;
stack<int>mysti;
stack<char>mystc;
vector<ll>myvec;
map<string,int>mymapsi;
map<string,string>mymapss;
map<int,int>mymapii;
map<ll,ll>mymapll;
int main()
{
    int n;
    string str1,str2,a,b;
    cin>>str1>>str2;
    cin>>n;
    cout<<str1<< " " <<str2<<endl;
    while(n--)
    {
       cin>>a>>b;
       if(str1==a)
       {
           str1=b;
           cout<<str1<< " " <<str2<<endl;
       }
       else if(str2==a)
       {
         str2=b;
         cout<<str1<< " " <<str2<<endl;
       }
    }

  return 0;
}



