#include<bits/stdc++.h>
using namespace std;

int ara[10000];

int main(int argc,char const *argv[]) {
    int n,a;
    cin>>n>>a;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    int l=a,r=a;
    int sum=0;
    while(l>=1&&r<=n) {
        if(l==r) sum+=ara[l];
        else if(ara[l]==1&&ara[r]==1) sum+=2;
        l--,r++;
    }
    if(l==0&&r==(n+1)) {
        cout<<sum<<endl;
        return 0;
    }
    if(l==0) {
        for(int i=r;i<=n;i++) {
            sum+=ara[i];
        }
        cout<<sum<<endl;
        return 0;
    }
    if(r==n+1) {
        for(int i=l;i>=1;i--) {
            sum+=ara[i];
        }
        cout<<sum<<endl;
        return 0;
    }
    return 0;
}
