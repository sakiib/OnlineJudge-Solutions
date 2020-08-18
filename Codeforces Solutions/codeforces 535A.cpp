#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    char beep[21][1000]={"zero","one","two","three","four","five",
                       "six","seven","eight","nine","ten","eleven",
                       "twelve","thirteen","fourteen","fifteen","sixteen",
                       "seventeen","eighteen","nineteen","twenty"};
    while(cin>>n){

    if(n==30) cout<<"thirty";
    if(n==40) cout<<"forty";
    if(n==50) cout<<"fifty";
    if(n==60) cout<<"sixty";
    if(n==70) cout<<"seventy";
    if(n==80) cout<<"eighty";
    if(n==90) cout<<"ninety";

    if(n<=20){
        cout<<beep[n];
    }
    else if(n>20&&n<30){
        cout<<"twenty-"<<beep[n%10];
    }
    else if(n>30&&n<40){
        cout<<"thirty-"<<beep[n%10];
    }
    else if(n>40&&n<50){
        cout<<"forty-"<<beep[n%10];
    }
    else if(n>50&&n<60){
        cout<<"fifty-"<<beep[n%10];
    }
    else if(n>60&&n<70){
        cout<<"sixty-"<<beep[n%10];
    }
    else if(n>70&&n<80){
        cout<<"seventy-"<<beep[n%10];
    }
    else if(n>80&&n<90){
        cout<<"eighty-"<<beep[n%10];
    }
    else if(n>90&&n<=99){
        cout<<"ninety-"<<beep[n%10];
    }
    }
    return 0;
}
