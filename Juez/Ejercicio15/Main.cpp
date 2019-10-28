// Andrés Puente Rodriguez
// MARP34
// Problema15 -> Serpientes y Escaleras

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

#include "GrafoDirigido.h"

using namespace std;

//--------Vector---------
void jugada(vector<long> &T, long c, int dado, vector<long> &a) {
	for (int i = 1; i <= dado; i++) {
		c++;

		// Por si tiene escalera o serpiente
		if (T[c] != 0) {
			a.push_back(T[c]);
		}
		// Por si hemos llegado al final del tamaño del dado y sera siguiente jugada 100%
		else if (i == dado) {
			// Para no pasarnos del tamaño
			if (c <= T.size()- 1) {
				a.push_back(c);
			}
		}
		// Por si en algun momento llegamos al final
		else if (c == T.size()- 1) {
			a.push_back(c);
			i = dado;
		}
	}
}

int resolver(vector<long> &t, int dado) {
	priority_queue<long, vector<long>, less<long>> nextJugada;
	vector<long> aux;
	vector<long> aux1;
	int n = 0;

	nextJugada.push(0);

	while (nextJugada.top() != t.size()- 1) {
		int z = nextJugada.size();
		for (int j = 0; j < z; j++) {
			long a = nextJugada.top();	nextJugada.pop();
			jugada(t, a, dado, aux);
			for (int i = 0; i < aux.size(); i++) {
				aux1.push_back(aux[i]);
			}
			aux.clear();
		}

		for (int i = 0; i < aux1.size(); i++) {
			nextJugada.push(aux1[i]);
		}
		aux1.clear();
		n++;
	}

	return n;
}

//--------Grafo----------
void jugada(GrafoDirigido &g, long casilla, int d, vector<long> &v, vector<bool> &c) {
	for (int i = 1; i <= d; i++) {
		casilla++;
		if (!c[casilla]) {
			c[casilla] = true;
			// Por si hay escalera o serpiente
			if (g.ady(casilla).size() > 0) {
				int salto = g.ady(casilla).front();
				if (!c[salto]) {
					c[salto] = true;
					v.push_back(salto);
				}
			}
			// Por si hemos comprobado todas las posibles casillas del dado
			else if (i == d) {
				// Para no pasarnos de tamaño en el tablero
				if (casilla < g.V()) {
					v.push_back(casilla);
				}
			}
			else if (casilla == g.V() - 1) {
				v.push_back(casilla);
				i = d;
			}
		}
	}
}

int resolver(GrafoDirigido &g, int d) {
	priority_queue<long, vector<long>, less<long>> pq;
	vector<long> aux, aux1;
	vector<bool> checked(g.V(), false);
	pq.push(0);
	checked[0] = true;
	int n = 0;
	
	while (pq.top() != g.V() - 1) {
		int z = pq.size();
		for (int i = 0; i < z; i++) {
			long casilla = pq.top();	pq.pop();
			jugada(g, casilla, d, aux, checked);
			for (int j = 0; j < aux.size(); j++) {
				aux1.push_back(aux[j]);	// Auxiliar para pasarlo a la cola de prioridad que se pasara cada vez que no se pueden realizar mas movimientos interesantes en la misma tirada
			}
			aux.clear();	//Auxiliar para cada casilla todas sus opciones rentables en una tirada
		}
		for (int i = 0; i < aux1.size(); i++) {
			pq.push(aux1[i]);
		}
		aux1.clear();
		n++;
	}
	return n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long size;
	long dado, n_s, n_e;

	cin >> size >> dado >> n_s >> n_e;

	if (size == 0 && dado == 0 && n_s == 0 && n_e == 0) return false;

	GrafoDirigido g(size*size);

	vector<long> tablero(size*size);

	// Añadir serpientes
	for (int i = 0; i < n_s; i++) {
		long a, b;
		cin >> a >> b;
		a--;
		b--;
		g.ponArista(a, b);
		tablero[a] = b;
	}

	//Añadir escaleras
	for (int i = 0; i < n_e; i++) {
		long a, b;
		cin >> a >> b;
		a--;
		b--;
		g.ponArista(a, b);
		tablero[a] = b;
	}

	//cout << resolver(tablero, dado) << '\n';
	cout << resolver(g, dado) << '\n';
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