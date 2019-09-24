// Andrés Puente Rodriguez
// MARP34
// Problema -> Lo que cuesta sumar

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>
using namespace std;

// función que resuelve el problema
long resolver(priority_queue<long, vector<long>, greater<long>> &datos) {
	long sol = 0;
	while (datos.size() > 1) {
		long n1, n2;

		n1 = datos.top();
		datos.pop();
		n2 = datos.top();
		datos.pop();

		n1 = n1 + n2;
		datos.push(n1);
		sol += n1;
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	long size;

	if (!cin)
		return false;
	else {
		cin >> size;
	}

	if (size == 0) return false;

	priority_queue<long, vector<long>, greater<long>> pq;
	long aux;

	for (auto i = 0; i < size; i++) {
		cin >> aux;
		pq.push(aux);
	}

	long sol = resolver(pq);

	// escribir sol
	cout << sol << "\n";

	// Para leer la cola
	/*
	for (auto i = 0; i < size; i++) {
		aux = pq.top();
		cout << aux << " ";
		pq.pop();
	}

	cout << endl;
	*/

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