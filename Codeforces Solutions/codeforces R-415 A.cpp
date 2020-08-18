#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,sum=0,num;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>num;
        sum+=num;
    }
    if(1.0*sum/n>=(1.0*k-0.5)){
        cout<<0;
        return 0;
    }
    double vag=0.5;
    double x=1.0*n*(k-vag);
    double z=x-1.0*sum;
    cout<<(int)(z/vag);

}
