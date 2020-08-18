#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    int ara[100010];
    vector<int> V;
    priority_queue<int> PQ;
    for(int i=0;i<k;i++) {
        cin>>ara[i];
        V.push_back(ara[i]);
        PQ.push(ara[i]);
    }
    int mx=0;
    int p=n;
    bool done=false;
    while(!PQ.empty()) {
        int k=PQ.top();
        mx+=k; p--;
        PQ.pop();
        PQ.push(k-1);
        if(p==0) break;
    }
    int mn=0;
    int q=n;
    bool yes=false;
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++) {
        while(V[i]!=0) {
            mn+=V[i];
            V[i]--; q--;
            if(q==0) {
                yes=true; break;
            }
        }
        if(yes) break;
    }
    cout<<mx<<" "<<mn<<endl;
    return 0;
}
