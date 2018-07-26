 
#include <stdio.h>
main()
{
    int m,n;
    int tmp;
    int i;
    while( scanf( "%d%d", &m, &n ) !=EOF )
    {
        if( m > n )
        {
            tmp = m;
            m = n;
            n = tmp;
        }
        for( i = m; i <=n; i++ )
        {
            if( i % 3 == 0 )
            {
                break;
            }
        }
        for( ; i <= n; )
        {
            printf( "%d ", i );
            i = i + 3;
        }
        printf( "\n" );
    }
}        