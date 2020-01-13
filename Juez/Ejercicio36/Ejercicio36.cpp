// Andrés Puente Rodriguez
// MARP34
// Problema35 -> Maraton de cine de terror

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

#include "PriorityQueue.h"

using namespace std;

struct sesion {
	int ini, fin;

	void init(int i, int f) {
		ini = i;
		fin = f;
	}
};

bool operator<(const sesion &a, const sesion &b) {
	return a.ini < b.ini;
}

int voraz_method(PriorityQueue<sesion, less<sesion>> pq) {
	int compañeros = 0;
	int fin = 0;
	int n = pq.size();
	sesion p;

	int aux = 0;

	for (int i = 0; i < n; i++) {
		p = pq.top(); pq.pop();
		if (p.ini >= fin) {
			fin = p.fin;
			aux++;
		}
		else {
			aux++;
			compañeros = max(aux, compañeros);
		}
		if (p.fin < fin) fin = p.fin;
	}

	return compañeros;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n_Pelis = 0;
	cin >> n_Pelis;

	if (n_Pelis == 0) return false;


	//Priority_Queue<peli> peliculas_;
	PriorityQueue<sesion, less<sesion>> peliculas_;
	sesion p;
	int i, f;

	for (int a = 0; a < n_Pelis; a++) {
		cin >> i >> f;
		p.init(i, f);
		peliculas_.push(p);
	}

	cout << voraz_method(peliculas_) << "\n";

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