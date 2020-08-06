// Andrés Puente Rodriguez
// MARP34
// Problema24 -> Seis grados de separacion

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "Grafo.h"

using namespace std;

const int INF = 1000000000;

void Floyd(const vector<vector<int>> &g, vector<vector<int>> &C, vector<vector<int>> &camino) {
	int N = g.size() - 1;
	// init
	C = g;
	camino = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	// actualizaciones de la matriz
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int temp = C[i][k] + C[k][j];
				if (temp < C[i][j]) { // es mejor pasar por k
					C[i][j] = temp;
					camino[i][j] = k;
				}
			}
		}
	}
}

void imp_camino_int(int i, int j, const vector<vector<int>>& camino) {
	int k = camino[i][j];
	if (k > 0) {
		imp_camino_int(i, k, camino);
		cout << "" << k;
		imp_camino_int(k, j, camino);
	}
}

void imprimir_caminos(const vector<vector<int>>& C, const vector<vector<int>>& camino) {
	int n = C.size() - 1; 
	int max = -1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && C[i][j] < INF) {
				max = std::max(C[i][j], max);

				// Si queremos la informacion de todos los caminos
				//cout << "Camino de" << i << "a" << j << "\n";
				//cout << "Coste:" << C[i][j] << "\n"; 
				//cout << "" << i; 
				//imp_camino_int(i, j, camino); 
				//cout << "" << j << "\n"; 
			} 

	cout <<  max << '\n';
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int P, R;
	if (!cin) return false;
	else cin >> P >> R;

	Grafo g(P);

	//Dictionary
	std::map<string, int> personas;
	char aux;

	// Quitamos el '\n'
	cin.get(aux);

	// Nonbre 1 y 2
	string n, n1;

	// Generamos el grafo
	for (int i = 0; i < R; i++) {
		getline(cin, n, ' ');
		getline(cin, n1, '\n');

		if(personas.find(n) == personas.end()) personas.insert(std::pair<string, int>(n, personas.size() + 1));
		if (personas.find(n1) == personas.end()) personas.insert(std::pair<string, int>(n1, personas.size() + 1));

		g.ponArista(personas.at(n) - 1, personas.at(n1) - 1);
	}

	// Quitamos el \n
	cin.get(aux);

	// Preparamos los datos para Floyd

	// Iniciamos la tabla de equivalencia con los vertices
	vector<vector<int>> grafo(g.V() + 1, vector<int>(g.V() + 1, INF));
	for (int u = 1; u <= g.V(); ++u)
		grafo[u][u] = 0; 

	// Leemos las aristas de cada vertice
	for (int i = 0; i < g.V(); ++i) {
		int e = g.ady(i).size();
		for (int j = 0; j < e; j++) {
			grafo[i+1][g.ady(i).at(j) + 1] = 1;
		}
	}

	// Vectores auxiliares
	vector<vector<int>> C(0, vector<int>(0));
	vector<vector<int>> camino(0, vector<int>(0));
	
	// Floyd -> Coste O(n^3) en tiempo y O(1) en espacio adicional
	Floyd(grafo, C, camino);

	bool desconectado = false;
	for (int j = 1; j < C.size(); j++) {
		if (C[1][j] > C.size() + 1 && !desconectado) {
			desconectado = true;
		}
	}

	if(!desconectado) imprimir_caminos(C, camino);
	else std::cout << "DESCONECTADA\n";

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