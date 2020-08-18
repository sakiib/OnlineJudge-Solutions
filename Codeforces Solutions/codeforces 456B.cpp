#include<bits/stdc++.h>
using namespace std;

int PHI(string &str) {
    if(str.size()<2) {
        int k=str[0]-'0';
        k%=4;
        return k;
    }
    int temp=0;
    for(int i=0;i<str.size();i++) {
        temp=(temp*10+(str[i]-'0'))%4;
    }
    return temp;
}
int power(int x,int y) {
    int ret=1;
    for(int i=1;i<=y;i++) {
        ret*=x;
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    int n=PHI(str);
    cerr<<n<<endl;
    int ans=1+power(2,n)+power(3,n)+power(4,n);
    cout<<(ans%5)<<endl;
    return 0;
}
