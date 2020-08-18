#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int ans=abs(a-b);
    if(ans==0) {
        cout<<1<<endl;
    }
    else if(ans<9) {
        cout<<9<<endl;
    }
    else {
        if(ans%10==9) {
            cout<<ans-1<<endl;
        }
        else cout<<ans+1<<endl;
    }
    return 0;
}
