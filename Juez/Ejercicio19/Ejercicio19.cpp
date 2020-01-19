// Andrés Puente Rodriguez
// MARP34
// Problema19 -> Ratones en un laberinto

#define MAXIMUS 10000

#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>

#include "GrafoDirigidoValorado.h"

using namespace std;

void resultado(GrafoDirigidoValorado<int> const &gdv, int fin, int t) {
	vector<int> dist_(gdv.V(), MAXIMUS);
	vector<bool> marked_(gdv.V(), false);
	int n_out = 0;

	queue<int> q;

	marked_[fin] = true;
	dist_[fin] = 0;
	q.push(fin);

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (AristaDirigida<int> w : gdv.ady(v)) {
			int w1 = w.to();
			int cost = w.valor() + dist_[v];
			dist_[w1] = min(dist_[w1], cost);

			if (!marked_[w1]) {
				q.push(w1);
				marked_[w1] = true;
			}
		}
	}

	for (int i = 0; i < dist_.size(); i++) {
		if (dist_[i] <= t && i != fin) n_out++;
	}

	cout << n_out << "\n";
}

bool resuelveCaso() {
	int N, S, T, P;

	cin >> N >> S >> T >> P;
	S--;
	if (!cin) return false;

	// Grafo
	GrafoDirigidoValorado<int> gdv(N);

	// Creacion de las aristas valoradas dirigidas del grafo
	AristaDirigida<int> ar;
	for (int i = 0; i < P; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		ar = AristaDirigida<int>(a, b, c);
		gdv.ponArista(ar);
	}

	resultado(gdv.inverso(), S, T);

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