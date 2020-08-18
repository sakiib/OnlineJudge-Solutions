#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mn1,mx1,mn2,mx2,mn3,mx3;
    cin>>n;
    cin>>mn1>>mx1;
    cin>>mn2>>mx2;
    cin>>mn3>>mx3;
    int sum=0;
    sum+=mn1+mn2+mn3;
    while(sum<n){
        while(mn1<mx1){
            mn1++;
            sum++;
            if(sum==n) break;
        }
        break;
    }

    while(sum<n){
        while(mn2<mx2){
            mn2++;
            sum++;
            if(sum==n) break;
        }
        break;
    }
    while(sum<n){
        while(mn3<mx3){
            mn3++;
            sum++;
            if(sum==n) break;
        }
        break;
    }
    cout<<mn1<< " "<<mn2<< " "<<mn3<<endl;
    return 0;
}
