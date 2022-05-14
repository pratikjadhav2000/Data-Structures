#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


int main(){

    int *p = NULL;
    int response = 1;
    int size = 0;
    int n;


    while(response){
        
        printf("Do you want to enter a number? Yes - 1  No - 0 \n");
        scanf("%d",&response);

        if(response){

        printf("Enter number \n");
        scanf("%d",&n);     
        
        p = (int*)realloc(p,(size+1) * sizeof(int));
        assert(p != NULL); 

        *(p + size++) = n;

        }

    }

    for(int i=0;i<size;++i){
        printf("%d\n",*(p + i));
    }

    free(p);
    p = NULL;
    return 0;
}