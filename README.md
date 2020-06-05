# Proyecto4-HPC
## Instrucciones para correr los algoritmos desarrollados:

1. entrar a la carpeta omp o a la carpeta secuencial
2. ejecutar el make
3. ejecutar la siguiente instruccion: ./"omp o secuencial" a.txt > output.txt

los resultados se almacenaran en el archivo output.txt

el archivo de salida en ambos casos esta organizado de la siguiente manera:

secuencia comun mas larga
tamano de la secuencia comun mas larga
tiempo total

el speedUp obtenindo en esta implementación fué: 50.070000/26.611313= 1.9 aproximadamente, lo que indica que el algoritmo paralelizado es más eficiente que el secuencial. entre mas grande la entrada mas se notará el cambio.