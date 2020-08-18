#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int a,b;
    cin>>a>>b;
    int ans=a;
    int left=0;
    while(a>=b) {
        ans+=(a/b);
        left=a%b;
        a/=b;
        a+=left;
        cerr<<a<<" "<<left<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
