// Andrés Puente Rodriguez
// MARP34
// Problema30 -> Agujeros en la manguera

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int calcula_voraz(vector<bool> &cogidos, vector<int> holes, int s) {
	int n_Parches = 0;
	int agujero;
	for (int i = 0; i < holes.size(); i++) {
		agujero = holes[i];
		cogidos[agujero - 1] = true;
		n_Parches++;

		int pos = agujero + s;
		bool fin = false;

		if (i + 1 < holes.size()) {
			while (!fin && holes[i + 1] <= pos) {
				i++;
				if (i + 1 >= holes.size()) { fin = true; }
			}
		}
	}

	return n_Parches;
}


bool resuelveCaso() {
	// leer los datos de la entrada
	int n_Agujeros, size_parche;

	cin >> n_Agujeros >> size_parche;
	if (!cin) return false;

	vector<int> holes_;
	int aux, m = 0;

	for (int i = 0; i < n_Agujeros; i++) {
		cin >> aux;
		holes_.push_back(aux);
		m = max(m, aux);
	}

	vector<bool> cogidos(m);
	vector<bool> optima(m);
	
	cout << calcula_voraz(cogidos, holes_, size_parche) << "\n";

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