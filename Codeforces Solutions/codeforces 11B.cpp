#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    if(n==0) {
        cout<<0<<endl; return 0;
    }
    if(n<0) n*=(-1);
    int i=1;
    while(true) {
        if(i*(i+1)/2>=n) break;
        else i++;
    }
    while(true) {
        if(((i*(i+1)/2)-n)%2==0) break;
        else i++;
    }
    cout<<i<<endl;
    return 0;
}
