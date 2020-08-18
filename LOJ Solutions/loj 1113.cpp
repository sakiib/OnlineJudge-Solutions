#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
 {

    int tc, ct = 1;
    char str[200];
    char url[500][1000];
    int in, high;
    char home[] = "http://www.lightoj.com/";
    scanf("%d", &tc);

    while( tc-- ) {

        in = 0;
        high = 0;
        strcpy(url[in],home);

        printf("Case %d:\n",ct++ );

        while( 1 ) {
        scanf("%s", str );
        if(strcmp(str,"VISIT" )== 0 )
        {
            in++;
            high = in;

            scanf("%s", str );
            strcpy(url[in], str );

            printf("%s\n",str );
        }
        else if ( strcmp( str, "BACK" )== 0 ) {

            if(in == 0) printf("Ignored\n");
            else {

                in--;
                printf("%s\n",url[in] );
            }
        }
        else if( strcmp("FORWARD", str ) == 0 ) {

            if(in == high )
                printf("Ignored\n");
            else {

                in++;
                printf("%s\n",url[in]);
            }
        }
          else
            break;

        }

    }
    return 0;
}
