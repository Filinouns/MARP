// Andrés Puente Rodriguez
// MARP34
// Problema17 -> Recorriendo el archipielago en bicicleta

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>

#include "GrafoValorado.h"

using namespace std;

bool operator<(const Arista<long> &a, const Arista<long> &b) {
	return a.valor < b.valor;
}

template<class T> 
class MyQueue : public priority_queue<T> {
public:
	bool find(const T&val) const {
		auto first = this->c.cbegin();
		auto last = this->c.cend();
		while (first != last) {
			if (*first == val) return true;
			++first;
		}
		return false;
	}
};

class PrimMST {
public:
	PrimMST(GrafoValorado<long> &G) : costTo_(G.V(), 100001), marked_(G.V(), false), edgeTo_(G.V()) {
		costTo_[0] = 0.0;
		for(Arista<long> v : G.ady(0)) pq.push(v);              // Initialize pq with 0, weight 0.

		while (!pq.empty()){
			long v = pq.top().uno(); pq.pop();
			visit(G, v);       // Add closest vertex to tree.
		} 
	}

private:
	vector<bool> marked_;									// true if v on tree   
	MyQueue<Arista<long>> pq;	// eligible crossing edges
	vector<Arista<long>> edgeTo_;
	vector<double> costTo_;
 
	void visit(GrafoValorado<long> &G, long v) {  // Add v to tree; update data structures.      
		marked_[v] = true;
		for (Arista<long> e : G.ady(v)) {
			int w = e.otro(v);
			if (marked_[w]) continue;	// v-w is ineligible.

			if (e.valor() < costTo_[w]) {  //Edge e is new best connection from tree to w.            
				edgeTo_[w] = e;
				costTo_[w] = e.valor();
				if (!pq.find(w))	pq.push(costTo_[w]);
				else				pq.swap(w, costTo_[w]);
			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	long V, bridges;
	cin >> V >> bridges;

	if (!cin) return false;

	GrafoValorado<long> g(V);

	long a, b, cost;
	for (int i = 0; i < bridges; i++) {
		cin >> a >> b >> cost;
		a--;	b--;
		Arista<long> ar(a, b, cost);
		g.ponArista(ar);
	}

	PrimMST prim(g);

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Text.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}