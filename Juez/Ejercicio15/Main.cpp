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

//Busqueda en anchura
class bfsClass {
public:
	bfsClass(GrafoDirigido &g) : marked_(g.V(), false), distTo_(g.V()) {
		bfs(g, 0);
	}

	long distFinal() {
		return distTo_[distTo_.size() - 1];
	}

	void printDist() {
		for (int i = 0; i < distTo_.size(); i++) {
			cout << i << ": " << distTo_[i] << '\n';
		}
	}

private:
	vector<bool> marked_;
	vector<int> distTo_;

	void bfs(GrafoDirigido &g, long c) {
		queue<long> q;
		distTo_[c] = 0;
		marked_[c] = true;
		q.push(c);
		while (!q.empty()) {
			long v = q.front();	q.pop();
			for (long w : g.ady(v)) {
				if (!marked_[w]) {
					distTo_[w] = distTo_[v] + 1;
					marked_[w] = true;
					q.push(w);
				}
			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long size;
	long dado, n_s, n_e;

	cin >> size >> dado >> n_s >> n_e;

	if (size == 0 && dado == 0 && n_s == 0 && n_e == 0) return false;

	GrafoDirigido g(size*size);

	int a, b;
	// Añadir serpientes y escaleras
	for (long i = 0; i < n_s + n_e; i++) {
		cin >> a >> b;
		a--;
		b--;
		g.ponArista(a, b);
	}

	for (long i = 0; i < g.V(); i++) {			// Para cada arista del grafo.
		if (g.ady(i).size() == 0) {				// Para no añadir aristas en aquellas que son serpientes o escaleras, ya que no son 
												// necesarias, si caes ahi saltarias directamente a la casilla que se te dirige.
			for (long j = 0; j <= dado; j++) {	// Si salimos de ahi tendremos diferentes destinos dependiendo del tamaño del dado.
				if (j + i < g.V()) {			// Para no pasarnos de tamaño.
					if (i + j != i) {			// Para que no se añada una arista un vertice consigo mismo.
						if (g.ady(i + j).size() > 0) {		// Si hay alguna escalera o serpiente.
							long z = g.ady(i + j).at(0);
							g.ponArista(i, z);
						}
						else {
							g.ponArista(i, j + i);
						}
					}
				}
			}
		}
	}

	bfsClass solucion(g);

	cout << solucion.distFinal() << '\n';

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