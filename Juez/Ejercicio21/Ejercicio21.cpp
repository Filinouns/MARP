// Andrés Puente Rodriguez
// MARP34
// Problema21 -> El cazatesoros

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Tesoro {
	int deep_, money_;
	void set(int p, int d) {
		deep_ = p;
		money_ = d;
	}
};

void cazatesoros_pd(vector<Tesoro> tesoros, int T) {
	int n = tesoros.size() - 1;

	vector<vector<int>> m(n + 1, vector<int>(T + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= T; j++) {
			if (j < tesoros[i].deep_) m[i][j] = m[i - 1][j];
			else m[i][j] = max(m[i - 1][j], m[i - 1][j - tesoros[i].deep_] + tesoros[i].money_);
		}
	}

	// Maximo numero de monedas que podemos obtener
	cout << m[n][T] << "\n";

	stack<Tesoro> elegidisimos;

	int resto = T;
	for (int i = n; i >= 1; --i) {
		if (m[i][resto] == m[i - 1][resto]) {
			// no cogemos objeto i 
		}
		else {
			// sí cogemos objeto i 
			resto = resto - tesoros[i].deep_;
			elegidisimos.push(tesoros[i]);
		}
	}

	// Escribimos por pantalla aquellos cofres que hemos escogido
	cout << elegidisimos.size() << "\n";

	while (!elegidisimos.empty()) {
		Tesoro first = elegidisimos.top();	elegidisimos.pop();
		cout << first.deep_ / 3 << " " << first.money_ << "\n";
	}
	cout << "----\n";
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int tiempo_botella, n_tesoros;

	cin >> tiempo_botella >> n_tesoros;
	if (!cin) return false;

	vector<Tesoro> tesoros;
	vector<bool> cogidos(n_tesoros, false);

	Tesoro t = { 0, 0 };
	tesoros.push_back(t);

	int p, d;

	for (int i = 0; i < n_tesoros; i++) {
		cin >> p >> d;
		p *= 3;
		Tesoro newTesoro;
		newTesoro.set(p, d);
		tesoros.push_back(newTesoro);
	}

	cazatesoros_pd(tesoros, tiempo_botella);

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