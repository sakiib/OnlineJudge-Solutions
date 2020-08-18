#include<bits/stdc++.h>
using namespace std;

int cnt;

int rec(int sum) {
    int val=0;
    //cerr<<sum<<endl;
    if(sum<9) return -100;
    if(sum==9) return 1;
    while(sum!=0) {
        val+=(sum%10);
        sum/=10;
    }
    return 1+rec(val);
}
int main(int argc,char const *argv[]) {
    string str;
    int t=1;
    for(t=1; ;t++) {
        cin>>str;
        if(str[0]-'0'==0) break;
        //cout<<str.size();
        int sum=0;
        for(auto c:str) sum+=(c-'0');
        int ans=rec(sum);
        //cout<<"ans : "<<ans<<endl;
        if(ans>0)
        cout<<str<<" is a multiple of 9 and has 9-degree "<<ans<<"."<<endl;
        else cout<<str<<" is not a multiple of 9."<<endl;
    }
    return 0;
}
