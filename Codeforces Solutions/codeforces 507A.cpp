#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    int ara[100010];
    vector<pair<int,int> > V;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        V.push_back({ara[i],i});
    }
    sort(V.begin(),V.end());
    int sum=0;
    vector<int> ans;
    for(int i=0;i<V.size();i++) {
        if(sum+V[i].first<=k) {
            sum+=V[i].first;
            ans.push_back(V[i].second);
        }
        else break;
    }
    if(ans.size()==0) {
        cout<<0<<endl; return 0;
    }
    cout<<ans.size()<<endl;
    for(auto &x:ans) {
        cout<<x<< " ";
    }
    return 0;
}
