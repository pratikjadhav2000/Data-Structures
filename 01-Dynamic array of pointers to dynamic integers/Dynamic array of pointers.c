#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 5

int main()
{

    // int
    int **pp = NULL;
    pp = (int **)malloc(N * sizeof(int *));
    assert(pp != NULL);

    for (int i = 0; i < N; ++i)
    {
        *(pp + i) = (int *)malloc(sizeof(int));
        assert(*(pp + i) != NULL);
    }

    for (int i = 0; i < N; ++i)
    {
        *(*(pp + i)) = 10000000 * (i + 1);
    }

    for (int i = 0; i < N; ++i)
    {
        printf("%d \n", *(*(pp + i)));
        free(*(pp + i));
        *(pp + i) = NULL;
    }

    free(pp);
    pp = NULL;

    // char
    char **cpp = NULL;

    cpp = (char **)malloc(N * sizeof(char *));
    assert(cpp != NULL);

    for (int i = 0; i < N; ++i)
    {
        *(cpp + i) = (char *)malloc(sizeof(char));
        assert(*(cpp + i) != NULL);
    }

    for (int i = 0; i < N; ++i)
    {
        *(*(cpp + i)) = i + 'A';
    }

    for (int i = 0; i < N; ++i)
    {
        printf("%c \n", *(*(cpp + i)));
        free(*(cpp + i));
        *(cpp + i) = NULL;
    }
    free(cpp);
    cpp = NULL;

    // short int

    short **spp = NULL;
    spp = (short **)malloc(N * sizeof(short *));
    assert(spp != NULL);

    for (int i = 0; i < N; ++i)
    {
        *(spp + i) = (short *)malloc(sizeof(short));
        assert(*(spp + i) != NULL);
    }

    for (int i = 0; i < N; ++i)
    {
        *(*(spp + i)) = 1000 * (i + 1);
    }

    for (int i = 0; i < N; ++i)
    {
        printf("%hd \n", *(*(spp + i)));
        free(*(spp + i));
        *(spp + i) = NULL;
    }

    free(spp);
    spp = NULL;
    // float

    float **fpp = NULL;
    fpp = (float **)malloc(N * sizeof(float *));
    assert(fpp != NULL);

    for (int i = 0; i < N; ++i)
    {
        *(fpp + i) = (float *)malloc(sizeof(float));
        assert(*(fpp + i) != NULL);
    }

    for (int i = 0; i < N; ++i)
    {
        *(*(fpp + i)) = 10000.00 * (i + 1);
    }

    for (int i = 0; i < N; ++i)
    {
        printf("%3.2f \n", *(*(fpp + i)));
        free(*(fpp + i));
        *(fpp + i) = NULL;
    }

    free(fpp);
    fpp = NULL;

    // long int
    long **lpp = NULL;
    lpp = (long **)malloc(N * sizeof(long *));
    assert(lpp != NULL);

    for (int i = 0; i < N; ++i)
    {
        *(lpp + i) = (long *)malloc(sizeof(long));
        assert(*(lpp + i) != NULL);
    }

    for (int i = 0; i < N; ++i)
    {
        *(*(lpp + i)) = 100000000 * (i + 1);
    }

    for (int i = 0; i < N; ++i)
    {
        printf("%ld \n", *(*(lpp + i)));
        free(*(lpp + i));
        *(lpp + i) = NULL;
    }

    free(lpp);
    lpp = NULL;

    // long long int
    long long **llpp = NULL;
    llpp = (long long **)malloc(N * sizeof(long long *));
    assert(llpp != NULL);

    for (int i = 0; i < N; ++i)
    {
        *(llpp + i) = (long long *)malloc(sizeof(long long));
        assert(*(llpp + i) != NULL);
    }

    for (int i = 0; i < N; ++i)
    {
        *(*(llpp + i)) = 100000000000000 * (i + 1);
    }

    for (int i = 0; i < N; ++i)
    {
        printf("%lld \n", *(*(llpp + i)));
        free(*(llpp + i));
        *(llpp + i) = NULL;
    }

    free(llpp);
    llpp = NULL;

    return 0;
}