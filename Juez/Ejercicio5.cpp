// Andrés Puente Rodriguez
// MARP34
// Problema5 -> Volando Drones

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>

using namespace std;
/*
struct battery {
	long time;
};

bool operator<(const battery &a, const battery &b) {
	return a.time < b.time;
}
*/

// función que resuelve el problema
long resolver(long n_Drones, priority_queue<long, vector<long>, greater<long>> &pqA, priority_queue<long, vector<long>, greater<long>> &pqB) {
	long horasA = 0, horasB = 0;



	return max(horasA, horasB);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long n_Drones, n_Pilas_A, n_Pilas_B;
	priority_queue<long, vector<long>, greater<long>> pqA;
	priority_queue<long, vector<long>, greater<long>> pqB;

	cin >> n_Drones >> n_Pilas_A >> n_Pilas_B;

	if (!cin)
		return false;

	long t;

	for (auto i = 0; i < n_Pilas_A; i++) {
		cin >> t;
		pqA.push(t);
	}

	for (auto i = 0; i < n_Pilas_B; i++) {
		cin >> t;
		pqB.push(t);
	}

	resolver(n_Drones, pqA, pqB);
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