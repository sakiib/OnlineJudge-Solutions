#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    if(str=="h1"||str=="a1"||str=="a8"||str=="h8") cout<<3<<endl;
    else if(str[0]=='a'||str[0]=='h'||str[1]=='1'||str[1]=='8') cout<<5<<endl;
    else cout<<8<<endl;
}
