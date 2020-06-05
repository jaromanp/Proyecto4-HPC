# Diseño del algoritmo paralelo: PCAM para el problema de la secuencia común más larga

1. Particionamiento. Para pasar el algoritmo secuencial a paralelo se deben descomponer y separar las tareas principales y analizar cuales podrían ser paralelizados. Al implementar esto en el código desarrollado se encontró lo siguiente:

Dado que dentro del método hallarCadena() las tareas relacionadas con buscar ocurrencias de los caracteres en el texto, imprimir la matiz solución, actualizar las matrices y hallar la cantidad de veces que cada caracter aparece en el texto se ejecutarán en ciclos separados independientes entre sí, de manera que cada uno de estos pueda situarse en un hilo diferente al momento de la ejecución, Al igual que cada una de las matrices y los datos a almacenar se guardarán en una estructura diferente de manera que permita implementar el paralelismo sin riesgo a perdida o daño de los datos.
### Tareas
T1: Carga de datos
T2: Guardado de los datos en la estructura
T3: Generar matriz de ocurrencias y de resultados
T4: Recorrer las secuencias y guardar en la matriz las ocurrencias
T5: Enviar mensajes a la matriz de resultados (Cada hilo)
T6: Actualizar valores de la matriz
T7: Imprimir resultado de la matriz de resultados



2. Comunicación. El flujo de información se desarrallará de la siguiente manera: 
inicialmente los datos a procesar se leerán del archivo y se almacenarán en diferentes estructuras segun corresponda y se asigna el espacio de memoria necesario. Luego de esto se entra en el primer ciclo que busca y almacena el número de ocurrencias por letra en la cadena2 en un arreglo que será leido tanto por la matriz encargada de realizar el proceso para hallar la cadena más larga como por la que se encarga de imprimir el resultado y la que se encarga de actualizar los valores de la matriz anterior. por lo que se define como una variable compartida entre todos los hilos que se generen. este nuevo alforitmo mantendra esta estructura dado que no hay problema alguno con la ejecucion en paralelo.
![enter image description here](https://raw.githubusercontent.com/jaromanp/Proyecto4-HPC/master/Images/Diagrama%20en%20blanco%20%281%29.png)

3. Aglomeración. Dado que desde un principio se tuvo en cuenta la paralelizacion al momento de implementar el secuencial los procesos y metodos fueron distribuidos de manera que la ejecucion fuera optima y los costos tanto de comunicacion como de sinconizacion fueran minimos por lo que en esta sección no es necesario realizar cambios importantes.
- Tareas Seriales: T1, T2, T3, T7
- Tareas paralelas (OMP): T4, T5, T6

 
4. Mapeo. Las tareas correspondientes a : actualizar matrices, contar la secuencia mas larga y contar el numero de ocurrencias por letra dentro de la cadena c. se asignaran a procesadores diferentes de manera que se puedan ejecutar en paralelo cuando sea pertinente. de estas, cada tarea es asignada a un procesador de tal modo que intente satisfacer las metas de competencia al maximizar la utilización del procesador y minimizar los costos de comunicación. 


