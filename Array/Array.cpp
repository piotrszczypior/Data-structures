//
// Created by Piotr on 07.03.2023.
//

#include <iostream>
#include "Array.h"

using namespace std;

Array::Array() {
    this->size = 0;
    this->data = nullptr;
}


void Array::print() {
    if (size == 0) {
        cout << "Array is empty" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int Array::getSize() {
    return size;
}

void Array::add(int index, int value) {
    if (data == nullptr) {
        data = new int[++size];
        data[0] = value;
        return;
    }

    if (index < 0 || index > size) {
        cout << "Index out of bounds" << endl;
        return;
    }

    int *temporaryArray = data;
    data = new int[++size];


    for (int i = 0; i < size; i++) {
        if (i == index) {
            data[i] = value;
            continue;
        } else if (i < index) {
            data[i] = temporaryArray[i];
            continue;
        }

        data[i] = temporaryArray[i - 1];
    }

    delete[] temporaryArray;
}

void Array::push_front(int value) {
    if (data == nullptr) {
        data = new int[++size];
        data[0] = value;
        return;
    }
    int *temporaryArray = data;

    data = new int[++size];
    data[0] = value;

    for (int i = 1; i < size; i++) {
        data[i] = temporaryArray[i - 1];
    }

    delete[] temporaryArray;
}

void Array::push_back(int value) {
    if (data == nullptr) {
        data = new int[++size];
        data[0] = value;
        return;
    }
    int *temporaryArray = data;

    data = new int[++size];
    data[size - 1] = value;

    for (int i = 0; i < size - 1; i++) {
        data[i] = temporaryArray[i];
    }

    delete[] temporaryArray;
}

void Array::deleteIndex(int index) {
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }

    if (index < 0 || index > size) {
        cout << "Index out of bounds" << endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    int *temporaryArray = data;

    data = new int[--size];

    for (int i = 0; i < size; i++) {
        data[i] = temporaryArray[i];
    }

    delete[] temporaryArray;
}

void Array::pop_back() {
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    int *temporaryArray = data;

    data = new int[--size];
    for (int i = 0; i < size; i++) {
        data[i] = temporaryArray[i];
    }
    delete[] temporaryArray;
}

void Array::pop_front() {
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    int *temporaryArray = data;

    data = new int[--size];
    for (int i = 0; i < size; i++) {
        data[i] = temporaryArray[i + 1];
    }
    delete[] temporaryArray;
}

Array::~Array() {
    delete[] data;
}




