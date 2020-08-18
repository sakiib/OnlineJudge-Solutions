#include<bits/stdc++.h>
using namespace std;
bool flag=false;
int main()
{
    int n,m,t=0,ans=0,num;
    scanf("%d%d",&n,&m);
    while(n--){
        while(t<m){
                flag=false;
            for(int i=0;i<2;i++){
                scanf("%d",&num);
                if(num==1&&!flag){
                    ans++; flag=true;
                }
            }
            t++;
        }
        t=0;
    }
    printf("%d\n",ans);
    return 0;
}
