// Andrés Puente Rodriguez
// MARP34
// Problema16 -> Camiones de reparto

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

#include "GrafoValorado.h"

using namespace std;

bool resuelveCaso() {
	// leer los datos de la entrada
	long V, E;
	cin >> V >> E;

	if (!cin) return false;

	GrafoValorado<long> g(V);

	long v, w, value;
	for (int i = 0; i < E; i++) {
		cin >> v >> w >> value;
		v--; w--;
		Arista<long> r (v, w, value);
		g.ponArista(r);
	}

	//g.print();
	//cout << g.ady(0).front().valor();

	long consultas;
	cin >> consultas;

	long ini, fin, S;
	for (int i = 0; i < consultas; i++) {
		cin >> ini >> fin >> S;
		ini--; fin--;

		//bool bip = true;
		bool finReached = false;
		vector<bool> marked_(g.V(), false);
		queue<long> q;
		q.push(ini);

		while (!q.empty() && !finReached) {
			long v = q.front(); q.pop();
			for (Arista<long> w : g.ady(v)) {
				long w1 = w.otro(v);
				if (w.valor() >= S) {
					if (!marked_[w1]) {
						if (w1 != fin) {
							q.push(w1);
							marked_[w1] = true;
						}
						else {
							finReached = true;
						}
					}
				}
			}
		}

		if (finReached) cout << "SI\n";
		else cout << "NO\n";
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