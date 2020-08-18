#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    int f[10001],s[10001],t[10001],l[10001];
    f[1]=1,s[1]=2,t[1]=3,l[2]=4;
    for(int i=2;i<=1000;i++){
        f[i]=f[i-1]+4;
        s[i]=s[i-1]+4;
        t[i]=t[i-1]+4;
    }
    for(int i=3;i<=100;i++){
        l[i]=l[i-1]+4;
    }
    cin>>x>>y;
    if((x==0&&y==0)||(x==1&&y==0)){
        cout<<0<<endl;
        return 0;
    }
    if(x>0&&y>0){
        cout<<f[x]<<endl;
    }
    else if(x<0&&y>0){
        cout<<s[-(x)]<<endl;
    }
    else if(x<0&&y<0){
        cout<<t[-(x)]<<endl;
    }
    else if(x>0&&y<0){
        cout<<l[x]<<endl;
    }
    return 0;
}
