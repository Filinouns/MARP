// Andrés Puente Rodriguez
// MARP34
// Problema23 -> Subsecuencia comun mas larga

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int subsecuencia_pd(const vector<char> &a, const vector<char> &b) {
	
	int n = a.size() + 1;
	int m = b.size() + 1;

	vector<vector<int>> sc(n, vector<int>(m, 0));

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (a[i-1] == b[j-1]) {
				// Si son la misma letra comprobamos entre 
				sc[i][j] = sc[i - 1][j - 1] + 1;
			}
			else {
				sc[i][j] = max(sc[i][j - 1], sc[i - 1][j]);
			}
		}
	}

	return sc[n - 1][m - 1];
}

bool resuelveCaso() {
	// leer los datos de la entrada
	char a;
	vector<char> w1, w2;

	if (!cin) return false;
	else {
		cin.get(a);
		if (a == -52) return false;
		while (a != ' ') {
			w1.push_back(a);
			cin.get(a);
		}
		cin.get(a);
		while (a != '\n') {
			w2.push_back(a);
			cin.get(a);
		}
	}

	std::cout << subsecuencia_pd(w1, w2) << "\n";

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