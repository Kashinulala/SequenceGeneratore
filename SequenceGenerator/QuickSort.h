﻿#pragma once
#include <iostream>

int medianOfThree(int arr[], int left, int right, unsigned& comp, unsigned& assignmentCount) {

    int mid = left + (right - left) / 2;

    comp++;
    if (arr[left] > arr[mid]) {
        std::swap(arr[left], arr[mid]);
        assignmentCount += 3;
    }
    comp++;
    if (arr[left] > arr[right]){
        std::swap(arr[left], arr[right]);
        assignmentCount += 3;
    }
    comp++;
    if (arr[mid] > arr[right]) {
        std::swap(arr[mid], arr[right]);
        assignmentCount += 3;
    }

    std::swap(arr[mid], arr[right - 1]);
    assignmentCount += 3;

    return arr[right - 1];
}

int partition(int arr[], int left, int right, unsigned& comp, unsigned& assignmentCount) {

    int pivot = medianOfThree(arr, left, right, comp, assignmentCount);

    int i = left - 1;
    int j = right - 1;

    while (true) {
        comp++;
        while (arr[++i] < pivot) {
            comp++;
        };
        comp++;
        while (arr[--j] > pivot) {
            comp++;
        };

        if (i < j) {
            std::swap(arr[i], arr[j]);
            assignmentCount+= 3;
        }
        else
            break;
    }

    std::swap(arr[i], arr[right - 1]);
    assignmentCount+= 3;
    return i;
}

void quickSort(int arr[], int left, int right, unsigned& comp, unsigned& assignmentCount) {

    if (left < right) {

        int pivotIndex = partition(arr, left, right, comp, assignmentCount);

        quickSort(arr, left, pivotIndex - 1, comp, assignmentCount);
        quickSort(arr, pivotIndex + 1, right, comp, assignmentCount);

    }
}