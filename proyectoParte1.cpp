#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void correspDirecta(string direccion, vector<int>& bloques, ofstream& log) {
	ifstream direcciones(direccion);
	int direccionBloque = 0;
	int numBloque;
	int contenidoBloque;
	bool fallo;

	cout << "Correspondencia Directa:" << endl;
	log << "Correspondencia Directa:" << endl;

	while (direcciones >> direccionBloque) {
		numBloque = direccionBloque % bloques.size();

		if (bloques[numBloque] == direccionBloque) {
			fallo = false;
			contenidoBloque = bloques[numBloque];
		}
		else {
			fallo = true;
			contenidoBloque = -1; // Cambiar a otro valor para representar contenido inválido
			bloques[numBloque] = direccionBloque;
		}

		cout << "Acceso: " << (fallo ? "Fallo " : "Acierto ");
		cout << "En el Bloque: " << numBloque;
		cout << "Contenido: " << contenidoBloque << endl;

		log << "Acceso: " << (fallo ? "Fallo " : "Acierto ");
		log << "En el Bloque: " << numBloque;
		log << "Contenido: " << contenidoBloque << endl;
	}
	direcciones.close();
}

void correspAsocConjuntos(string direccion, vector<int>& bloques, ofstream& log) {
	ifstream direcciones(direccion);

	int direccionBloque = 0; // Inicialización con un valor predeterminado

	int numConjunto;
	int numBloque;
	int contenidoBloque;
	bool fallo;

	vector<int> conjunto0(bloques.size() / 2, -1);
	vector<int> conjunto1(bloques.size() / 2, -1);

	cout << "Correspondencia Asociativa por Conjuntos:" << endl;
	log << "Correspondencia Asociativa por Conjuntos:" << endl;


	while (direcciones >> direccionBloque) {
		numConjunto = direccionBloque % 2;
		numBloque = direccionBloque % (bloques.size() / 2);

		if (numConjunto == 0) {
			if (conjunto0[numBloque] == direccionBloque) {
				fallo = false;
				contenidoBloque = conjunto0[numBloque];
			}
			else {
				fallo = true;
				contenidoBloque = -1;
				conjunto0[numBloque] = direccionBloque;
			}
		}
		else {
			if (conjunto1[numBloque] == direccionBloque) {
				fallo = false;
				contenidoBloque = conjunto1[numBloque];
			}
			else {
				fallo = true;
				contenidoBloque = -1;
				conjunto1[numBloque] = direccionBloque;
			}
		}

		cout << "Acceso: " << (fallo ? "Fallo" : "Acierto") << endl;
		cout << "Bloque: " << numBloque << endl;
		cout << "Contenido: " << contenidoBloque << endl;

		log << "Acceso: " << (fallo ? "Fallo" : "Acierto") << endl;
		log << "Bloque: " << numBloque << endl;
		log << "Contenido: " << contenidoBloque << endl;
	}

	direcciones.close();
}

void correspAsociativa(string direccion, vector<int>& bloques, ofstream& log) {
	ifstream direcciones(direccion);

	int direccionBloque = 0; // Inicialización con un valor predeterminado

	int numBloque;
	int contenidoBloque;
	bool fallo;

	vector<int> cache(4, -1);

	cout << "Correspondencia Completamente Asociativa:" << endl;
	log << "Correspondencia Completamente Asociativa:" << endl;

	while (direcciones >> direccionBloque) {
		numBloque = -1;
		fallo = true;

		// Buscar el bloque en la cache
		for (int i = 0; i < cache.size(); i++) {
			if (cache[i] == direccionBloque) {
				fallo = false;
				numBloque = i;
				contenidoBloque = cache[i];
				break;
			}
		}

		// Si el bloque no está en la cache, buscar un espacio disponible
		if (fallo) {
			for (int i = 0; i < cache.size(); i++) {
				if (cache[i] == -1) {
					numBloque = i;
					cache[i] = direccionBloque;
					contenidoBloque = direccionBloque;
					break;
				}
			}
		}

		// Si no hay espacio disponible, reemplazar un bloque aleatoriamente
		if (numBloque == -1) {
			numBloque =  rand() % cache.size();
			contenidoBloque = cache[numBloque];
			cache[numBloque] = direccionBloque;
		}

		 cout << "Acceso: " << (fallo ? "Fallo" : "Acierto") <<  endl;
		 cout << "Bloque: " << numBloque <<  endl;
		 cout << "Contenido: " << contenidoBloque <<  endl;

		log << "Acceso: " << (fallo ? "Fallo" : "Acierto") <<  endl;
		log << "Bloque: " << numBloque <<  endl;
		log << "Contenido: " << contenidoBloque <<  endl;
	}

	direcciones.close();
}
}

int main() {
	string fArch;
	ifstream testF;
	ofstream log("log.txt", ios::app);
	vector<int> bloques(4);

	cout << "Ingrese el nombre del archivo que contiene la secuencia de direcciones de bloque:" << endl;
	cin >> fArch;

	testF.open(fArch.c_str());
	if (testF.fail()) {
		cout << "ERROR" << endl;
		cout << "El archivo no existe." << endl;

		cin.get();
		exit(EXIT_FAILURE);
	}
	testF.close();

	correspDirecta(fArch, bloques, log);
	correspAsocConjuntos(fArch, bloques, log );
	correspAsociativa(fArch, bloques, log);

	log.close();
	cout << "Pulse ENTER para terminar el programa...";
	cin.get(); //pausa antes del final del programa
	return 0;
}