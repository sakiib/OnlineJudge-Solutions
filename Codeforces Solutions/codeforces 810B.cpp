#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    int n,f;
    cin>>n>>f;

    long long sales=0;
    vector<int> gain(n);

    for (int i=0; i<n; i++)
    {
        int k,l;
        cin>>k>>l;

        int cur=min(k,l);
        int pos=min(2*k,l);

        sales+=cur;
        gain[i]=pos-cur;
        cout<<pos-cur<<endl;
    }
    cout<<endl;
    sort(gain.rbegin(),gain.rend());
    for(int i=0;i<gain.size();i++){
        cout<<gain[i]<< " ";
    }
    for (int i=0; i<f; i++)
        sales+=gain[i];

  //  cout<<sales;
}
