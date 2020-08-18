#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int ara[5];
    for(int i=1;i<=4;i++) {
        cin>>ara[i];
    }
    sort(ara+1,ara+4+1);
    if(ara[1]+ara[2]>ara[3]&&ara[1]+ara[3]>ara[2]&&ara[2]+ara[3]>ara[1]){
        cout<<"TRIANGLE"<<endl;
        return 0;
    }
    if(ara[2]+ara[3]>ara[4]&&ara[2]+ara[4]>ara[3]&&ara[3]+ara[4]>ara[2]){
        cout<<"TRIANGLE"<<endl;
        return 0;
    }
    if(ara[1]+ara[2]==ara[3]||ara[1]+ara[2]==ara[4]||ara[2]+ara[3]==ara[4]) {
        cout<<"SEGMENT"<<endl;
        return 0;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
