#include<bits/stdc++.h>
using namespace std;

bool bob=false;
bool limak=false;

int main()
{
    int t,l=0,m=0,i=1,j=2,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        bob=false;
        limak=false;
        i=1,j=2;
        while(1){
           a-=i;
           if(a<0){
            bob=true; break;
           }
           i+=2;
           b-=j;
           if(b<0){
            limak=true;
            break;
           }
           j+=2;
        }
        if(limak) puts("Limak");
        else if(bob) puts("Bob");
    }
    return 0;
}
