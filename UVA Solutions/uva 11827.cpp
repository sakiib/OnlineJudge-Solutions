#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    cin.ignore();
    while(t--) {
        string str;
        getline(cin,str);
        stringstream iss(str);
        int ara[10010];
        int i=1,k;
        int cnt=1;
        while(iss>>k) {
            ara[i]=k;
            i++,cnt++;
        }
        cnt--;
        int mx=1;
        for(int i=1;i<=cnt;i++) {
            for(int j=i+1;j<=cnt;j++) {
                int val=__gcd(ara[i],ara[j]);
                mx=max(mx,val);
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
