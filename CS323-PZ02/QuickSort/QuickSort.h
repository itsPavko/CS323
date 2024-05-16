#pragma once
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<class T>
class QuickSort {
public:
	using Compare = function<bool(const T&, const T&)>;

	void swapElements(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	int splitArray(vector<T>& array, int low, int high, Compare compare) {
		T pivot = array[high];  // Pivot element
		int i = (low - 1);    // Indeks manjeg elementa

		for (int j = low; j <= high - 1; j++) {
			// Ako je trenutni element manji ili jednak pivotu
			if (compare(array[j], pivot)) {
				i++;  // Pomeri indeks manjeg elementa
				swapElements(array[i], array[j]);
			}
		}

		swapElements(array[i + 1], array[high]);
		return (i + 1);
	}

	void quickSort(vector<T>& array, int low, int high, Compare compare) {
		if (low < high) {
			int splitter = splitArray(array, low, high, compare);

			quickSort(array, low, splitter - 1, compare);
			quickSort(array, splitter + 1, high, compare);
		}
	}

	void printVector(const vector<T>& array) {
		for (const auto& item : array) {
			cout << item.id << " " << item.name << " " << item.studentNumber << endl;
		}
	}
};

