#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    int ara[1000];
    bool check[1000];
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    int cnt=0;
    bool found=false;
    while(true) {
        memset(check,false,sizeof(check));
        found=false;
        for(int i=0;i<n;i++) {
            if(ara[i]!=k&&!check[ara[i]]){
                check[ara[i]]=true;
                ara[i]++;
                found=true;
            }

        }
        /*(for(int i=0;i<n;i++) {
            cout<<ara[i]<< " ";
        }
        cout<<endl;*/
        if(!found) break;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
