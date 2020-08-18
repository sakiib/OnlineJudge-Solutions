 #include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const double eps = 1e-6;
const int SIZE = 100000005;
const int Size = 100005;
const int MOD = 1000000007;
const double PI = 2*acos(0.0);
const long long INF = 214738360000;
typedef long long int LL;
typedef unsigned long long int LLU;

int main()
{
    char last;
    string str,str1="",str2;
    int ans=1,i,j=5;
    cin>>str;
    str2=str;
    while(1){
    last=str[str.size()-1];
    str1.push_back(last);
    for(i=0;i<str.size()-1;i++)
     {
       str1+=str[i];
     }
    //cout<<str1<<endl;
     if(str2==str1) break;
     else ans++;
     str=str1;
     str1="";
    }
     cout<<ans;
   return 0;
}
