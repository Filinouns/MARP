// Andrés Puente Rodriguez
// MARP34
// Problema20 -> La cuerda de la cometa

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;


//Ejemplo del problema de la mochila
// Numero maximo de objetos que puedes llevar con su mayor valor sin pasarse del peso de la mochila
void mochila_pd (vector<int>const&P, vector<int>const&V, int M, int&valor, vector<bool>&cuales) {//PyV1-based
	int n = P.size();

	vector<vector<int>> mochila = vector<vector<int>>(n, vector<int>(M + 1));

	//rellenar la matriz
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= M; ++j) {
			if(P[i] > j)
				mochila[i][j] = mochila[i-1][j];
			else
				mochila[i][j] = max(mochila[i-1][j],mochila[i-1][j - P[i]] + V[i]);
		}
	}
	valor = mochila[n][M];
	//cálculo de los objetos
	int resto = M;
	for(int i = n; i >= 1; --i) {
		if(mochila[i][resto] == mochila[i-1][resto]) {//no cogemos objeto i
			cuales[i] =false;
		}else{//sí cogemos objeto i
			cuales[i] =true;
			resto = resto - P[i];
		}
	}
}

// función que resuelve el problema
void resolver(long n_Drones, priority_queue<long, vector<long>, less<long>> &pqA, priority_queue<long, vector<long>, less<long>> &pqB) {

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	
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