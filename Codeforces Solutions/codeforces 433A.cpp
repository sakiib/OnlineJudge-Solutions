#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    int sum=0,one=0,two=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        if(ara[i]==100) one++;
        else two++;
        sum+=ara[i];
    }
    sum/=2;
    for(int i=0;i<=one;i++) {
        for(int j=0;j<=two;j++) {
            if(i*100+j*200==sum) {
                cout<<"YES"<<endl; return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
