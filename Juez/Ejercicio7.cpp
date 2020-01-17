// Andrés Puente Rodriguez
// MARP34
// Problema7 -> Las partituras de la orquesta

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>

using namespace std;

// Hay que tener en cuenta que en un grupo de 18 musicos y 3 partituras la mejor manera de ordenarlo es en 3 grupos de 6
// NO 18 -> 9, 9 -> 9, 5, 4

struct group_ {
	long people;
	long p;
};

bool operator<(const group_ &a, const group_ &b) {
	long g1 = (a.people / a.p), g2 = (b.people / b.p);
	if (a.people % a.p != 0) g1++;
	if (b.people % b.p != 0) g2++;
	return g1 < g2;
}

/*
class Grupo {
public:
	Grupo(long n) : n_Musicos(n), prioridad(n) {
		partituras = 0;
	}

	void daPartitura() {
		partituras++;
		if (n_Musicos % partituras == 0) {
			prioridad = n_Musicos / partituras;
		}
		else {
			prioridad = n_Musicos / partituras + 1;
		}
	}

private:
	long n_Musicos;
	long partituras;
	long prioridad;
};
*/

// función que resuelve el problema
long resolver(long p, priority_queue<group_> &pq) {
	
	group_ a;

	while (p != 0) {
		//long g1, g2;
		a = pq.top();
		pq.pop();

		a.p++;

		pq.push(a);

		/*g1 = a / 2;
		g2 = a - g1;

		pq.push(g1);
		pq.push(g2);*/

		p--;
	}

	a = pq.top();
	long g = a.people / a.p;
	if (a.people % a.p != 0) g++;

	return g;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long n_instrumentos, n_partituras;
	priority_queue<group_> organitation_;

	cin >> n_partituras >> n_instrumentos;

	if (!cin)
		return false;

	group_ elem;
	for (int i = 0; i < n_instrumentos; i++) {
		cin >> elem.people;
		elem.p = 1;
		organitation_.push(elem);
	}

	n_partituras -= n_instrumentos;

	cout << resolver(n_partituras, organitation_) << '\n';

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