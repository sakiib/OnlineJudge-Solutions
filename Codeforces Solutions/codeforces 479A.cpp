#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int a,b,c;
    cin>>a>>b>>c;
    int a1=a+b+c;
    int a2=a*b*c;
    int a3=(a+b)*c;
    int a4=a*(b+c);
    int a5=(a*b)+c;
    int a6=a+(b*c);
    cout<<max(a1,max(a2,max(a3,max(a4,max(a5,a6)))));
    return 0;
}
