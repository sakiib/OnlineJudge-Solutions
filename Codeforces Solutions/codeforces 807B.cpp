#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int p,x,y;

bool pseudo(int s){

    int a=(s/50)%475;

    for(int i=1;i<=25;i++){
        //i := (i * 96 + 42) mod 475
        a=(a*96 + 42)%475;
        if (a+26==p)
            return true;
    }
    return false;
}


int main(){

   // cout<<pseudo(7408)<<endl;

    cin>>p>>x>>y;
    int steps=0, minSteps=1e7;
    for(int i=0;i<=2000;i++){
        if (i%2==0){
            steps=i/2;
        }
        else {
            steps=(i+1)/2;
        }
        if (pseudo(i*50+x)){
            minSteps=min(steps,minSteps);
        }
    }

    for(int i=1;x-i*50>=y;i++){
        steps=0;
        if (pseudo(x- i*50)){
            cout<<"here\n";
            minSteps=min(steps,minSteps);
        }
    }

    cout<<minSteps<<endl;


}
