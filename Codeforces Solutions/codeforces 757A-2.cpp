#include<bits/stdc++.h>
using namespace std;
int main()
{
    int coun=0;
    int B=0,u=0,l=0,b=0,a=0,s=0,r=0;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='B') B++;
        else if(str[i]=='u') u++;
        else if(str[i]=='l') l++;
        else if(str[i]=='b') b++;
        else if(str[i]=='a') a++;
        else if(str[i]=='s') s++;
        else if(str[i]=='r') r++;
    }
    while(B>=1&&l>=1&&b>=1&&s>=1&&a>=2&&u>=2&&r>=1)
     {
        coun++;
        B--;u-=2;l--;b--;s--;a-=2;r-=1;
     }
    cout<<coun<<endl;
    return 0;
}
