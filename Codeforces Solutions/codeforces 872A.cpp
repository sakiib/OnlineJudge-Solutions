#include<bits/stdc++.h>
using namespace std;

int cnt[10];

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    vector<int> a,b,c;

    for(int i=1;i<=n;i++) {
        int num;
        cin>>num;
        a.push_back(num);
        cnt[num]++;
    }
    for(int i=1;i<=m;i++) {
        int num;
        cin>>num;
        b.push_back(num);
        cnt[num]++;
        if(cnt[num]==2) c.push_back(num);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(c.size()!=0) {
        sort(c.begin(),c.end());
        cout<<c[0]<<endl;
        return 0;
    }
    int x=a[0]*10+b[0];
    int y=b[0]*10+a[0];
    cout<<min(x,y)<<endl;
    return 0;
}
