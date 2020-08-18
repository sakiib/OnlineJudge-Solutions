#include<bits/stdc++.h>
using namespace std;

void solve(int n){

    vector<int> A;
    A.push_back(n);

    while(n!=1){

        for(int i=(n/2);i>=1;i--){
            if(n%i==0){
                A.push_back(i);
                n=i;
                break;
            }
        }
    }
    for(int i=0;i<A.size();i++){
        cout<<A[i]<< " ";
    }
    return;
}

int main(){

    int n;
    cin>>n;
    solve(n);
    return 0;
}
