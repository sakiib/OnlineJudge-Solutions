#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        int ans=0;
        while(a>0&&b>0) {
            if(a>b) swap(a,b);
            if(a==b) {ans++; break;}
            int temp=b/a;
            ans+=temp;
            temp*=a;
            b-=temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
