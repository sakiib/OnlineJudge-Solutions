#include<bits/stdc++.h>
using namespace std;
vector<int> V;
void print_seq()
{
    for(int i=0;i<V.size();i++){
        cout<<V[i]<< " ";
    }
}
int rec(int n)
{
    if(n==1) print_seq();
    else if(n%2==0){
        n=n/2;
        V.push_back(n);
        rec(n);
    }
    else{
        n=(3*n+1);
        V.push_back(n);
        rec(n);
    }
}
int main()
{
    int n,ans;
    cin>>n;
    V.push_back(n);
    rec(n);
}
