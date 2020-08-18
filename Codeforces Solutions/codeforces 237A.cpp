#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    pair<int,int> P[100010];
    for(int i=1;i<=n;i++) {
        cin>>P[i].first>>P[i].second;
    }
    int sum=0;
    int mx=1;
    P[0].first=P[1].first; P[0].second=P[1].second;
    for(int i=1;i<=n;i++) {
        if(P[i].first==P[i-1].first&&P[i].second==P[i-1].second) {
            sum++;
            mx=max(mx,sum);
        }
        else {
            sum=1;
        }
    }
    mx=max(mx,sum);
    cout<<mx<<endl;
    return 0;
}
