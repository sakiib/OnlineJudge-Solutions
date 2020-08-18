#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[1010];
    set<int> S;
    int zero=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        S.insert(ara[i]);
        if(ara[i]==0) zero++;
    }
    if((int)S.size()==1) {
        cout<<n<<endl; return 0;
    }
    for(int i=1;i<=n;i++) {
        int temp=1;
        for(int j=1;j<i;j++) {
            if(ara[j]==0) temp++;
        }
        for(int j=i+1;j<=n;j++) {
            if(ara[j]==1) {
                temp++;
            }
        }
        zero=max(zero,temp);
    }
    cout<<zero<<endl;
    return 0;
    /*100
    1 1 0 1 1 0 0 0 0 1 0 1 1 1 0 1 1 1 1 0 1 1 1 1 1 1 0
    1 1 0 0 1 1 1 0 0 0 1 0 0 1 0 1 1 0 1 0 0 1 0 0 1 1 0
    0 1 0 0 1 1 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0
    1 1 1 0 1 1 0 1 1 1 0 0 1 1 0 0 0 0 1*/
}
