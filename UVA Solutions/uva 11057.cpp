#include<bits/stdc++.h>
using namespace std;

int n;
int ara[10010];
int sum;
int mn=100000;
vector<int> V;
int x=-1,y=-1;
vector<vector<int> > ans;

void solve(int i,int t,int cur) {
    cerr<<"i - t - cur : "<<i<<" "<<t<<" "<<cur<<endl;
    if(i==n+1) return;
    if(t>2) return;
    if(cur==sum) {
        cout<<"print : "<<endl;
        ans.push_back(V);
        return;
    }
    else if(ara[i]+cur<=sum) {
        V.push_back(ara[i]);
        solve(i+1,t+1,cur+ara[i]);
        V.clear();
    }
    solve(i+1,t,cur);
}
int main(int argc,char const *argv[]) {
    while(scanf("%d",&n)!=EOF) {
        for(int i=1;i<=n;i++) {
            cin>>ara[i];
        }
        cin>>sum;
        solve(1,0,0);
        for(int i=0;i<ans.size();i++) {
            vector<int> a=ans[i];
            cerr<<"here"<<endl;
            for(int j=0;j<a.size();j++) {
                cout<<a[j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
