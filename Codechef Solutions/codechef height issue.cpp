#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> ans;
        ans.clear();
        int ara[100010];
        ans.push_back(1);
        for(int i=1;i<=n;i++) {
            cin>>ara[i];
        }
        for(int i=2;i<=n;i++) {
            int cnt=0;
            for(int j=i;j>=1;j--) {
                if(ara[i]>=ara[j]) cnt++;
                else {
                    ans.push_back(cnt);
                    cnt=0;
                    break;
                }
            }
            if(cnt!=0) ans.push_back(cnt);
        }
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<< " ";
        }
        cout<<endl;
    }
    return 0;
}
