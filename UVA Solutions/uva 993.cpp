#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        bool nai=false;
        string ans="";
        while(n>=10&&!nai) {
            int prev=n;
            for(int i=9;i>=2;i--) {
                if(n%i==0) {
                    ans+=(i+'0');
                    n/=i;
                    break;
                }
            }
            if(prev==n) {nai=true; break;}
        }
        if(nai) cout<<"-1"<<endl;
        else {
            reverse(ans.begin(),ans.end());
            cout<<n<<ans<<endl;
        }
    }
    return 0;
}
