#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int c,v0,v1,a,l,day=1;
    cin>>c>>v0>>v1>>a>>l;
    c=c-v0;
    v0=v0+a;
    v0=min(v0,v1);
    while(c>0) {
        c=c-v0+l;
        day++;
        v0=v0+a;
        v0=min(v0,v1);
    }
    cout<<day<<endl;
    return 0;
}
