#include<bits/stdc++.h>
using namespace std;

int sum,n;
int ara[100010];
vector<int> V;

void solve(int i,int cur) {
    if(i==n+1) return;
    if(cur==sum) {
        cout<<"sum : "<<sum<<endl;
        V.push_back(ara[i]);
        return;
    }
}
int main(int argc,char const *argv[]) {
    cin>>sum;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    solve(0,0);
    for(int i=0;i<V.size();i++) {
        cout<<V[i]<<" ";
    }
    cout<<endl;
    return 0;
}
