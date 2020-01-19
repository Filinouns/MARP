// Andrés Puente Rodriguez
// MARP34
// Problema31 -> Esquiando en Alaska

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int resuelve_voraz(vector<int> people, vector<int> skis) {
	int suma = 0;



	return suma;
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int N;

	int p, e;

	cin >> N;
	if (!cin) return false;

	vector<int> people_;
	vector<int> skis_;

	for (int i = 0; i < N; i++) {
		cin >> p >> e;
		people_.push_back(p);
		skis_.push_back(e);
	}

	resuelve_voraz(people_, skis_);

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