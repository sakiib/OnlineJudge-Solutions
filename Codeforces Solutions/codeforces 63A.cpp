#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    vector< pair<int,string> > V;
    cin>>n;

    for(int i=0;i<n;i++) {
        string a,b;
        cin>>a>>b;
        if(b=="rat")     V.push_back({1,a});
        if(b=="woman")   V.push_back({2,a});
        if(b=="child")   V.push_back({2,a});
        if(b=="man")     V.push_back({3,a});
        if(b=="captain") V.push_back({4,a});
    }
    int track=1;
    while(true) {

        for(int i=0;i<V.size();i++) {
            if(V[i].first==track) {
                cout<<V[i].second<<endl;
            }
        }
        track++;
        if(track==5) break;
    }
    return 0;
}
