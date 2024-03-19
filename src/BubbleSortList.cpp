#include "../include/BubbleSortList.h"
#include <iostream>

template <typename T, unsigned int capacity>
BubbleSortList<T, capacity>::BubbleSortList(std::initializer_list<T> initial_enries) : List<T, capacity>(initial_enries) {}

template <typename T, unsigned int capacity>
void BubbleSortList<T, capacity>::sort() {
    for (unsigned int i = 1; i < this->count; i++)
        for (unsigned int j = i; j < this->count; j++)
            if (this->entries[j] > this->entries[j+1])
                this->swap(j, j+1);
}