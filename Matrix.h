#pragma once
#include "AbstractFrame.h"

template <class T>
class Matrix{

private:
	int n;
	int m;
	std::vector<T> tab;

public :
	Matrix();
	Matrix(const Matrix<T>&);
	Matrix(int, int);
	~Matrix();



	T getValue(std::pair<int, int>);
	AbstractFrame* getValue(int, int);

	void setValue(int, int, T);

	int getNbColumns() const;
	int getNbLines() const;

	std::vector<std::pair<int, int>> couplesArround(int, int);
	void print();


};

template <class T>
Matrix<T>::Matrix() {
	n = 0;
	m = 0;
}

template <class T>
Matrix<T>::Matrix(const Matrix& other) {
	n = other.n;
	m = other.m;
	for (int i = 0; i < n * m; i++) {
		tab.insert(i, other.tab.at(i));
	}
}

template <class T>
Matrix<T>::Matrix(int nLine, int mColumn) {
	n = nLine;
	m = mColumn;
	for (int i = 0; i < n * m; i++) {
		tab.push_back(nullptr);
	}
}

template <class T>
Matrix<T>::~Matrix() {
}

template <class T>
AbstractFrame* Matrix<T>::getValue(int i, int j) {
	if (i < 0 || i > n - 1 || j < 0 || j > m - 1) {
		return nullptr;
	}
	return tab.at(m * i + j);
}

template <class T>
T Matrix<T>::getValue(std::pair<int, int> c) {
	return getValue(c.first, c.second);
}

template <class T>
void Matrix<T>::setValue(int i, int j, T value) {
	tab.at(m * i + j) = value;
}

template <class T>
int Matrix<T>::getNbColumns() const {
	return m;
}

template <class T>
int Matrix<T>::getNbLines() const {
	return n;
}

template <class T>
std::vector<std::pair<int, int>> Matrix<T>::couplesArround(int i, int j) {
	std::vector<std::pair<int, int>> result;
	std::pair<int, int> h(i - 1, j);
	std::pair<int, int> b(i + 1, j);
	std::pair<int, int> g(i, j - 1);
	std::pair<int, int> d(i, j + 1);
	if (getValue(h) != nullptr)	result.push_back(h);
	if (getValue(b) != nullptr)	result.push_back(b);
	if (getValue(g) != nullptr)	result.push_back(g);
	if (getValue(d) != nullptr)	result.push_back(d);
	return result;
}

template <class T>
void Matrix<T>::print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%p\t", getValue(i, j));
		}
		std::cout << "\n";
	}
}
