#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define PI (2*acos(0.0))
int main()
{
    int n,p,c = 0;
    long long a = 1;
    string s;
    stack<int> st;
    scanf("%d %d",&n,&p);
    getchar();
    for(int i=0;i<n-1;i++)
    {
        getline(cin,s);
        if(s.length()==4)
        {
            st.push(0);
        }
        else
        {
            st.push(1);
            c++;
        }
    }
    getline(cin,s);
    c++;
    while(!st.empty())
    {
        a = (a*2) + st.top();
        st.pop();
        cout<<a<<endl;
    }
   // cout << (a*p) - (c*p/2);
    return 0;
}
