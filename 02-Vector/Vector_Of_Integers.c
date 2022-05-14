#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct vector_int
{
    int *arr;
    unsigned long long int size;
};

struct vector_int *create_vector();
void append_vector(struct vector_int *pv, int number);
void display_vect(struct vector_int *pv, const char *msg);
void destroy_vector(struct vector_int **ppv);

int main()
{

    struct vector_int *vec_remain0, *vec_remain1, *vec_remain2;
    vec_remain0 = NULL;
    vec_remain1 = NULL;
    vec_remain2 = NULL;

    struct vector_int *pvector;
    pvector = NULL;

    int count = 10;
    int number;

    vec_remain0 = create_vector();
    vec_remain1 = create_vector();
    vec_remain2 = create_vector();

    for (int i = 0; i < count; ++i)
    {

        number = rand();

        switch (number % 3)
        {
        case 0:
            pvector = vec_remain0;
            break;

        case 1:
            pvector = vec_remain1;
            break;

        case 2:
            pvector = vec_remain2;
            break;
        }

        append_vector(pvector, number);
        pvector = NULL;
    }

    display_vect(vec_remain0, "Divisible by 3");
    display_vect(vec_remain1, "Divisible by 3 remainder 1");
    display_vect(vec_remain2, "Divisible by 3 remainder 2");

    destroy_vector(&vec_remain0);
    destroy_vector(&vec_remain1);
    destroy_vector(&vec_remain2);

    assert(vec_remain0 == NULL && vec_remain1 == NULL && vec_remain2 == NULL);
    exit(0);
}

struct vector_int *create_vector()
{

    struct vector_int *pvector;
    pvector = (struct vector_int *)malloc(sizeof(struct vector_int));
    assert(pvector != NULL);
    pvector->arr = NULL;
    pvector->size = 0;

    return (pvector);
}

void append_vector(struct vector_int *pv, int number)
{

    pv->arr = (int *)realloc(pv->arr, (pv->size + 1) * sizeof(int));
    pv->arr[pv->size] = number;
    pv->size += 1;
}

void display_vect(struct vector_int *pv, const char *msg)
{

    if (msg != NULL)
        puts(msg);

    for (int i = 0; i < pv->size; ++i)
    {
        printf("%d \n", pv->arr[i]);
    }
}

void destroy_vector(struct vector_int **ppv)
{

    struct vector_int *pvector = *ppv;
    free(pvector->arr);
    pvector->arr = NULL;
    free(pvector);
    *ppv = NULL;
}
