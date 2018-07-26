 
#include <stdio.h>
#include <math.h>
int main()

{

int a, b, c, d, e, max, min;

scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

if (a > b&&a>c&&a>d&&a>e)

{

max = a;

 

}

else

{

if (b > a&&b > c&&b > d&&b > e)

{

max = b;

}

else

{

if (c > a&&c > b&&c > e&&c > d)

{

max = c;

}

else

{

if (d > a&&d > b&&d > c&&d > e)

{

max = d;

}

else

{

if (e > a&&e > b&&e > c&&e > d)

{

max = e;

}

}

}

}

}

if (a < b&&a<c&&a<d&&a<e)

{

min = a;

 

}

else

{

if (b < a&&b < c&&b < d&&b < e)

{

min = b;

}

else

{

if (c < a&&c < b&&c < e&&c < d)

{

min = c;

}

else

{

if (d < a&&d < b&&d < c&&d < e)

{

min = d;

}

else

{

if (e < a&&e < b&&e < c&&e < d)

{

min = e;

}

}

}

}

}

 

printf("%d %d", min,max);

 

}        