#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include "omp.h"


#define max(x,y) ((x)>(y)?(x):(y))



char *cadena1;
char *cadena2;
char *letras; 
int numLetras;
int **matriz;
int *actual; 
int *anterior; 
int c_i;



int hallarCadena(int *matrix, int *ant, int **mat,char *c1, char *c2, int tamanoC1, int tamanoC2,int numl)

{   int i=1;
    int x;
    
    c_i=-1;
    int j;
    for( i=1;i<tamanoC1+1;i++)
    {
        
        for( j=0;j<numl;j++)
        {
            if(letras[j]== c1[i-1])
            {
                c_i= j;
            }
        }
         
        int t,s;
        
	    for( j=0;j<tamanoC2+1;j++)
        {
            t= (0-mat[c_i][j])<0;
            s= (0 - (ant[j] - (t*ant[mat[c_i][j]-1]) ));
            matrix[j] = ((t^1)||(s^0))*(ant[j]) + (!((t^1)||(s^0)))*(ant[mat[c_i][j]-1] + 1);
        }

        
        for( j=0;j<tamanoC2+1;j++){
            ant[j] = matrix[j];
        }

        
        

    }
        int a;

        for(a=1;a<tamanoC2;a++){
	if(matrix[a]>matrix[a-1]){
	printf("%c",(char)c2[a]);
}
}
    return matrix[tamanoC2];
}
 
    
int main(int argc, char *argv[])
{

    if(argc <= 1){
        printf("Debe especificar un archivo\n");
        return 0;
    }

    FILE *fp;
    int tamanoCadena1,tamanoCadena2;
    double inicio, fin;

    fp = fopen(argv[1], "r");
    fscanf(fp, "%d %d %d", &tamanoCadena1, &tamanoCadena2, &numLetras);
    
    cadena1 = (char *)malloc((tamanoCadena1+1) * sizeof(char *));
    cadena2 = (char *)malloc((tamanoCadena2+1) * sizeof(char *));
    letras = (char *)malloc((numLetras+1) * sizeof(char *));

     fscanf(fp, "%s %s %s", cadena1,cadena2,letras);

    //allocate memory for matrix Results
    actual = (int *)malloc((tamanoCadena2+1) * sizeof(int));
    anterior = (int *)malloc((tamanoCadena2+1) * sizeof(int));
    
    
      
    //allocate memory for matriz array
    matriz = (int **)malloc(numLetras * sizeof(int *));
    int k;
    for( k=0;k<numLetras;k++)
    {
        matriz[k] = (int *)calloc((tamanoCadena2+1), sizeof(int));
    }
     
     inicio = clock();
    int t ;
    int j;
    for(t=0;t<numLetras;t++)
    {   
        for(j=1;j<tamanoCadena2+1;j++)
        {
            if(cadena2[j-1]==letras[t])
            {
                matriz[t][j] = j;
            }
            else
            {
                matriz[t][j] = matriz[t][j-1];
            }
        }  
    }    
        
     
     int resultadoSecuencial = hallarCadena(actual, anterior, matriz, cadena1, cadena2, tamanoCadena1, tamanoCadena2,numLetras);
     fin = clock();
     printf("tamano de la cadena: %d\n",resultadoSecuencial);
     printf("Tiempo : %lf segundos\n\n",((double)fin - inicio)/CLOCKS_PER_SEC);



    free(matriz);
    free(actual);
    free(anterior);


    
    return 0;
}
