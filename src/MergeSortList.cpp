#include "../include/MergeSortList.h"

template <typename T, unsigned int capacity>
MergeSortList<T, capacity>::MergeSortList(std::initializer_list<T> initial_enries) : List<T, capacity>(initial_enries) {}

template <typename T, unsigned int capacity>
void MergeSortList<T, capacity>::sort() {
    T* array = new T[this->count];
    for (unsigned int i = 0; i < this->size(); ++i)
        array[i] = this->entries[i+1];
    this->sort(array, this->count);
    for (unsigned int i = 0; i < this->size(); ++i)
        this->entries[i+1] = array[i];
    delete[] array;
}

template <typename T, unsigned int capacity>
void MergeSortList<T, capacity>::sort(T* inputArray, unsigned int inputLength) {
    if(inputLength < 2)
        return;
    
    unsigned int midIndex = inputLength / 2;
    unsigned int leftLength = inputLength - midIndex;
    unsigned int rightLength = midIndex;

    T* leftHalfArray = new T[leftLength];
    T* rightHalfArray = new T[rightLength];

    for (unsigned int i = 0; i < leftLength; ++i)
        leftHalfArray[i] = inputArray[i];
    for (unsigned int i = leftLength; i < inputLength; ++i)
        rightHalfArray[i - leftLength] = inputArray[i];

    this->sort(leftHalfArray, leftLength);
    this->sort(rightHalfArray, rightLength);

    this->merge(inputArray, leftHalfArray, leftLength, rightHalfArray, rightLength);

    delete[] leftHalfArray;
    delete[] rightHalfArray;
}

template <typename T, unsigned int capacity>
void MergeSortList<T, capacity>::merge(T* inputArray, T* leftHalfArray, unsigned int leftLength,
        T* rightHalfArray, unsigned int rightLength) {
    unsigned int i = 0, j = 0, k = 0;
    
    while (i < leftLength && j < rightLength) {
        if (leftHalfArray[i] < rightHalfArray[j]) {
            inputArray[k] = leftHalfArray[i];
            ++i;
        } else {
            inputArray[k] = rightHalfArray[j];
            ++j;
        }
        ++k;
    }
    
    while (i < leftLength) {
        inputArray[k] = leftHalfArray[i];
        ++i;
        ++k;
    }
    
    while (j < rightLength) {
        inputArray[k] = rightHalfArray[j];
        ++j;
        ++k;
    }
}