#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        cin.ignore();
        vector<pair<int,int> > V;
        V.clear();
        for(int i=1;i<=n;i++) {
            string str;
            getline(cin,str);
            stringstream iss(str);
            string k;
            int cnt=0;
            while(iss>>k) {
                cnt++;
            }
            V.push_back(make_pair(cnt,i));
        }
        sort(V.begin(),V.end());
        vector<int> idx;
        idx.clear();
        int res=V[0].first;
        idx.push_back(V[0].second);
        for(int i=1;i<V.size();i++) {
            if(V[i].first==res) {
                idx.push_back(V[i].second);
            }
        }
        for(int i=0;i<idx.size();i++) {
            if(i==0) cout<<idx[i];
            else cout<<" "<<idx[i];
        }
        cout<<endl;
    }
    return 0;
}
