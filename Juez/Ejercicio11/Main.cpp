// Andrés Puente Rodriguez
// MARP34
// Problema11 -> Colocar a los Guardias

#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <queue>

#include "Grafo.h"

using namespace std;

class bst {
public:

	bst(const Grafo &g, int v) : marked_(g.V(), false), dist_(g.V()) {
		bip = true;
		n_Guards_g0 = 0;
		n_Guards_g1 = 0;

		//Recorremos los elementos del grafo
		for (int i = 0; i < g.V(); i++) {
			//Si no esta marcado llamamos a resolverlo, de esta manera nos aseguramos que recorremos los elementos sueltos
			if (!marked_[i]) {
				resolve(g, i);
			}
			if (dist_[i] % 2 == 0) n_Guards_g0++;
			else n_Guards_g1++;
		}
	}

	void solucion() {
		if (bip) cout << "SI\n";
		else cout << "NO\n";
	}

	void nGuards() {
		if (bip) cout << min(n_Guards_g0, n_Guards_g1) << "\n";
		else cout << "IMPOSIBLE\n";
	}


private:
	vector <bool> marked_;
	vector <int> dist_;

	long n_Guards_g0;
	long n_Guards_g1;
	bool bip;

	void resolve(const Grafo &g, int e) {
		// Creamos una cola de prioridad con el elemento (e)
		priority_queue<int> q;
		dist_[e] = 0; //La distancia a e se toma como 0
		marked_[e] = true;
		q.push(e);

		//Mientras que sigamos escuchando el latido (bip) y haya elementos en la cola, comprobamos:
		while (!q.empty() && bip) {
			int v = q.top(); q.pop(); //Cogemos el elem
			for (int z : g.ady(v)) { //Recorremos los hijos del elem
				if (!marked_[z]) { // Si no estan los hijos marcados
					dist_[z] = dist_[v] + 1; //Le damos 1 mas de distancia del elemento (v)
					marked_[z] = true; //Marcamos
					q.push(z); //Lo añadimos a la cola para que se recorran sus hijos
				}
				else { // Si el hijo esta marcado se comprobara que la distancia entre ellos sea siempre diferente
					if (dist_[z] % 2 == 0 && dist_[v] % 2 == 0) bip = false;
					else if (dist_[z] % 2 != 0 && dist_[v] % 2 != 0) bip = false;
				}
			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	long V, E;

	cin >> V;
	cin >> E;

	if (!cin) return false;

	Grafo g(V);

	for (int i = 0; i < E; i++) {
		long v, w;
		cin >> v >> w;
		v--; w--;
		g.ponArista(v, w);
	}

	bst sol(g, 0);
	sol.nGuards();

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