// Andrés Puente Rodriguez
// MARP34
// Problema12 -> Las noticias vuelan

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

using Grafo = vector<vector<int>>;

class Noticias {
public:
	Noticias(Grafo const& g) : marked_(g.size(), false), component_(g.size()) {
		for (int i = 0; i < g.size(); i++) {
			if (!marked_[i]) {
				int tam = dfs(g, i);
				sizes_.push_back(tam);
			}
		}
	}

	int solucion(int v) {
		return sizes_[component_[v]];
	}

private:
	vector<bool> marked_;
	vector<int> component_;
	vector<int> sizes_;

	int dfs(Grafo const& g, int e) {
		int t = 1;

		marked_[e] = true;
		component_[e] = sizes_.size();

		for (int i : g[e]) {
			if (!marked_[i]) {
				t += dfs(g, i);
			}
		}
		return t;
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	long N, M;

	cin >> N >> M;

	if (!std::cin)
		return false;

	Grafo g(N);

	long grupo, u, v;

	for (int j = 0; j < M; j++) {

		cin >> grupo;
		if (grupo > 0) {
			cin >> u;
			u--;
			for (int i = 1; i < grupo; i++) {
				cin >> v;
				v--;
				g[u].push_back(v);
				g[v].push_back(u);
				u = v;
			}
		}
	}

	Noticias n(g);

	for (int i = 0; i < g.size(); i++) {
		cout << n.solucion(i) << ' ';
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