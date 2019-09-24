// Andrés Puente Rodriguez
// MARP34
// Problema4 -> La reina del super (UCM)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>

using namespace std;

struct client_ {
	long time;
	long box;
};

bool operator<(const client_ &a, const client_ &b) {
	return a.time > b.time || a.time == b.time && a.box > b.box;
}

// función que resuelve el problema
void resolver(long n_Cajas, long n_Clients) {
	
	priority_queue<client_> pq;

	long freeBox = 1;
	long full_time = 0;
	bool firstIn = true;

	while (n_Clients--) {
		long t;
		cin >> t;
		long b;

		if (!firstIn) {
			client_ c = pq.top();
			full_time = pq.top().time;
			t += full_time;
			c.time = t;
			pq.pop();
			pq.push(c);
		}
		else {
			pq.push({ t, freeBox });
			if (freeBox == n_Cajas) firstIn = false;
			else freeBox++;
		}
	}

	long selectedBox;

	if (firstIn) selectedBox = freeBox;
	else selectedBox = pq.top().box;

	cout << selectedBox << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long n_Cajas;
	long n_Clients;

	if (!cin)
		return false;
	else {
		cin >> n_Cajas;
		cin >> n_Clients;
	}

	if (n_Cajas == 0 && n_Clients == 0) return false;

	resolver(n_Cajas, n_Clients);
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