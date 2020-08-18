#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc,char const *argv[]) {
    int ways;
    cin>>ways;
    if(ways==1) {
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<2<<endl;
    }
    else {
        cout<<2*ways-2<<" "<<2<<endl;
        cout<<1<<" "<<2<<endl;
    }
    return 0;
}
