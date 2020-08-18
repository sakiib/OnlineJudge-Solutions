#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==1){
        cout<<"I hate it"<<endl;
        return 0;
    }
    for(int i=1;i<=n-1;i++){
        if(i%2==0) cout<<"I love that"<< " ";
        else cout<<"I hate that"<< " ";
    }
    if(n%2!=0){
        cout<<"I hate it"<<endl;
    }
    else cout<<"I love it"<<endl;

    return 0;
}
