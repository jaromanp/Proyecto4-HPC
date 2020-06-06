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



int hallarCadena(int *act, int *ant, int **P, char *A, char *B, char *C, int m, int n, int u)
{
    c_i=-1;
    
    for(int i=1;i<m+1;i++)
    {
         
        for(int j=0;j<u;j++)
        {
            if(C[j]== A[i-1])
            {
                c_i= j;
            }
        }
         
        int t,s;
        //Encontrar cadena comun mas larga
	   #pragma omp parallel for private(t,s) schedule(static)
        for(int j=0;j<n+1;j++)
        {
            t= (0-P[c_i][j])<0;
            s= (0 - (ant[j] - (t*ant[P[c_i][j]-1]) ));
            act[j] = ((t^1)||(s^0))*(ant[j]) + (!((t^1)||(s^0)))*(ant[P[c_i][j]-1] + 1);
        }
        //actualizar matrices
        #pragma omp parallel for schedule(static)
        for(int j=0;j<n+1;j++){
            ant[j] = act[j];
        }

              

    }        
         
    for(int a=1;a<n;a++){
	if(act[a]>act[a-1]){
	printf("%c",(char)B[a]);
	}   
        }
	
    return act[n];
}

int main(int argc, char *argv[])
{
    omp_set_num_threads(6);

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

    #pragma omp parallel 
  {          
      #pragma omp single
      {
          printf("hilos usados: %d\n", omp_get_num_threads() );
      }
  }
    
    actual = (int *)malloc((tamanoCadena2+1) * sizeof(int));
    anterior = (int *)malloc((tamanoCadena2+1) * sizeof(int));    
    matriz = (int **)malloc(numLetras * sizeof(int *));

    for(int k=0;k<numLetras;k++)
    {
        matriz[k] = (int *)calloc((tamanoCadena2+1), sizeof(int));
    }


    inicio = omp_get_wtime();

    //contar el numero de ocurrencias por letra en la cadena 2
    #pragma omp parallel for
    for(int t=0;t<numLetras;t++)
    {   
        
        for(int j=1;j<tamanoCadena2+1;j++)
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

    int resultadoOMP = hallarCadena(actual, anterior, matriz,cadena1,cadena2,letras,tamanoCadena1,tamanoCadena2,numLetras);
    fin = omp_get_wtime();

    printf("Tamano de la cadena: %d\n",resultadoOMP);
    printf("Tiempo : %lf segundos\n\n",fin - inicio);  


    free(matriz);
    free(actual);
    free(anterior);
    return 0;
}
