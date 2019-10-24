// Andrés Puente Rodriguez
// MARP34
// Problema13 -> La ronda de la noche

#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>

#include "Grafo.h"

using namespace std;

class bst {
public:
	bst(const Grafo &g, vector<char> &d, int ini) : marked_(g.V(), false), dist_(g.V()), bip(false) {
		resolve(g, d, ini);
	}

	//void searchCamino(int ini)

	void solucion() {
		if (bip) cout << dist_[exit] << "\n";
		else cout << "NO\n";
	}


private:
	vector<bool> marked_;
	vector<int> dist_;

	int exit;
	bool bip;

	void resolve(const Grafo &g, vector<char> &d, int e) {
		priority_queue<int> q;
		marked_[e] = true;
		dist_[e] = 0;
		q.push(e);

		while (!q.empty() && !bip) {
			int v = q.top(); q.pop();
			for (int z : g.ady(v)) {
				switch (d[z]) {
				case '.':	// En caso de poder seguir el camino
					if (!marked_[z]) {
						marked_[z] = true;
						dist_[z] = dist_[v] + 1;
						q.push(z);
					}
					break;
				case '#':	// En caso de encontrar una pared
					if (!marked_[z]) marked_[z] = true;
					break;
				case 'P':	// En caso de encontrar la salida
					if (!marked_[z]) {
						marked_[z] = true;
						dist_[z] = dist_[v] + 1;
						exit = z;
						bip = true;
					}
					break;
				case 'E':
					break;
				default: //Usarlo aqui para las camaras, ya que no hay casos que las incluyan
					if (!marked_[z]) marked_[z] = true;
					break;
				}
			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n_Gardens = 0;

	cin >> n_Gardens;

	long ancho, alto;

	for (int i = 0; i < n_Gardens; i++) {
		cin >> ancho;
		cin >> alto;

		int v = ancho * alto;

		priority_queue<int> cameras;
		vector<char> data;
		Grafo g(v);

		int init;

		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				int c1 = j + i * ancho;			//Arista inicial que debe unirse a las dos inferiores
				int c2 = c1 + 1;				//Arista a la der de la inicial
				int c3 = j + (i + 1) * ancho;	//Arista bajo la inicial
				
				//Comprobaciones para no pasarnos de ancho/largo del tablero
				if(j < ancho - 1) g.ponArista(c1, c2);
				if(i < alto - 1) g.ponArista(c1, c3);

				// Info de la casilla actual
				char info;
				cin >> info;
				data.push_back(info);

				if (info == 'E') init = data.size() - 1;	// Guardamos la posicion de la entrada para comenzar a buscar desde ahi
				else if (info - '0' >= 0 && info - '9' <= 0) cameras.push(data.size() - 1);
			}
		}

		// Actualizacion del tablero con las distancias de las camaras
		while(!cameras.empty()) {
			int cam = cameras.top(); cameras.pop();
			char vision = data[cam];

			if (vision != '0') {
				if (vision == '1') {
					for (int z : g.ady(cam)) {
						data[z] = vision;
					}
				}
				else {
					int size = vision - '0';
					int camV = 0, limIzq = 0, limDer = 0;
					int auxH = ancho;
					bool bIzq = true, bDer = true, bUp = true, bDown = true;
					for (int i = 0; i < size; i++) {
						// Hacia abajo
						camV = cam - auxH;
						if (camV >= 0 && bDown) {
							if(data[camV] == '.') data[camV] = vision;
							else bDown = false;
						}
						//Hacia arriba
						camV = cam + auxH;
						if (camV <= alto * ancho && bUp) {
							if (data[camV] == '.') data[camV] = vision;
							else bUp = false;
						}
						//Hacia la izq
						camV = cam - (i + 1);
						limIzq = (camV / ancho) * ancho;
						if(camV >= limIzq && bIzq){
							if (data[camV] == '.') data[camV] = vision;
							else bIzq = false;
						}
						//Hacia la der
						camV = cam + (i + 1);
						limDer = ((camV / ancho) + 1) * ancho;
						if (camV <= limDer && bDer) {
							if (data[camV] == '.') data[camV] = vision;
							else bDer = false;
						}

						auxH += ancho;
					}
				}
			}
		}

		bst b(g, data, init);
		b.solucion();
	}

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Text.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}