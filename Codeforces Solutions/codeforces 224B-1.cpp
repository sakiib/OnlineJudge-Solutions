#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k,ara[100010];
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    set<int> S;
    S.clear();
    int from=0,to;
    bool found=false;
    for(int i=1;i<=n;i++) {
        S.insert(ara[i]);
        if(S.size()==k) {
            to=i;
            found=true;
            break;
        }
    }
    if(!found) {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    for(auto &it : S) {
        from++;
        S.erase(it);
        cerr<<it<<endl;
        if(S.size()==0) break;
    }
    cout<<from-1<< " " <<to<<endl;
    return 0;
}
