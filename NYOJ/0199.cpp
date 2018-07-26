 
#include <stdio.h>
#include <math.h>

int jishu, i;
double shu, L, D, R;

int main()
{
    scanf("%d", &jishu);
    while (jishu--)
    {
        scanf("%lf %lf %lf", &L, &D, &R);

        if (R+R-D <= 1e-6)
        {
            printf("impossible\n");
        }
        else
        {
            shu = sqrt(4*R*R-D*D);
            if (shu-1 <= 1e-6)
            {
                printf("impossible\n");
            }
            else
            {
                printf("%d\n", (int)ceil(1.0*L/shu));
            }
        }
    }

    return 0;
}        