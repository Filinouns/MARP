// Andrés Puente Rodriguez
// MARP34
// Problema6 -> Pájaros en vuelo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>
#include <string>

using namespace std;

// función que resuelve el problema
int resolver(pair<long, long> p, priority_queue<long> &pq) {
	return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	if (!std::cin)
		return false;

	long head, n_pairs;
	cin >> head;
	cin >> n_pairs;

	if (head == 0 && n_pairs == 0) return false;

	priority_queue<long> pq_young;
	priority_queue<long, vector<long>, greater<long>> pq_old;

	bool looking = true;

	while (looking) {
		pair<long, long> pareja_;
		cin >> pareja_.first;
		cin >> pareja_.second;

		if (pareja_.second < pareja_.first) {
			long aux = pareja_.second;
			pareja_.second = pareja_.first;
			pareja_.first = aux;
		}

		if (pareja_.first < head) {
			pq_young.push({ pareja_.first });
		}
		else {
			pq_young.push({ head });
			head = pareja_.first;
		}

		if (pareja_.second < head) {
			pq_old.push({ head });
			head = pareja_.second;
		}
		else {
			pq_old.push({ pareja_.second }); 
		}

		if (head > pq_old.top()) {
			long aux = pq_old.top();
			pq_old.pop();
			pq_old.push(head);
			head = aux;
		}
		if (head < pq_young.top()) {
			long aux = pq_young.top();
			pq_young.pop();
			pq_young.push(head);
			head = aux;
		}

		n_pairs--;
		if (n_pairs == 0)
			looking = false;

		cout << head << " ";
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
	while (resuelveCaso());
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}