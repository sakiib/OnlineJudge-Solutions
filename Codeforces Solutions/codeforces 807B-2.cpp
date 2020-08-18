#include<bits/stdc++.h>
using namespace std;

bool check(int num,int p)
{
   num=(num/50)%475;
   for(int i=0;i<25;i++){
     num=(num*96+42)%475;
     if(num+26==p) return true;
   }
   return false;
}
int main()
{
    int p,x,y;
    cin>>p>>x>>y;
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            if(x+100*i-50*j>=y){
                if(check(x+100*i-50*j,p)){
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
