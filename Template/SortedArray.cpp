//
// Created by bruno on 19/11/2019.
//

#include <algorithm>
#include <random>
#include <experimental/random>
#include "../include/Population.h"
#include "SortedArray.h"

SortedArray::SortedArray (int size){
    this->_array = new int[size];
    _size = size;
    for(int i = 0; i < size; i++){
        _array[i] = i;
    }
    std::random_shuffle(_array, _array  + _size);
}

SortedArray::SortedArray(const SortedArray &src) {
    this->_array = new int[src._size];
    this->_size = src._size;
    for(int i = 0; i < _size; i++){
        this->_array[i] = src._array[i];
    }
}

double SortedArray::score() {
    int score = 0;
    for(int i = 0; i < _size; i++){
        score += _array[i] * i;
    }
    return score;
}

void SortedArray::mut() {
    int s = _size;
    int l = (rand()%(s / 2 - 1 + 1)) + 1;
    int i = (rand()%(s - 2 * l + 1));
    int j = (rand()%(s - l - i - l + 1)) + i + l;

    std::swap_ranges(_array + i, _array + i + l, _array + j);
}

void SortedArray::shuffle() {
    std::random_shuffle(_array, _array  + _size);
}


void SortedArray::fill(SortedArray& target){
    SortedArray &targ = (SortedArray&) target;
    for(int i = 0; i < _size; i++){
        targ._array[i] = _array[i];
    }
}

SortedArray::~SortedArray() {
    delete _array;
}

std::ostream &operator<<(std::ostream &os, const SortedArray &array) {
    os << "Array: ";
    for(int i = 0; i < array._size-1; i++){
        os << array._array[i] << " ";
    }
    if(array._size != 0){
        os << array._array[array._size-1];
    }
    return os;
}
