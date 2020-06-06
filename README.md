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

Link del drive: https://drive.google.com/drive/folders/1nrIzq5KtM4nba3IQXlD0b2vUQ-wmqLFv?usp=sharing

Dado que este proyecto se define como fuertemente acoplado, al aplicar el MPI no se obtienen resultados óptimos por su funcionamiento y por la definición de este. Es por esta razón que no se adjuntó en este trabajo la sección relacionada con MPI, pues al hallar el speedUp no arrojaría los resultados esperados.

### Links Videos
- Manuela Valencia Toro https://web.microsoftstream.com/video/b5b524c4-79db-4f37-a3e7-70970745859e
- Andres Sanchez Castrillo
- [Jose Alejandro Roman Patiño](https://web.microsoftstream.com/video/931cdfb2-6f9a-4171-bf0a-2733cef82bdc)
