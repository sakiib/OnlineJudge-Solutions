#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string a,b;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--) {
        if(a[i]=='z'&&b[i]!='z') a[i]='a';
        else if(a[i]==b[i]) continue;
        else {a[i]++; break;}
    }
    cerr<<a<<endl;
    if(a<b) cout<<a<<endl;
    else cout<<"No such string"<<endl;
    return 0;
}
