#define DOUBLE_FORMAT "%.2lf "
#include <stdio.h>
/* "This old function was needed to read doubles until I found out you can use "fscanf" instead :P
int readNum(FILE* file, double *num)
{ //reads a number delimited by whitespace, newline, or EOF
    returns 1 //for newline and space, 0 for EOF
    int ch, decimal = 0;
    double number, pos = 10, neg = 0.1;
    ch = fgetc(file);
    number = ch - '0';
    while (1)
    {
 	ch=fgetc(file);
        if(ch == ' ' || ch == '\n' || ch == EOF)
        	break;
        else if (ch == '.')
	    decimal = 1;
	else
	{
  	    ch -= '0';
            if(decimal)
  	    {
		number += (ch * neg);
		neg *= neg;	
	    }   
            else
	    {
            	number *= pos; //shift by an order of 10 everytime a new number is read
     	    	number += ch;
		pos *= pos;
	    }
        }
    }
    *num = number;
    if(ch == ' ' || ch == '\n')
	return 1;
    else
	return 0;
}
*/
void printMatrix(int rows, int columns, double matrix[rows][columns]) {
    int i, j;
    for(i = 0; i < rows; i++)
    {
 	for(j = 0; j < columns; j++)
	     printf("%d ", matrix[i][j]);
	printf("\n");
    }
}

int ind(int i, int j, int c)
{/* r is row, j is column, c is number of items per row */
 /* returns position of index i,j in a linear array */
    return i*c+j;
}
 
int main() {
    FILE *A, *B;
    A = fopen("A.txt", "r");
    B = fopen("B.txt", "r");
    int aRows = 0, bRows = 0, aColumns = 0, bColumns = 0;
    int c;
    double num;
    fscanf(A, "%d %d\n", &aRows, &aColumns);
    printf("Matrix A has %d rows and %d columns.\n", aRows, aColumns);
    fscanf(B, "%d %d\n", &bRows, &bColumns);
    printf("Matrix B has %d rows and %d columns.\n", bRows, bColumns);
    if(aColumns != bRows)
    {
	printf("Error: Incompatible Dimensions for Matrices");
	return 0;
    }
    //allocate memory for upcoming matrices
    double *M1, *M2, *M3;
    M1 = (double *)malloc(aRows*aColumns*sizeof(double));
    M2 = (double *)malloc(bRows*bColumns*sizeof(double));
    M3 = (double *)malloc(aRows*bColumns*sizeof(double));
    int i = 0,j = 0;
    while(!feof(A)) //read in 1st matrix
    {
	fscanf(A, "%lf", &num);
	M1[ind(i, j, aColumns)] = num;
	j++;
	if(j == aColumns)
	{
	    j = 0;
	    i++;
	}
    }
    printf("Value of Matrix A:\n");
    for(i = 0; i < aRows; i++)
    {
	for(j = 0; j < aColumns; j++)
	    printf(DOUBLE_FORMAT, M1[ind(i, j, aColumns)]);
	printf("\n");
    }
    i = 0, j = 0;
    while(!feof(B)) //read in 2nd matrix
    {
	fscanf(B, "%lf", &num);
       	M2[ind(i, j, bColumns)] = num;
       	j++;
	if(j == bColumns)
	{
	    j = 0;
	    i++;
	}
    }
    printf("Value of Matrix B:\n");
    for(i = 0; i < bRows; i++)
    {
	for(j = 0; j < bColumns; j++)
	    printf(DOUBLE_FORMAT, M2[ind(i, j, bColumns)]);
	printf("\n");
    }
    fclose(A);
    fclose(B);
    int k;
    double n;
    printf("Multiplying ..\n");
    for(i = 0; i < aRows; i++)
    {
	for(j = 0; j < bColumns; j++)
	{
	    n = 0;
	    for(k = 0; k < bRows; k++)
		n += M1[ind(i, k, aColumns)] * M2[ind(k, j, bColumns)];
	    M3[ind(i, j, bColumns)] = n;
	}
    }
    printf("Value of Matrix C:\n");
    for(i = 0; i < aRows; i++)
    {
	for(j = 0; j < bColumns; j++)
	    printf(DOUBLE_FORMAT, M3[ind(i, j, bColumns)]);
	printf("\n");
    }
}
