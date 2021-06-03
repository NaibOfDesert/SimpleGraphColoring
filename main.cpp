#include <iostream>
#include "Graph.h"

int main() {
	int graph_quantity;
	int graph_size;
	// wyczytywanie ilosci grafow
	std::cin >> graph_quantity;
	// tworzenie tablicy wynikow grafow
	bool* graph_results = new bool[graph_quantity];
	for (int i = 0; i < graph_quantity; i++) {
		graph_results[i] = false;
	}
	// wczytywanie grafu i szuanie rozwiazania
	for (int i = 0; i < graph_quantity; i++) {
		std::cin >> graph_size;
		Graph new_graph = Graph(graph_size);
		new_graph.Loader();
		graph_results[i] = new_graph.IsChromaticBiggerThenTop();
		new_graph.DeleteElementArray();
		new_graph.DeleteMatrixArray();
		new_graph.~Graph();
	}
	// wypisywanie rozwiazan
	for (int i = 0; i < graph_quantity; i++) {
		if (graph_results[i] == true) {
			std::cout << "True" << std::endl;
		}
		else std::cout << "False" << std::endl;
	}
	// zwalnianie pamieci
	delete[] graph_results;
	return 0;
}