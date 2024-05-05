#include "../include/QuickSortList.h"
#include <random>
#include <ctime>

template <typename T, unsigned int capacity>
QuickSortList<T, capacity>::QuickSortList(std::initializer_list<T> initial_enries) : List<T, capacity>(initial_enries) {
    srand(time(0));
}

template <typename T, unsigned int capacity>
void QuickSortList<T, capacity>::sort() {
    T* array = new T[this->count];
    for (unsigned int i = 0; i < this->count; ++i)
        array[i] = this->entries[i+1];
    this->sort(array, 0, this->count - 1);
    for (unsigned int i = 0; i < this->count; ++i)
        this->entries[i+1] = array[i];
    delete[] array;
}

template <typename T, unsigned int capacity>
void QuickSortList<T, capacity>::sort(T* input_array, unsigned int low_index, unsigned int high_index) {
    
    if (low_index >= high_index) {
        return;
    }
    
    int pivot_index = getRandomNumber(low_index, high_index);
    T pivot = input_array[pivot_index];
    this->swap(input_array, pivot_index, high_index);
    
    int left_index = this->partition(input_array, low_index, high_index, pivot);
    this->sort(input_array, low_index, left_index-1);    
    this->sort(input_array, left_index+1, high_index);    
}

template <typename T, unsigned int capacity>
int QuickSortList<T, capacity>::partition(T* input_array, unsigned int low_index, unsigned int high_index, T pivot) {
    
    int left_index = low_index;
    int right_index = high_index - 1;

    while (left_index < right_index) {
        while (input_array[left_index] <= pivot && left_index < right_index) {
            ++left_index;
        }
        while (input_array[right_index] >= pivot && left_index < right_index) {
            --right_index;
        }
        this->swap(input_array, left_index, right_index);
    }

    if (input_array[left_index] > input_array[high_index]) {
        this->swap(input_array, left_index, high_index);
    }
    else {
        left_index = high_index;
    }

    return left_index;
}

template <typename T, unsigned int capacity>
void QuickSortList<T, capacity>::swap(T* input_array, unsigned int index, unsigned int other_index) {
    T tmp = input_array[index];
    input_array[index] = input_array[other_index];
    input_array[other_index] = tmp;
}

template <typename T, unsigned int capacity>
int QuickSortList<T, capacity>::getRandomNumber(int low_index, int high_index) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low_index, high_index - 1);
    return dis(gen);
}