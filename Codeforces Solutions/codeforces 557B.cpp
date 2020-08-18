#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    int n,ara[200005],t;
    cin>>n>>t;

    for(int i=0;i<2*n;i++){
        cin>>ara[i];
    }
    sort(ara,ara+2*n);
   /* for(int i=0;i<2*n;i++){
        cout<<ara[i]<< " ";
    }*/
    double low=0.0,high=t*1.0,mid;

    while((high-low)>=0.000001){

        bool girl=true,boy=true;

        mid=(low+high)/2.0;

        for(int i=0;i<n;i++){
            if((double)(ara[i])>=mid) continue;
            else {
                //cout<<"here"<< " ";
                girl=false; break;
            }
        }
        if(girl){
            for(int i=n;i<2*n;i++){
                if((double)(ara[i])>=(2.0*mid)) continue;
                else{
                   // cout<<"There"<< " ";
                    boy=false; break;
                }
            }
        }
        if(boy&&girl&&((mid*n*1.0)+(mid*2.0)*(1.0*n))<=t) low=mid;
        else high=mid;

       // cout<<low<< " " <<high<<endl;
    }
    cout<<setprecision(4);
    cout<<fixed<<(mid*n*1.0)+(mid*2.0)*(1.0*n)<<endl;
    return 0;
}
