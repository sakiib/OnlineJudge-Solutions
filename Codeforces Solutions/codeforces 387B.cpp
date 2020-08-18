#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    vector<int> a,b;
    map<int,int> M;

    for(int i=1;i<=n;i++) {
        int num;
        cin>>num;
        a.push_back(num);
    }
    int cnt=0;
    for(int i=1;i<=m;i++) {
        int num;
        cin>>num;
        if(a[cnt]<=num&&cnt<n) cnt++;
    }
    cout<<n-cnt<<endl;
    return 0;
}
