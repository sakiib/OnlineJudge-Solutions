#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size()) {
        cout<<"NO"<<endl;
        return 0;
    }
    string c=a;
    string d=b;
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    if(c!=d) {
        cout<<"NO"<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<a.size();i++) {
        if(a[i]!=b[i]) cnt++;
    }
    if(cnt>2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
