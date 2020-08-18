#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#include<stack>
#define pi acos(-1)
#define mod 1000000007
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;
int main()
{
    ll n,ara[200001],i,j=0,ara2[200001],count=1;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> ara[i];
    }
   sort(ara,ara+n);
   for(i=0;i<n-1;i++){
    ara2[j]=abs(ara[i+1]-ara[i]);
    j++;
   }
   sort(ara2,ara2+n-1);
   j=0;
   while(ara2[j]==ara2[j+1]){
    count++;
    j++;
   }
   cout << ara2[0] << " " << count << endl;
   return 0;
}


