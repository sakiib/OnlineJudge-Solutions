#include<bits/stdc++.h>

using namespace std ;


#define ll long long
#define N 20000005

vector<ll> prime ; /*Stores generated primes*/
char Isprime[N] ;  /*1 means prime*/
void Primesieve()
{
    memset(Isprime,1,sizeof(Isprime)) ;
    Isprime[0] = Isprime[1] = 0 ; /*0 and 1 are not prime*/
    Isprime[2] = 1 ;

    //prime.push_back(2) ; // /*Only Even Prime*/

    for(ll i= 4 ; i<=N; i += 2) /*Remove multiples of 2*/
    {
        Isprime[i] = 0 ;
    }

    ll sqrtn = sqrt(N) ;

    for(ll i=3 ; i<= sqrtn ; i+=2 )
    {
        if(Isprime[i] == 1 )
        {
            for(ll j=i*i ; j<N ; j+= 2* i )
            {
                Isprime[j] = 0 ;
            }
        }
    }

    for(ll i=3; i<N ; i+=2)
    {
        if(Isprime[i] && Isprime[i+2])
        {
            prime.push_back(i) ;
        }
    }
}


int main()
{
    prime.clear() ;
    Primesieve() ;
    int n , res ;
    while(scanf("%d",&n)!=EOF)
    {
        n = n-1 ;
        int a = prime[n] ;
        //int b = prime[n+1] ;
        printf("(%d, %d)\n",a,a+2) ;
    }

    return 0 ;
}
