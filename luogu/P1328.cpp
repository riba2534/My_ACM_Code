#include <stdio.h>
#include <stdlib.h>

int main() {
    int game[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
    int N, NA, NB;
    scanf("%d %d %d", &N, &NA, &NB);
    int ans1 = 0, ans2 = 0;
    int *a = (int *)calloc(NA, sizeof(int));
    int *b = (int *)calloc(NB, sizeof(int));
    for (int i = 0; i < NA; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < NB; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < N; ++i) {
        ans1 += game[a[i % NA]][b[i % NB]];
        ans2 += game[b[i % NB]][a[i % NA]];
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}