

// 두 다항식을 입력 받아 다항식의 곱을 구하는 multpoly 함수

#include <stdio.h>
#include <math.h>
#define divisor 10.0;

int Poly_Result[10];
void make_poly_array(int, int*);
void Print_Poly(int*);
void Multi_Poly(int*, int*);


int pow_func(int i)
{
    int result=1;

    for (int j = 0; j < i; j++)
    {
        result *= 10;
    }

    return result;

}

int main() {

    int poly_a, poly_b;
    int poly_array_a[10], poly_array_b[10],Result[10];

    printf("Please Enter first Polynomial max 10 \n");
    printf("ex) 5x^4+3x^2+2x^1+1  -- > 50321 \n");

    scanf("%d", &poly_a);

    printf("Please Enter Second Polynomial max 10\n");
    printf("ex) 5x^4+3x^2+2x^1+1  -- > 50321 \n");

    scanf("%d", &poly_b);
    make_poly_array(poly_a, &poly_array_a[9]);
    make_poly_array(poly_b, &poly_array_b[9]);

    Multi_Poly(poly_array_a,poly_array_b);

    Print_Poly(&Poly_Result[9]);

}

void make_poly_array(int a, int* array)
{
    int  quotient, div_temp,a_t;
    a_t = a;

    for (int i = 9; i >= 0; i--)
    {

        div_temp = pow_func(i);
        quotient = a_t / div_temp;

        if (quotient != 0)
        {
         
            *array = quotient;
            a_t -= quotient * div_temp;
            
        }
        else
        {
            *array = 0;
            
        }

    array--;

    }

}

void Print_Poly(int *poly)
{
    for(int i=9; i>=0; i--)
    {
        printf("%dx^%d +  ",*poly, i);
        poly--;

    }
}

void Multi_Poly(int poly_a[], int poly_b[]){

    int i,j;
    int temp[20]={0,};

        for(i=0;i<10;i++)
    {
        printf("%d ",poly_a[i]);
    }
    printf("\n");


    for(i=9;i>=0;i--)
    {
        for(j=9;j>=0;j--)
        {
            if(poly_a[i]*poly_b[j] !=0)
            temp[i+j]+=poly_a[i]*poly_b[j];
        }

    }

    for(i=0;i<10;i++)
    {
        Poly_Result[i] = temp[i];
    }

}