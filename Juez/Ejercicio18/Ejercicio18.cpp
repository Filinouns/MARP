// Andrés Puente Rodriguez
// MARP34
// Problema18 -> ¿Cúal es el mejor camino?

#define MAXIMUS 5000

#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>

#include "GrafoValorado.h"

using namespace std;

void resuelveConsulta(GrafoValorado<int> &g, int ini, int fin) {
	vector<bool> marked_(g.V(), false);
	vector<pair<int, int>> dist_t(g.V(), pair<int, int>(MAXIMUS, MAXIMUS));
	queue<int> q;

	q.push(ini);
	marked_[ini] = true;
	dist_t[ini].first = 0;
	dist_t[ini].second = 0;

	int shorter = MAXIMUS;
	pair<int, int> fast_path(MAXIMUS, MAXIMUS);

	while (!q.empty()) {
		int v = q.front(); q.pop();
		//marked_[v] = true;
		for (Arista<int> w : g.ady(v)) {
			int w1 = w.otro(v);
			int nextStep = w.valor() + dist_t[v].first;
			dist_t[w1].first = min(dist_t[w1].first, nextStep);
			dist_t[w1].second = dist_t[v].second + 1;
			if (!marked_[w1]) {
				if (w1 != fin) {
					q.push(w1);
					marked_[w1] = true;
				}
				else {
					//dist_t[w1].second = dist_t[min()].second + 1;
					shorter = min(dist_t[w1].second, shorter);
					if (dist_t[w1].first < fast_path.first) {
						fast_path = dist_t[w1];
					}
				}
			}
		}
	}

	if (fast_path.first != MAXIMUS) {
		cout << fast_path.first;
		if (fast_path.second == shorter) cout << " SI\n";
		else cout << " NO\n";
	}
	else {
		cout << "SIN CAMINO\n";
	}

}

bool resuelveCaso() {

	int v, e;
	cin >> v;
	if (!cin) return false;

	GrafoValorado<int> g(v);

	cin >> e;

	int a1, a2, l;
	for (int i = 0; i < e; i++) {
		cin >> a1 >> a2 >> l;
		a1--;
		a2--;
		Arista<int> a(a1, a2, l);
		g.ponArista(a);
	}

	int consultas;
	cin >> consultas;
	for (int i = 0; i < consultas; i++) {
		int ini, fin;
		cin >> ini >> fin;
		ini--;
		fin--;
		resuelveConsulta(g, ini, fin);
	}

	cout << "---\n";

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