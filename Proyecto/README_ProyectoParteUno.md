# Caché #
### Acceso por Correspondencia Directa, Asociativa por Conjuntos y Completamente Asociativa ###
	
	Use tres procedimientos para simular las tres politicas de correspondencia de una memoria cache, 
	estos procedimientos son: correspDirecta, correspAsocConjuntos y correspAsociativa

### correspDirecta: ### 
	Este procedimiento implementa la política de correspondencia directa. 
	Recibe como entrada una dirección de archivo, un vector de bloques bloques y una referencia a un objeto ofstream llamado log para escribir el registro de resultados.

	Crea un vector llamado cache con 4 elementos, inicializados a -1. Este vector representa la caché.
	Lee las direcciones de memoria del archivo direccion y las procesa una por una.
	Calcula el número de bloque utilizando el operador de módulo (%).
	Comprueba si la dirección de bloque está en la caché. Si está presente, es un acierto. Si no está presente, es un fallo.
	Actualiza la caché con la dirección de bloque actual.
	Imprime y registra los resultados del acceso, el número de bloque y el contenido del bloque.
	
### correspAsocConjuntos: ### 
	Este procedimiento implementa la política de correspondencia asociativa por conjuntos. Recibe los mismos parámetros que correspDirecta.
	Crea una matriz bidimensional llamada cache con 2 conjuntos y 2 bloques por conjunto, inicializados a -1. Esta matriz representa la caché.
	Lee las direcciones de memoria del archivo direccion y las procesa una por una.
	Calcula el número de conjunto utilizando el operador de módulo (%).
	Busca la dirección de bloque en el conjunto correspondiente de la caché. Si está presente, es un acierto. Si no está presente, es un fallo.
	Si es un fallo, busca un espacio disponible en el conjunto para almacenar la dirección de bloque actual. Si no hay espacio disponible, reemplaza un bloque aleatoriamente.
	Actualiza la caché con la dirección de bloque actual.
	Imprime y registra los resultados del acceso, el número de conjunto, el número de bloque y el contenido del bloque.
	
### correspAsociativa: ### 
	Este procedimiento implementa la política de correspondencia completamente asociativa. Recibe los mismos parámetros que correspDirecta.
	Crea un vector llamado cache con 4 bloques, inicializados a -1. Este vector representa la caché.
	Lee las direcciones de memoria del archivo direccion y las procesa una por una.
	Busca la dirección de bloque en la caché. Si está presente, es un acierto. Si no está presente, es un fallo.
	Si es un fallo, busca un espacio disponible en la caché para almacenar la dirección de bloque actual. Si no hay espacio disponible, reemplaza un bloque aleatoriamente.
	Actualiza la caché con la dirección de bloque actual.
	Imprime y registra los resultados del acceso, el número de bloque y el contenido del bloque.
	
Después de definir estos procedimientos, el código principal se encuentra en la función main. Aquí se realiza lo siguiente:
Se define el nombre del archivo de direcciones y un vector de bloques.
Se crea un objeto ofstream llamado log para escribir el registro de resultados, y se abre en modo de adjuntar (ios::app).
Se llama a cada uno de los procedimientos correspDirecta, correspAsocConjuntos y correspAsociativa, pasando los parámetros correspondientes.
Se cierra el archivo log y termina el programa.