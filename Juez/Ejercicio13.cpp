// Andrés Puente Rodriguez
// MARP34
// Problema13 -> La ronda de la noche

// Usar grafos para representar el mapa, a cada vertice se le deben añadir como aristas los 4, o menos, vertices laterales

#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <queue>

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n_Gardens = 0;

	cin >> n_Gardens;

	long ancho, alto;

	for (int i = 0; i < n_Gardens; i++) {
		cin >> ancho;
		cin >> alto;
	}


	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Text.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}