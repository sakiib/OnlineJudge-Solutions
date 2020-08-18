#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define SIZE 1000005
ll ara[SIZE];

int main()
{
    ll n,count=0;
    double sum_1=0.0,sum_2=0.0,ans,c1,c2;

    cin>>n>>c1>>c2;

    if(c1<c2){
        swap(c1,c2);
    }

    //cout<<c1<< " " <<c2<<endl;;

    for(int i=0;i<n;i++){

        cin>>ara[i];
    }

    sort(ara,ara+n);

    for(int i=n-1;i>=0;i--){

         sum_1+=ara[i];ara[i]=0;count++;
         if(count==c2) break;
    }

    count=0;
    for(int i=n-1;i>=0;i--){

        if(ara[i]!=0){
            sum_2+=ara[i]; count++;
            if(count==c1) break;
        }
    }

    //cout<<sum_1 << " " <<sum_2<<endl;

    ans=(sum_1/(double)c2)+(sum_2/(double)c1);
    cout<<setprecision(8)<<ans<<endl;

    return 0;

}
