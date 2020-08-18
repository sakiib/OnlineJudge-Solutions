#include<bits/stdc++.h>
using namespace std;
int ara[100001];
int ev,od;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ara[i]);
        if(ara[i]%2==0) ev++;
        else od++;
    }
    if(ev>od){
        for(int i=0;i<n;i++){
            if(ara[i]%2!=0){
                printf("%d",i+1);
                return 0;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(ara[i]%2==0){
                printf("%d",i+1);
                return 0;
            }
        }
    }
}
