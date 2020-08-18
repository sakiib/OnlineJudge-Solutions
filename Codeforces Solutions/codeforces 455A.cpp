#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    map<int,int> M;
    int ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        M[ara[i]]++;
    }
    vector<pair<int,int> > V;
    map<int,bool> done;
    for(int i=1;i<=n;i++) {
        int val=M[ara[i]+1]+M[ara[i]-1];
        if(!done[ara[i]]) {
            done[ara[i]]=true;
            V.push_back({val,ara[i]});
        }
    }
    sort(V.begin(),V.end());
    for(auto &x:V) {
        cout<<x.first<< " " <<x.second<<endl;
    }
}
