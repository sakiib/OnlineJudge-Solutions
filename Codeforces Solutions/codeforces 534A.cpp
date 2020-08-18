#include<bits/stdc++.h>
using namespace std;
void build(int x) {
    switch(x){
        case 1: cout<<1<<endl<<1<<endl;
        break;
        case 2: cout<<1<<endl<<1<<endl;
        break;
        case 3: cout<<2<<endl<<"1 3"<<endl;
        break;
    }
    exit(0);
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    if(n==1||n==2||n==3) {
        build(n);
    }
    vector<int> odd,even;
    for(int i=1;i<=n;i++) {
        if(i&1) odd.push_back(i);
        else even.push_back(i);
    }
    int ans;
    ans=odd.size()+even.size();
    sort(odd.rbegin(),odd.rend());
    sort(even.rbegin(),even.rend());
    cout<<ans<<endl;
    for(auto x:odd) {
        cout<<x<< " ";
    }
    for(auto x:even) {
        cout<<x<< " ";
    }
    return 0;
}
