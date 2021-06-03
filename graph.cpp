#include "Graph.h"

Graph::Graph() {
	graph_size = 0;
	max_top = 0;
	chromatic_number = 0;
	bonds_quantity = 0;
	collor_elements_array = nullptr;
	collor_able_array = nullptr;
	matrix_array = nullptr;
	list_element_array = nullptr;
	NewMatrixArray();
	NewElementArray();
}

Graph::Graph(const int graph_size_) {
	graph_size = graph_size_;
	max_top = 0;
	chromatic_number = 0;
	bonds_quantity = 0;
	collor_elements_array = nullptr;
	collor_able_array = nullptr;
	matrix_array = nullptr;
	list_element_array = nullptr;
	NewMatrixArray();
	NewElementArray();
}

void Graph::Loader() {
	int matrix_index = 0;
	// wczytywanie macierzy w linii
	std::cin >> matrix_loaded;
	// tworzenie tablicy dwuwymiarowej
	for (int i = 0; i < graph_size; i++) {
		int present_top = 0;
		for (int j = 0; j < graph_size; j++) {
			matrix_array[i][j] = matrix_loaded[matrix_index];
			if (matrix_array[i][j] == '1') {
				present_top++;
				bonds_quantity++;
			}
			matrix_index++;
		}
		if (present_top > max_top) {
			max_top = present_top;
		}
	}
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	/*
	// wypisywanie macierzy
	for (int i = 0; i < graph_size; i++) {
		for (int j = 0; j < graph_size; j++) {
			if (matrix_array[i][j] == '0') {
				cout << "0";
			}
			else cout << "1";
		}
		cout << endl;
	}
	cout << max_top << endl;
	*/
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
// tworzenie tablicy macierzy grafu
void Graph::NewMatrixArray() {
	matrix_array = new int* [graph_size];
	for (int i = 0; i < graph_size; i++) {
		matrix_array[i] = new int[graph_size];
	}
}
// tworzenie listy s¹siedztwa
void Graph::NewElementArray() {
	list_element_array = new ListElement * [graph_size];
	for (int i = 0; i < graph_size; i++) {
		list_element_array[i] = nullptr;
	}
}
// uzupelnianie tablicy sasiadow
void Graph::FillElementArray() {
	for (int i = 0; i < graph_size; i++) {
		for (int j = i + 1; j < graph_size; j++) {
			if (matrix_array[i][j] == '1') {
				ListElement* new_element_array_1 = new ListElement;
				new_element_array_1->number = i;
				// ListElementArray[j] = new_element_array_1;
				new_element_array_1->next_element = list_element_array[j];
				list_element_array[j] = new_element_array_1;

				ListElement* new_element_array_2 = new ListElement;
				new_element_array_2->number = j;
				// ListElementArray[i] = new_element_array_2;
				new_element_array_2->next_element = list_element_array[i];
				list_element_array[i] = new_element_array_2;
			}
		}
	}
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	/*
	// lista sasiadow
	cout << endl;
	for (int v = 0; v < graph_size; v++)
		cout << ListElementArray[v] << endl;
	*/
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
// ustawianie kolorow
void Graph::SetColors() {
	collor_elements_array = new int[graph_size];
	collor_able_array = new bool[graph_size];
	collor_elements_array[0] = 0;
	for (int i = 1; i < graph_size; i++) {
		collor_elements_array[i] = -1;
	}
	for (int i = 1; i < graph_size; i++) {
		for (int j = 0; j < graph_size; j++) {
			collor_able_array[j] = false;
		}
		for (ListElement* k = list_element_array[i]; k; k = k->next_element) {
			if (collor_elements_array[k->number] > -1) {
				collor_able_array[collor_elements_array[k->number]] = true;
			}
		}
		int j;
		for (j = 0; collor_able_array[j]; j++);
		collor_elements_array[i] = j;
	}
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	/*
	// wypisywanie kolorow - do usuniecia
	cout << endl;
	for (int i = 0; i < graph_size; i++)
		cout << "vertex " << i << " has color " << collor_elements_array[i] << endl;
	*/
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
// wylicz liczbê chromatyczna
void Graph::GetChromaticNumber() {
	for (int i = 0; i < graph_size; i++) {
		bool is_color = false;
		for (int j = 0; j < graph_size; j++) {
			if (i == collor_elements_array[j]) {
				is_color = true;
			}
		}
		if (is_color == true) {
			chromatic_number++;
		}
	}
	// cout << "liczba chroamtyczna " << chromatic_number << endl;
}
// czy liczba chromatyczna jest wieksza ni¿ stopien
bool Graph::IsChromaticBiggerThenTop() {
	FillElementArray();
	SetColors();
	GetChromaticNumber();
	if (chromatic_number > max_top) {
		return true;
	}
	else return false;
}

void Graph::DeleteElementArray() {
	for (int i = 0; i < graph_size; i++) {
		delete[] list_element_array[i];
		list_element_array[i] = nullptr;
	}
	delete[] list_element_array;
	list_element_array = nullptr;
}

void Graph::DeleteMatrixArray() {
	for (int i = 0; i < graph_size; i++) {
		matrix_array[i];
		matrix_array[i] = nullptr;
	}
	delete[] matrix_array;
	matrix_array = nullptr;
}

Graph::~Graph() {
	collor_elements_array = nullptr;
	collor_able_array = nullptr;
}