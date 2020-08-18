#include <bits/stdc++.h>
using namespace std;

int mn = 1000000000;
int r, c, i, j, a, b;

int main(int argc, char const *argv[]) {
    cin >> r >> c >> i >> j >> a >> b;
    int x1 = 1 , y1 = 1;
    int x2 = r , y2 = 1;
    int x3 = 1 , y3 = c;
    int x4 = r , y4 = c;
    if(abs(x1-i)%a!=0||abs(y1-j)%b!=0) {
        cout << "Poor Inna and pony!"<<endl;
        return 0;
    }
    if(abs(x2-i)%a!=0||abs(y2-j)%b!=0) {
        cout << "Poor Inna and pony!"<<endl;
        return 0;
    }
    if(abs(x3-i)%a!=0||abs(y3-j)%b!=0) {
        cout << "Poor Inna and pony!"<<endl;
        return 0;
    }
    if(abs(x4-i)%a!=0||abs(y4-j)%b!=0) {
        cout << "Poor Inna and pony!"<<endl;
        return 0;
    }
    if((abs(x1-i))%2 != (abs(y1-j%2))) {
        cout << "Poor Inna and pony!"<<endl;
        return 0;
    }
    if((abs(x2-i))%2 != (abs(y2-j))%2) {
        cout << "Poor Inna and pony!"<<endl;
        return 0;
    }
    if((abs(x3-i))%2 != (abs(y3-j))%2) {
        cout << "Poor Inna and pony!"<<endl;
        return 0;
    }
    if((abs(x4-i))%2 != (abs(y4-j))%2) {
        cout << "Poor Inna and pony!"<<endl;
        return 0;
    }
    int op1 = max(abs(x1-i)/a,abs(y1-j)/b);
    int op2 = max(abs(x2-i)/a,abs(y2-j)/b);
    int op3 = max(abs(x3-i)/a,abs(y3-j)/b);
    int op4 = max(abs(x4-i)/a,abs(y4-j)/b);
    cout << min(op1, min(op2, min(op3,op4))) <<endl;
    return 0;
}
