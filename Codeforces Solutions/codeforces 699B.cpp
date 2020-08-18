#include<bits/stdc++.h>
using namespace std;
int row[100001]={0};
int col[100001]={0};
char ch[1005][1005];
int main()
{
    int n,m,cnt=0,sum;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>ch[i][j];
            if(ch[i][j]=='*'){
                cnt++; row[i]++; col[j]++;
            }
        }
    }
    //cout<<"cnt "<<cnt<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           sum=row[i]+col[j];
           //cout<<"sum: "<<sum<<endl;
           if(ch[i][j]=='*'){
            sum--;
           }
           if(sum==cnt){
            //cout<<"sum in:"<<sum<<endl;
            cout<<"YES"<<endl;
            cout<<i+1<< " " <<j+1<<endl;
            return 0;
           }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
