#include <stdio.h>
#include <stdlib.h> //malloc and free functions

int main(void){
    
    int *array = NULL;
    int array_size;
    
    printf("Quantos números inteiros o array deve conter: ");
    scanf("%d", &array_size);

    //memory allocation
    array = (int *) malloc(array_size * sizeof(int));

    //check if array memory allocation is ok
    if(array == NULL) {
        printf("Error in memory allocation");
        return 1;
    }

    //read numbers to array
    for(int i = 0; i < array_size; i++) {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    //show array in reverse
    printf("Array de trás pra frente:\n");

    for(int i = array_size-1; i >= 0; i--){
        printf("array[%d]: %d\n",i, array[i]);
    }
    //free array memory
    free(array);
    array = NULL;
    return 0;
}
