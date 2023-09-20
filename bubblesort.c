#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

void bubble_sort(int list[], int list_size){
    printf("----------------------------------------------------------------------------\n");
    printf("BUBBLE SORT ALGORITHM\n");
    printf("----------------------------------------------------------------------------\n");
    int j, k, temp, sorted = FALSE;
    while (!sorted) {
        sorted = TRUE;
        //PRINT THE LIST EACH CYCLE
        for (k = 0; k < list_size; k++)
        {
            printf("%d\t", list[k]);
        }
        //COMPARE TWO VALUES IN AN ARRAY AND SWAP VALUES
        //IF THE VALUE ON THE LEFT IS GREATER THEN THE RIGHT
        for (j = 0; j < list_size -1; j++)
        {
            if (list[j] > list[j+1])
            {
                sorted = FALSE;
                temp = list[j];
                list[j]= list[j+1];
                list[j+1] = temp;

            }
        }
        printf("\n");
        
    
    }
}

int main(void)
{   
    //TEST DATA: UNSORTD LIST
    int list[] = { 13, 56, 33, 1, 90, 54, 20, 150, 86,2};
    //INVOKE FUNCTION WIT LIST AND LIST SIZE AS PARA
    bubble_sort (list, sizeof(list)/sizeof(list[0])) ;
    exit( 0 );
}