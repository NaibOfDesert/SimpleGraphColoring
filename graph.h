#pragma once
#include <iostream>
#include <string>

struct ListElement {
	int number;
	ListElement* next_element;
};

class Graph
{
private:
	int graph_size;
	int max_top;
	int chromatic_number;
	int bonds_quantity;
	int* collor_elements_array;
	bool* collor_able_array;
	int** matrix_array;
	ListElement** list_element_array; // tablica list sasiedztwa
	std::string matrix_loaded;
public:
	Graph();
	Graph(int graph_size_);
	void Loader();
	void NewMatrixArray();
	void NewElementArray();
	void FillElementArray();
	void SetColors();
	void GetChromaticNumber();
	bool IsChromaticBiggerThenTop();
	void DeleteElementArray();
	void DeleteMatrixArray();
	~Graph();
};

