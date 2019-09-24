// Andrés Puente Rodriguez
// MARP34
// Problema2 -> Unidad Curiosa de Motorizacion (UCM)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>
//#include "PriorityQueue.h"

using namespace std;

struct user_ {
	long ID;
	long T;

public:
	long ini_T = T;
};

bool operator<(const user_ &a, const user_ &b) {
	return a.T > b.T || a.T == b.T && a.ID > b.ID;
}

// función que resuelve el problema
void resolver(long n_send, priority_queue<user_> &datos) {
	for (int i = 0; i < n_send; i++) {
		user_ u1 = datos.top();
		datos.pop();
		
		cout << u1.ID << '\n';
		u1.T += u1.ini_T;
		datos.push(u1);
	}
	cout << "---\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long n_Users;

	if (!cin)
		return false;
	else {
		cin >> n_Users;
	}

	if (n_Users == 0) return false;

	priority_queue <user_> pq;
	long id, t;

	for (auto i = 0; i < n_Users; i++) {
		cin >> id;
		cin >> t;
		pq.push({ id, t});
	}

	long n_envios;
	cin >> n_envios;

	resolver(n_envios, pq);

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