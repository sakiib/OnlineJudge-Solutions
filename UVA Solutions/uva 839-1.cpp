#include<bits/stdc++.h>
using namespace std;

bool ok;

int w1,d1,w2,d2;

int solve() {
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    if(w1==0&&w2==0) {
        return (w1+w2);
    }
    else {
        if(w1*d1!=w2*d2) {
            ok=false;
        }
        else {
            return (w1*d1+w2*d2);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    for(int tc=1;tc<=t;tc++){
        ok=false;
        solve();
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(tc!=t) printf("\n");
    }
    return 0;
}
