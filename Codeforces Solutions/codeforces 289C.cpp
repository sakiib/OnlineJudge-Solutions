#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    if(n<k||(k==1&&n>1)){
        cout<<-1<<endl;
        return 0;
    }
    if(n==1&&k==1){
        cout<<"a"<<endl;
        return 0;
    }
    for(int i=0;i<n-k+2;i++){
        if(i%2==0) cout<<"a";
        else cout<<"b";

    }
    char ch='c';
    for(int i=n-k+2;i<n;i++){
        putchar(ch);
        ch++;
    }
    return 0;
}
