// Andr�s Puente Rodriguez
// MARP34
// Problema19A -> Perseo rescata a Andromeda

#define MAXIMUS 100000

#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>

#include "GrafoDirigidoValorado.h"

using namespace std;

int calculaTime(GrafoDirigidoValorado<int> const &gdv, vector<int> const &t_islas, int ini, int fin) {

	vector<bool> marked_(gdv.V(), false);
	vector<int> dist_(gdv.V(), MAXIMUS);

	if (ini == fin) {
		dist_[ini] = t_islas[ini];
	}
	else {
		queue<int> q;

		q.push(ini);
		marked_[ini] = true;
		dist_[ini] = 0;

		while (!q.empty()) {
			int v = q.front(); q.pop();

			for (AristaDirigida<int> w : gdv.ady(v)) {
				int w1 = w.to();
				dist_[w1] = min(dist_[w1], dist_[v] + w.valor() + t_islas[w1]);

				if (!marked_[w1]) {
					marked_[w1] = true;
					q.push(w1);
				}
			}
		}
	}
	cout << dist_[fin] << "\n";

	return dist_[fin];
}

bool resuelveCaso() {
	int I, N, L, A, O;

	cin >> I >> N >> L >> A >> O;
	if (!cin) return false;
	A--;
	O--;

	GrafoDirigidoValorado<int> gdv(I);

	// Lectura de datos
	// Tiempo de las islas
	vector<int> t_islas(I);
	for (int i = 0; i < I; i++) {
		int t;
		cin >> t;
		t_islas[i] = t;
	}

	// Nado entre islas
	AristaDirigida<int> ar;
	for (int i = 0; i < N; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		a--;
		b--;
		ar = AristaDirigida<int>(a, b, d);
		gdv.ponArista(ar);
	}

	// Islas donde hay llaves
	vector<int> llaves;
	int l;
	for (int i = 0; i < L; i++) {
		cin >> l;
		l--;
		llaves.push_back(l);
	}

	// Comienza la magia
	bool posible = false;

	int llaveMasRapida = MAXIMUS;
	for (int i = 0; i < L; i++) {
		llaveMasRapida = min(calculaTime(gdv, t_islas, A, llaves[i]), llaveMasRapida);
	}



	//cout << llaveMasRapida << "\n";
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