#include<bits/stdc++.h>
using namespace std ;

int tracks[21] ;
int s[21] ;
int arr[21] ;
int limit ,N ;
int Count = 0 ;

long long Max = LLONG_MIN;

long long Maxi( long  a , long b )
{
    if( (a >= b) && ( a <= N) )
    {
        return a ;
    }

    else
    {
        return b ;
    }
}
void  subset (int Size , int index )
{
    long long sum = 0;
    if( limit < index)
    {
        for(int i =0 ; i<= Size-1 ; i++)
        {
            sum += s[i] ;
        }

        Max = Maxi(sum , Max) ;


        if( sum == Max)
        {
            for(int i =0 ; i<= Size-1 ; i++)
            {
                arr[i] = s[i] ;
                Count = Size-1;
            }
        }

        return ;
    }

    s[index] = tracks[index] ;

    subset( Size+1  , index +1 ) ;
    subset ( Size , index+1  ) ;
}
int main()
{
    int  n ;

    while(scanf("%d",&N) ==1 )
    {
        cin >> n ;

        tracks[n] ;
        limit = n-1 ;

        for(int i = 0 ; i<n ; i++ )
        {
            cin >> tracks[i] ;
        }

        subset(0,0) ;

        for(int i = 0 ; i<=Count ; i++)
        {
            cout << arr[i] <<" ";

        }

        cout <<"sum : " << Max << endl ;
    }

    return 0 ;
}
