#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll cnt=0,val;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if((str[i]-'0')%4==0) cnt++;
    }
    for(int i=0;i<str.size()-1;i++){
        val=(str[i]-'0')*10+(str[i+1]-'0');
        if(val%4==0){
            cnt+=(i+1);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
