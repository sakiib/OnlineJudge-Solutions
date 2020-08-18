#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,msize,limit,oran,sum=0,count=0;
    cin>>n>>msize>>limit;
    while(n--){
        cin>>oran;
        if(oran>msize) continue;
        else{
            sum+=oran;
            if(sum>limit){
                sum=0;
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}

