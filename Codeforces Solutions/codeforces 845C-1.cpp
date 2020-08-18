#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    vector<pair<int,int> > V;
    for(int i=1;i<=n;i++) {
        int st,en;
        cin>>st>>en;
        V.push_back({st,en});
    }
    sort(V.begin(),V.end());
    int s=V[0].first;
    int e=V[0].second;
    int cnt=1;
    for(int i=1;i<V.size();i++) {
        if(V[i].first<=e) {
            cnt++;
            if(cnt>2) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else {
            cnt=1;
            s=V[i].first;
            e=V[i].second;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
