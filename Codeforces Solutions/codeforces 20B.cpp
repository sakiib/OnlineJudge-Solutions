#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,root;
    double one,two;
    cin>>a>>b>>c;
    if(a==b&&b==0&&c==0){
        cout<<-1<<endl;
        return 0;
    }
    if(a==0&&b==0){
        cout<<0<<endl;
        return 0;
    }
    setprecision(10);
    if(a==0){
        cout<<1<<endl;
        cout<<fixed<<-c*1.0/b<<endl;
        return 0;
    }
    root=b*b-4*a*c;
    if(root<0){
        cout<<0<<endl;
        return 0;
    }
    one=(-b+sqrt(1.0*root))/(2.0*a);
    two=(-b-sqrt(1.0*root))/(2.0*a);

    if(one==two){
        cout<<1<<endl;
        cout<<fixed<<one<<endl;
    return 0;
    }
    cout<<2<<endl;
    cout<<fixed<<min(one,two)<<endl;
    cout<<fixed<<max(one,two)<<endl;
    return 0;
}
