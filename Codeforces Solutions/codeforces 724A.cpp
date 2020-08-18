#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    ios::sync_with_stdio(false);
    string str[14]={"monday","tuesday","wednesday","thursday","friday","saturday",
                    "sunday","monday","tuesday","wednesday","thursday","friday",
                    "saturday","sunday"};

    string str1,str2;
    cin>>str1>>str2;
    if(str1==str2){
        cout<<"YES"<<endl;
        return 0;
    }
    for(int i=0;i<14;i++){
        if(str[i]==str1){
            if(str[i+2]==str2||str[i+3]==str2){
                cout<<"YES"<<endl;
                return 0;
            }
        }

    }
    cout<<"NO"<<endl;
    return 0;
}
