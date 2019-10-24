// Andrés Puente Rodriguez
// MARP34
// Problema14 -> Petroleros hundidos

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

using Mapa = vector<string>;	//grafo implícito en el mapa 

class Manchas {
public:
	Manchas(Mapa const &M) :	F(M.size()), C(M[0].size()), 
								marked(F, vector<bool>(C, false)), 
								_numero(0), _maximo(0) {
		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) {
				if (M[i][j] == '#' && !marked[i][j]) {
					//se recorre una nueva mancha
					++_numero;
					int nuevotam = 0;
					dfs(M, i, j, nuevotam);
					_maximo = max(_maximo, nuevotam);
				}
			}
		}
	}

	void updateMaximo(Mapa const &M, int i, int j) {
		vector<vector<bool>> newMarked(M.size(), vector<bool>(M[0].size(), false));
		marked = newMarked;

		int nTam = 0;

		dfs(M, i, j, nTam);
		_maximo = max(_maximo, nTam);
	}

	int numero() const { return _numero; }
	int maximo() const { return _maximo; }

private:
	int F, C;						// tamaño del mapa 
	vector<vector<bool>> marked;	// marked[i][j] = se ha visitado <i,j>?
	int _numero;					// número de manchas
	int _maximo;					// tamaño de la mancha más grande

	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}

	const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1}, {1, 1}, {-1, -1} ,{-1, 1}, {1, -1} };

	//recorrido en profundidad de la mancha del vértice <i,j>
	void dfs(Mapa const &M, int i, int j, int&tam) {
		marked[i][j] = true; 
		++tam;
		for (auto d : dirs) {
			int ni = i + d.first,
				nj = j + d.second;
			if (correcta(ni, nj) && M[ni][nj] == '#' && !marked[ni][nj]) {
				dfs(M, ni, nj, tam);
			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int F, C; 
	cin >> F >> C;	//número de filas y columnas 
	if(!cin) return false;

	// Limpiamos el buffer
	cin.clear();
	cin.ignore();

	Mapa mapa(F);
	
	//leemos la imagen
	for(string &linea : mapa) {
		getline(cin, linea);
	}

	vector<pair<int, int>> mE;
	long n_Manchas;

	cin >> n_Manchas;

	for (int i = 0; i < n_Manchas; i++) {
		pair<int, int> mancha;
		int x, y;
		cin >> x >> y;
		x--; y--;
		mancha.first = x;
		mancha.second = y;
		mE.push_back(mancha);
	}
	
	//Escribimos la mancha mas grande
	Manchas manchas(mapa);
	cout << manchas.maximo();

	for (int i = 0; i < n_Manchas; i++) {
		mapa[mE[i].first][mE[i].second] = '#';
		manchas.updateMaximo(mapa, mE[i].first, mE[i].second);
		cout << " " << manchas.maximo();
	}

	cout << '\n';

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