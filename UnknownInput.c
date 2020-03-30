#include<stdio.h>


int main() {
    printf("Enter data, ctrl-z to end:\n");
    int array[20][7];
    int row_sum[20] = {0},col_sum[7] = {0};
    int row = 0, col = 0, temp;
    int max_row_index=0, max_col_index=0;
    while(row<20 && scanf("%d", &temp)==1) {
        col=0;
        array[row][col++] = temp;
        while(col<7 && scanf("%d", &temp)==1){
            array[row][col++] = temp;
        }
    }
    //number of rows in array is row
    //number of cols in array is col

    printf("Row averages ");
    for(int i=0;i<row;i++){
        row_sum[i] = 0;
        for(int j=0;j<col;j++) {
            row_sum[i]+=array[i][j];
        }
        if(row_sum[i]>row_sum[max_row_index]) {//checking max row value
            max_row_index = i;            
        }
    }
    for(int i=0;i<row;i++){
        printf("%lf", (double)row_sum[i]/(row));
    }
    printf("\nColumn averages ");
    for(int i=0;i<col;i++){
        col_sum[i] = 0;
        for(int j=0;j<row;j++) {
            col_sum[i]+=array[j][i];
        }
        if(col_sum[i]>col_sum[max_col_index]) {//checking max column value
            max_col_index = i;
        }
    }
    for(int i=0;i<row;i++){
        printf("%lf", (double)col_sum[i]/(col));
    }

    printf("\nRow with largest sum: %d sum is %d", max_row_index, row_sum[max_row_index]);
    printf("\nColumn with largest sum: %d sum is %d", max_col_index, col_sum[max_col_index]);
    
}