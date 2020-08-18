#include<bits/stdc++.h>
using namespace std;

vector<int> V[100010];

int main(int argc,char const *argv[]) {
    int e;
    cin>>e;
    for(int i=0;i<e;i++) {
        int n;
        cin>>n;
        while(n--) {
            int f;
            cin>>f;
            V[i].push_back(f);
            V[f].push_back(i);
        }
    }
    int q;
    cin>>q;
    while(q--) {
        int st;
        cin>>st;
    }
    return 0;
}


