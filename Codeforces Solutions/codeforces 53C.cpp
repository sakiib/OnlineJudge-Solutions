#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    vector<int> ans;
    ans.push_back(1);
    int hi=n;
    int lo=2;
    while(lo<=hi) {
        ans.push_back(hi);
        hi--;
        ans.push_back(lo);
        lo++;
    }
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
