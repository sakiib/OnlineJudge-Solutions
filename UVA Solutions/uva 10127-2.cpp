#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    int temp=10;
    int ans=1;
    int a=1;
    while(scanf("%d",&n)!=EOF) {
        a=1,ans=1,temp=10;
        while(a%n!=0) {
           a=((a%n*temp%n)%n+1)%n;
           ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
