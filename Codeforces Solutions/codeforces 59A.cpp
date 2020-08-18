#include<bits/stdc++.h>
using namespace std;
int main()
{
    int up=0,low=0;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='a'&&str[i]<='z') low++;
        else up++;
    }
    if(up>low){
        for(int i=0;i<str.size();i++){
            if(str[i]>='a'&&str[i]<='z') str[i]-=32;
            cout<<str[i];
        }
    }
    else{
        for(int i=0;i<str.size();i++){
            if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
            cout<<str[i];
        }
    }
    return 0;
}
