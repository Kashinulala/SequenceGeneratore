#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "IntroSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

int getSequenceLenght(std::string file) {
	std::ifstream f(file);
	int n;
	f >> n;
	return n;
	f.close();
}

void getSequence(int* arr, std::string file) {
	std::ifstream f(file);
	int n;
	f >> n;
	
	for (int i = 0; i < n; i++) {
		f >> arr[i];
	}
	f.close();
}

void testQuickSort(float& time, unsigned& comp,unsigned& assignment, unsigned& length, std::string file) {

	int* arr;
	int n = getSequenceLenght(file);
	arr = new int[n];
	getSequence(arr, file);

	clock_t t;

	t = clock();
	quickSort(arr, 0, n - 1, comp, assignment);
	time = clock() - t;
	length = n;
}

void testIntroSort(float& time, unsigned& comp, unsigned& assignment, std::string file) {

	int* arr;
	int n = getSequenceLenght(file);
	arr = new int[n];
	getSequence(arr, file);

	clock_t t;

	t = clock();
	introSort(arr, 0, n - 1, comp, assignment);
	time = clock() - t;

	/*std::ofstream f;
	f.open("111.txt");
	for (int i = 0; i < n; i++) {
		f << arr[i] << " ";
	}
	f.close();*/
}