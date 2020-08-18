#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0;
    string str;
    char cur='a';
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
       sum+=min(abs(cur-str[i]),26-abs(cur-str[i]));
       cur=str[i];
    }
    cout<<sum<<endl;
    return 0;
}
