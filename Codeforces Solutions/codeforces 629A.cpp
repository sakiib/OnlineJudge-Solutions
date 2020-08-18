#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[105][105];
    int n,cntr=0,cntc=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>str[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(str[i][j]=='C'){
                cntr++;
            }
            if(str[j][i]=='C'){
                cntc++;
            }
        }
        sum+=(cntr*(cntr-1)/2);//Same nC2=n*(n-1)/2;
        sum+=(cntc*(cntc-1)/2);
        cntr=0;
        cntc=0;
    }
    cout<<sum<<endl;
    return 0;
}
