#include<bits/stdc++.h>
using namespace std;

bool used[1000010];

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    vector<int> ans;
    int x=(n-k);
    for(int i=1;i<=x;i++) {
        ans.push_back(i);
    }
    int hi=n,lo=x+1;
    while(lo<=hi) {
        ans.push_back(hi);
        hi--;
        ans.push_back(lo);
        lo++;
    }
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
