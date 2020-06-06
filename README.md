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
- [Manuela Valencia Toro]( https://web.microsoftstream.com/video/b5b524c4-79db-4f37-a3e7-70970745859e)
- Andres Sanchez Castrillo
[p1](https://web.microsoftstream.com/video/a83eea1a-fb7d-4784-b186-b2bf5ae6fff9)
[p2](https://web.microsoftstream.com/video/a701b577-c657-4ac3-8f4a-6289810a63f6)
[p3](https://web.microsoftstream.com/video/74d34e17-4c1c-4af4-ae76-7c2f31239918)
[p4](https://web.microsoftstream.com/video/d1f8c779-0975-4eb1-93d7-0a039de2382c)
[p5](https://web.microsoftstream.com/video/9a44378e-fd60-461a-a49f-e2ce366aaddb)
[p6](https://web.microsoftstream.com/video/0f463fc7-2e77-4dfe-a07f-07f2d7811295)
- [Jose Alejandro Roman Patiño](https://web.microsoftstream.com/video/931cdfb2-6f9a-4171-bf0a-2733cef82bdc) (Por vencimiento de la cuenta inicial del cluster se tiene un nuevo usuario para acceso al cluster u44110@c008, las claves de acceso a esta fueron puestas en la carpeta del mooc HPC)
