// Andrés Puente Rodriguez
// MARP34
// Problema35 -> Maraton de cine de terror

#include <iostream>
#include <iomanip>
#include <fstream>

#include "PriorityQueue.h"


using namespace std;

struct peli {
	int ini, fin;

	void init (int h, int min, int d) {
		ini = h * 60 + min;
		fin = ini + d + 10;
	}
};

bool operator<(const peli &a, const peli &b) {
	return a.ini < b.ini;
}

int voraz_method(PriorityQueue<peli, less<peli>> pq) {
	int posibles = 0;
	int fin = 0;
	int n = pq.size();
	peli p;

	for (int i = 0; i < n; i++) {
		p = pq.top(); pq.pop();
		if (p.ini >= fin) {
			fin = p.fin;
			posibles++;
		}
		if (p.fin < fin) fin = p.fin;
	}

	return posibles;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n_Pelis = 0;
	cin >> n_Pelis;

	if (n_Pelis == 0) return false;


	//Priority_Queue<peli> peliculas_;
	PriorityQueue<peli, less<peli>> peliculas_;
	peli p;
	int h, min, d;
	char puntos;

	for (int i = 0; i < n_Pelis; i++) {
		cin >> h >> puntos >> min >> d;
		p.init(h, min, d);
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