#include<bits/stdc++.h>
using namespace std;

double rec(int n) {
    if(n==0) return sqrt(2)+sqrt(3)+sqrt(6);
    else return (rec((n-1))*rec(n-1)-5)/(2*rec(n-1)+4);
}
int main(int argc,char const *argv[]) {
    string str;
    while(cin>>str) {
        if(str.size()==1) {
            char ch=str[0];
            int a=ch-'0';
            printf("%.10lf\n",rec(a));
        }
        else {
            int k=str[str.size()-1];
            if(k%2==0) printf("%.10lf\n",rec(4));
            else printf("%.10lf\n",rec(3));
        }
    }
    return 0;
}
