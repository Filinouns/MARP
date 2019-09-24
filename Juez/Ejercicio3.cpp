// Andrés Puente Rodriguez
// MARP34
// Problema3 -> Ordenando a los pacientes en urgencias (UCM)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>
#include <string>

using namespace std;

struct pacient_ {
	string name;
	long gravedad;
	long order;
};

bool operator<(const pacient_ &a, const pacient_ &b) {
	return a.gravedad < b.gravedad || a.gravedad == b.gravedad && a.order < b.order;
}

// función que resuelve el problema
void resolver(long n_Data) {

	priority_queue<pacient_> pq;

	while (n_Data--) {
		char action;
		cin >> action;

		pacient_ p;

		if (action == 'I') {
			cin >> p.name;
			cin >> p.gravedad;
			p.order = n_Data;
			pq.push(p);
		} else if (action == 'A'){
			cout << pq.top().name << "\n";
			pq.pop();
		}
	}
	cout << "---\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long n_Data;

	if (!cin)
		return false;
	else {
		cin >> n_Data;
	}

	if (n_Data == 0) return false;

	resolver(n_Data);
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