#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    vector<int> ans;
    while(n) {
        int p=1,m=0,k;
        k=n;
        while(k) {
            if(k%10!=0) m+=p;
            k/=10; p*=10;
        }
        cerr<<m<<endl;
        ans.push_back(m);
        n-=m;
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto &x : ans) cout<<x<< " ";
    return 0;
}
