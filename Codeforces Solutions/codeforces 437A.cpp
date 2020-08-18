#include<bits/stdc++.h>
using namespace std;

int len(string &str) {
    return str.size()-2;
}
int main(int argc,char const *argv[]) {
    string str[10];
    cin>>str[1]>>str[2]>>str[3]>>str[4];
    int ara[10];
    ara[1]=len(str[1]);
    ara[2]=len(str[2]);
    ara[3]=len(str[3]);
    ara[4]=len(str[4]);
    cerr<<ara[1]<<" "<<ara[2]<<" "<<ara[3]<<" "<<ara[4]<<endl;
    int choices=0,ans;
    for(int i=1;i<=4;i++) {
        int cnt=0;
        for(int j=1;j<=4;j++) {
            if(i!=j) {
                if(ara[i]<=ara[j]/2) cnt--;
                else if(ara[i]>=ara[j]*2) cnt++;
            }
        }
        if(cnt==3||cnt==-3) {
            choices++;
            cerr<<i<<endl;
            cerr<<cnt<<endl;
            ans=i;
            //cout<<(char)(i-1+'A')<<endl;
        }
    }
    cerr<<choices<<endl;
    if(choices==1) {
        cout<<(char)(ans-1+'A')<<endl;
    }
    else cout<<'C'<<endl;
    return 0;
}
