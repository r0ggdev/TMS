#pragma once
#include"Headers.h"

void quickSort(int* _arr, int _start_index, int _end_index) {
    int pivot_index;

    auto partition = [](int* _arr, int _start_index, int _end_index) {
        int aux = _arr[_end_index];
        int minor_index = _start_index - 1;

        for (int j = _start_index; j < _end_index; j++) {

            if (_arr[j] <= aux) {
                minor_index++;
                swap(_arr[minor_index], _arr[j]);
                cout << _arr[minor_index] << " " << _arr[j] << endl;
            }
        }

        swap(_arr[minor_index + 1], _arr[_end_index]);
        
        return minor_index + 1;
        };


    if (_start_index < _end_index) {
        pivot_index = partition(_arr, _start_index, _end_index); // devuelve el indice del pivote

        quickSort(_arr, _start_index, pivot_index - 1);

        quickSort(_arr, pivot_index + 1, _end_index);
    }
}