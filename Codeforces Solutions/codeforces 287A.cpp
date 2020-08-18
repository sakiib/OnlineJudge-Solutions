#include<bits/stdc++.h>
using namespace std;

int main(){
    char ara[5][5];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            cin>>ara[i][j];
        }
    }
    //memset(ara,'0',sizeof(ara));
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(ara[i][j]==ara[i+1][j]&&ara[i][j]==ara[i][j+1]
               &&ara[i+1][j]==ara[i+1][j+1]){
                cout<<"YES"<<endl;
                return 0;
               }
        }
    }
    for(int i=1;i<=3;i++){
            int white=0,black=0;
        for(int j=1;j<=3;j++){
            if(ara[i][j]=='#') black++;
            else if(ara[i][j]=='.') white++;
            if(ara[i+1][j]=='#') black++;
            else if(ara[i+1][j]=='.') white++;
            if(ara[i][j+1]=='#') black++;
            else if(ara[i][j+1]=='.') white++;
            if(ara[i+1][j+1]=='#') black++;
            else if(ara[i+1][j+1]=='.') white++;
            if((black==3&&white==1)||(black==1&&white==3)){
                cout<<"YES"<<endl;
                //cout<<i<<" "<<j<<endl;
                return 0;
            }
          white=0,black=0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
