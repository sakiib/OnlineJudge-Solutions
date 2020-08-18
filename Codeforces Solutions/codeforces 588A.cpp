#include<bits/stdc++.h>
using namespace std;
bool found=false;
int main()
{
    long long int n,a[100001]={0},b[100001]={0},mn,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    mn=b[0];
    b[n]=100000;
    sum+=a[0]*b[0];
    for(int i=1;i<n;i++){
        if(b[i]<mn){
            mn=b[i];
            sum+=a[i]*mn;
        }
        else{
            sum+=a[i]*mn;
        }
    }
    cout<<sum;
    return 0;
}
