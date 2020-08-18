#include<bits/stdc++.h>
using namespace std;

int top;
pair<int,int> P[1000];

void NO() {
    cout<<"NO"<<endl;
    exit(0);
}
void YES() {
    cout<<"YES"<<endl;
    exit(0);
}
int solve(int n) {
    for(int i=1;i<=n;i++) {
        if(P[i].first==top||P[i].second==top||
           P[i].first+P[i].second==7||(7-top==P[i].first)
           ||(7-top==P[i].second))  NO();
    }
    YES();
    return 0;
}

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    cin>>top;
    for(int i=1;i<=n;i++) {
        cin>>P[i].first>>P[i].second;
    }
    solve(n);
    return 0;
}
