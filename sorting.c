#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int input_size = argc - 1;
    if (input_size <= 0){
        printf("No input numbers\n");
        exit(-1);
    }

    int *input_data = calloc(input_size, sizeof(int));
    for(int i = 0; i < input_size; i++){
        input_data[i] = atoi(*(argv + (i + 1)));
    }

    for(int k = 0; k < input_size - 1; k++){
        int pivot = input_data[k];
        int *smallest = &input_data[k + 1];
        
        for(int m = k + 2; m < input_size; m++){
            if(input_data[m] < *smallest){
                smallest = &input_data[m];
            }
        }

        if(*smallest < input_data[k]){
            int temp = input_data[k];
            input_data[k] = *smallest;
            *smallest = temp;
        }
    }

    for(int j = 0; j < input_size; j++){
        printf("%d\n", input_data[j]);
    }

    free(input_data);
}