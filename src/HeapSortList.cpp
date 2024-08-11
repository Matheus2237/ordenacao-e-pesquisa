#include "../include/HeapSortList.h"

template <typename T, unsigned int capacity>
HeapSortList<T, capacity>::HeapSortList(std::initializer_list<T> initial_enries) : List<T, capacity>(initial_enries) {}

template <typename T, unsigned int capacity>
void HeapSortList<T, capacity>::sort() {
    T* array = new T[this->count];
    for (unsigned int i = 0; i < this->count; ++i)
        array[i] = this->entries[i+1];
    this->sort(array, this->count);
    for (unsigned int i = 0; i < this->count; ++i)
        this->entries[i+1] = array[i];
    delete[] array;
}

template <typename T, unsigned int capacity>
void HeapSortList<T, capacity>::sort(T* array, unsigned int size) {
    for (int i = size/2-1; i >= 0; --i) {
        this->heapify(array, size, i);       
    }
    for (int i = size-1; i > 0; --i) {
        this->swap(array, 0, i);
        this->heapify(array, i, 0);
    }
}

template <typename T, unsigned int capacity>
void HeapSortList<T, capacity>::heapify(T* array, unsigned int size, int rootIndex) {
    int largest = rootIndex;
    int left = 2 * rootIndex + 1;
    int right = 2 * rootIndex + 2;

    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != rootIndex) {
        this->swap(array, largest, rootIndex);
        this->heapify(array, size, largest);
    }
    
}

template <typename T, unsigned int capacity>
void HeapSortList<T, capacity>::swap(T* input_array, unsigned int index, unsigned int other_index) {
    T tmp = input_array[index];
    input_array[index] = input_array[other_index];
    input_array[other_index] = tmp;
}