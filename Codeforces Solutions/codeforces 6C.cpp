#include<bits/stdc++.h>
using namespace std;

int A=0,B=0;
int ara[100010];
int lef[100010]={0};
int righ[100010]={0};

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    for(int i=1;i<=n;i++) {
        lef[i]+=(lef[i-1]+ara[i]);
    }
    for(int i=n;i>=1;i--) {
        righ[i]+=(righ[i+1]+ara[i]);
    }
    /*for(int i=1;i<=n;i++) {
        cout<<lef[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++) {
        cout<<righ[i]<<" ";
    }*/
    for(int i=1;i<=n;i++) {
        if(lef[i]<=righ[i]) A++;
        else B++;
    }
    cout<<A<<" "<<B<<endl;
    return 0;
}
