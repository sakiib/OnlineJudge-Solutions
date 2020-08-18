#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    //cout<<setprecision(10)<<fixed;
    if(a==0&&b==0&&c==0){
        cout<<-1<<endl;
        return 0;
    }
    if(a==0&&b==0){
        cout<<-0<<endl;
        return 0;
    }
    if(a==0){
        cout<<1<<endl;
        cout<<setprecision(10)<<fixed<<-(1.0*c/b)<<endl;
        return 0;
    }

    long double root=(1.0*b*b-4.0*a*c);
    //cerr<<root<<endl;
    if(root<0){
        cout<<0<<endl;
        return 0;
    }
    long double r=sqrt(root);
    if(root==0){
        cout<<1<<endl;
        long double ans1=(-1.0*b)/(2.0*a);
        //cerr<<"here"<<endl;
        cout<<setprecision(10)<<fixed<<(ans1)<<endl;
        return 0;
    }
    cout<<2<<endl;
    long double ans1=(-1.0*b+r)/(2.0*a);
    long double ans2=(-1.0*b-r)/(2.0*a);

    cout<<setprecision(10)<<fixed<<min(ans1,ans2)<<endl;
    cout<<setprecision(10)<<fixed<<max(ans1,ans2)<<endl;
    return 0;

}
