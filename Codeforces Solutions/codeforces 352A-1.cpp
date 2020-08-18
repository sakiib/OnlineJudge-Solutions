#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    int f=0,z=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        if(ara[i]==5) f++;
        else z++;
    }
    if(f<9&&z>0) {
        cout<<0<<endl;
        return 0;
    }
    if(f>=9&&z>=1) {
        f/=9;
        string s="555555555";
        while(f--) {
            cout<<s;
        }
        while(z--) {
            cout<<0;
        }
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}
