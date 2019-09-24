// Andrés Puente Rodriguez
// MARP34
// Problema7 -> Las partituras de la orquesta

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>

using namespace std;

// función que resuelve el problema
long resolver(long p, priority_queue<long, vector<long>, less<long>> &pq) {
	while (p != 0) {
		long a;
		long g1, g2;
		a = pq.top();
		pq.pop();

		g1 = a / 2;
		g2 = a - g1;

		pq.push(g1);
		pq.push(g2);

		p--;
	}

	return pq.top();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long n_instrumentos, n_partituras;
	priority_queue<long, vector<long>, less<long>> organitation_;

	cin >> n_partituras >> n_instrumentos;

	if (!cin)
		return false;

	long elem;
	for (int i = 0; i < n_instrumentos; i++) {
		cin >> elem;
		organitation_.push(elem);
	}

	n_partituras -= n_instrumentos;

	cout << resolver(n_partituras, organitation_) << '\n';

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