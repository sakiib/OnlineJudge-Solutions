#include<bits/stdc++.h>
using namespace std;

map<string,bool> sec;
map<string,string> M;
vector<string> orig;
vector<pair<string,string> > V;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    string old[1000],ne[1000];
    for(int i=1;i<=n;i++) {

        cin>>old[i]>>ne[i];
        if(!sec[old[i]]) {

            V.push_back(make_pair(old[i],ne[i]));
            orig.push_back(old[i]);
        }
        sec[ne[i]]=true;
    }
    for(int j=0;j<V.size();j++) {
        string track=V[j].second;
        for(int i=1;i<=n;i++) {
            if(track==old[i]) {
                track=ne[i];
            }
        }
        V[j].second=track;
    }
    cout<<V.size()<<endl;
    for(int i=0;i<V.size();i++) {
        cout<<V[i].first<< " " <<V[i].second<<endl;
    }
    return 0;
}
