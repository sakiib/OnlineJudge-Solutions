#include<bits/stdc++.h>
using namespace std;

int n,ara[100005],k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    freopen("sakib.txt", "r", stdin);
    freopen("nova.txt", "w", stdout);

    cin>>n;
    k=n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    while(k--){
        bool found=true;
        for(int i=0;i<n;i++){
            if(ara[i]!=i){
                found=false; break;
            }
        }
        if(found){
            cout<<"YES"<<endl;
            return 0;
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                ara[i]=(ara[i]+1)%n;
            }
            else ara[i]=(ara[i]+n-1)%n;
        }
    }
    cout<<"NO"<<endl;
    return 0;

}
