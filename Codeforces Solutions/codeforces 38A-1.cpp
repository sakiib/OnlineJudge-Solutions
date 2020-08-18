#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[1000];
    ara[0]=0;
    for(int i=1;i<=n-1;i++) {
        int val;
        cin>>val;
        ara[i]=val;
    }
    for(int i=1;i<=n-1;i++) {
        ara[i]+=ara[i-1];
    }
    int from,to;
    cin>>from>>to;
    from--; to--;
    cout<<ara[to]-ara[from]<<endl;
    return 0;
}
