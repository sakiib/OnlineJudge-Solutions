#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string s;
    int count1=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        cout<<(s[i]-'0'+1)+'0';
    }

    return 0;
}
