// Andrés Puente Rodriguez
// MARP34
// Problema22 -> Construyendo Dianas

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void diana_pd(vector<int> sectors, int P) {
	int n = sectors.size() - 1;

	vector<vector<int>> m(n+1, vector<int>(P + 1, 1E9));

	m[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		m[i][0] = 0;
		for (int j = 1; j <= P; j++) {
			if (j < sectors[i]) m[i][j] = m[i - 1][j];
			else {
				m[i][j] = min(min(m[i - 1][j], m[i - 1][j - sectors[i]] + 1), m[i][j - sectors[i]] + 1);
			}
		}
	}
	
	bool posible = (m[n][P] != 1E9);

	if (posible) cout << m[n][P] << "\n";
	else cout << "Imposible\n";

}

bool resuelveCaso() {
	// leer los datos de la entrada
	int final_score;
	int n_sectors;
	cin >> final_score >> n_sectors;

	if (!cin) return false;

	vector<int> sectors;
	sectors.push_back(0);
	int s;

	for (int i = 0; i < n_sectors; i++) {
		cin >> s;
		sectors.push_back(s);
	}

	diana_pd(sectors, final_score);

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