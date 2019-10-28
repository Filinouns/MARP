// Andrés Puente Rodriguez
// MARP34
// Problema15 -> Serpientes y Escaleras

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void jugada(vector<int> &T, long c, int dado, vector<int> &a) {
	//vector<int> nextPlay;

	for (int i = 1; i <= dado; i++) {
		c++;

		// Por si tiene escalera o serpiente
		if (T[c] != 0) {
			a.push_back(T[c]);
		}
		// Por si hemos llegado al final del tamaño del dado y sera siguiente jugada 100%
		else if (i == dado) {
			// Para no pasarnos del tamaño
			if (c <= T.size()- 1) {
				a.push_back(c);
			}
		}
		// Por si en algun momento llegamos al final
		else if (c == T.size()- 1) {
			a.push_back(c);
		}
	}

	//return nextPlay;
}

int resolver(vector<int> &t, int dado) {
	priority_queue<long, vector<long>, less<long>> nextJugada;
	vector<int> aux;
	vector<int> aux1;
	int n = 0;

	nextJugada.push(0);

	while (nextJugada.top() != t.size()- 1) {
		int z = nextJugada.size();
		for (int j = 0; j < z; j++) {
			long a = nextJugada.top();	nextJugada.pop();
			jugada(t, a, dado, aux);
			for (int i = 0; i < aux.size(); i++) {
				aux1.push_back(aux[i]);
			}
			aux.clear();
		}

		for (int i = 0; i < aux1.size(); i++) {
			nextJugada.push(aux1[i]);
		}
		aux1.clear();
		n++;
	}

	return n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long size;
	long dado, n_s, n_e;

	cin >> size >> dado >> n_s >> n_e;

	if (size == 0 && dado == 0 && n_s == 0 && n_e == 0) return false;

	vector<int> tablero(size*size);

	for (int i = 0; i < n_s; i++) {
		long a, b;
		cin >> a >> b;
		a--;
		b--;
		tablero[a] = b;
	}

	for (int i = 0; i < n_e; i++) {
		long a, b;
		cin >> a >> b;
		a--;
		b--;
		tablero[a] = b;
	}

	cout << resolver(tablero, dado) << '\n';
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