#include<bits/stdc++.h>
using namespace std;
string process(string &str) {
    string ret="";
    for(int i=0;i<str.size();i++) {
        if(str[i]!=' ') ret+=str[i];
    }
    for(int i=0;i<ret.size();i++) {
        if(ret[i]>='a'&&ret[i]<='z') ret[i]-=32;
    }
    sort(ret.begin(),ret.end());
    return ret;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    getchar();
    for(tc=1;tc<=t;tc++) {
        string a,b;
        getline(cin,a);
        getline(cin,b);
        string x=process(a);
        string y=process(b);
        if(x==y) printf("Case %d: Yes\n",tc);
        else printf("Case %d: No\n",tc);
    }
    return 0;
}
