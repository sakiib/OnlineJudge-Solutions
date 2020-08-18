#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    long long ans=0;
    map<char,int> M;
    cin>>str;
    for(int i=0;i<str.size();i++){
        M[str[i]]++;
    }
    map<char,int> :: iterator it;
    for(int i=0;i<str.size();i++){
        ans+=M[str[i]];
    }
    cout<<ans<<endl;
    return 0;
}
