#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int ara[10];
        cin>>ara[0]>>ara[1]>>ara[2]>>ara[3];
        sort(ara,ara+4);
        if(ara[0]==ara[1]&&ara[1]==ara[2]&&ara[2]==ara[3])
            cout<<"square"<<endl;
        else if(ara[0]==ara[1]&&ara[2]==ara[3])
            cout<<"rectangle"<<endl;
        else if(ara[0]+ara[1]+ara[2]>=ara[3])
            cout<<"quadrangle"<<endl;
        else cout<<"banana"<<endl;
    }
    return 0;
}
