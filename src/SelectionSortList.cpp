#include "../include/SelectionSortList.h"
#include <iostream>

template <typename T, unsigned int capacity>
SelectionSortList<T, capacity>::SelectionSortList(std::initializer_list<T> initial_enries) : List<T, capacity>(initial_enries) {}

template <typename T, unsigned int capacity>
void SelectionSortList<T, capacity>::sort() {
    for (unsigned int i = 1; i < this->count; i++) {
        T pos_menor = i;
        for (unsigned int j = i+1; j <= this->count; j++)
            if (this->entries[j] < this->entries[pos_menor])
                pos_menor = j;
        if (this->entries[i] > this->entries[pos_menor]) {
            T tmp = this->entries[pos_menor];
            this->entries[pos_menor] = this->entries[i];
            this->entries[i] = tmp;
        }
    }
}