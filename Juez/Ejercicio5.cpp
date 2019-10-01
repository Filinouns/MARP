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
void resolver(long n_Drones, priority_queue<long, vector<long>, less<long>> &pqA, priority_queue<long, vector<long>, less<long>> &pqB) {
	bool resuelto = false;
	long horasA = 0, horasB = 0;
	vector<long> v_Sabados;

	while (!resuelto) {

		long horas_Sabado = 0;

		for (int i = 0; i < n_Drones; i++) {
			if (pqA.size() != 0 && pqB.size() != 0) {
				horasA = pqA.top();
				horasB = pqB.top();

				pqA.pop();
				pqB.pop();

				if (horasA > horasB) {
					horasA -= horasB;
					horas_Sabado += horasB;
					horasB = 0;
				}
				else {
					horasB -= horasA;
					horas_Sabado += horasA;
					horasA = 0;
				}

				if (horasA != 0) pqA.push(horasA);
				if (horasB != 0) pqB.push(horasB);
			}
			else {
				resuelto = true;
			}
		}
		if (pqA.size() == 0 || pqB.size() == 0) resuelto = true;
		v_Sabados.push_back(horas_Sabado);
	}

	for (int i = 0; i < v_Sabados.size(); i++) {
		cout << v_Sabados[i] << " ";
	}
	cout << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long n_Drones, n_Pilas_A, n_Pilas_B;
	priority_queue<long, vector<long>, less<long>> pqA;
	priority_queue<long, vector<long>, less<long>> pqB;

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