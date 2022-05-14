#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 10

struct point3d{
    int x;
    int y;
    int z;
};

int main(){

    struct point3d **array_of_struct;

            //allocate memory for array
            array_of_struct = (struct point3d**)malloc( N * sizeof(struct point3d*) );
            assert(array_of_struct != NULL);

            //allocate memory for structures and fill array with structures
            for(int i=0;i<N;++i){
                struct point3d *temp;
                 temp = (struct point3d*)malloc(sizeof(struct point3d));
                 assert(temp != NULL);
                 *(array_of_struct + i) = temp;
            }

            //fill structures with values
            for(int i=0;i<N;++i){
                struct point3d *temp;
                temp = *(array_of_struct + i) ;
                temp->x = (i+1) * 100;
                temp->y = (i+1) * 200;
                temp->z = (i+1) * 300;
            }

            //print values inside all stuctures
            for(int i=0;i<N;++i){
                struct point3d *temp;
                temp = *(array_of_struct + i) ;
                printf("%d x = %d y = %d z = %d  \n",i+1,temp->x,temp->y,temp->z);
              
            }

            //free all stuctures
            for(int i=0;i<N;++i){
                struct point3d *temp;
                temp = *(array_of_struct + i) ;
                free(temp);
                temp = NULL;
            }
    //free array of structure
    free(array_of_struct);
    array_of_struct = NULL;
    return 0;
}