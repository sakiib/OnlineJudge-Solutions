#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    string ch="heidi";
    int t=0;
    for(int i=0;i<str.size();i++){
      if(str[i]==ch[t]) t++;
    }
    //cout<<t<<endl;
    if(t==5) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
