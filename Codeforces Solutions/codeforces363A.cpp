#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10][1000]={"O-|-OOOO","O-|O-OOO","O-|OO-OO",
                "O-|OOO-O","O-|OOOO-","-O|-OOOO",
                "-O|O-OOO","-O|OO-OO","-O|OOO-O","-O|OOOO-"};
   long long int n,a;
   cin>>n;
   if(n==0){
    cout<<str[0]<<endl;
    return 0;
   }
   while(n>0){
     a=n%10;
     cout<<str[a]<<endl;
     n=n/10;
   }
   return 0;
}
