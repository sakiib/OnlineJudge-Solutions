#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    bool done=false;
    while(true) {
        for(int i=1;i<=n;i++) {
           if(m>=i) m-=i;
           else {
            done=true; break;
           }
        }
        if(done) break;
    }
    cout<<m<<endl;
    return 0;
}
