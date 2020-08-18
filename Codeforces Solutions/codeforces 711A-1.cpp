#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos;
    string str,str1="";
    cin>>n;
    while(n--){
        cin>>str;
        str1+=str+'\n';
    }
        pos=str1.find("OO");
        //cout<<pos<<endl;
        if(pos>=0) {
             str1.replace(pos,2,"++");
             cout<<"YES"<<endl;
             cout<<str1;
        }
        else cout<<"NO"<<endl;
        return 0;
}
