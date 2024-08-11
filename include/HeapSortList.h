#ifndef HEAP_SORT_LIST_H
#define HEAP_SORT_LIST_H

#include <initializer_list>
#include "List.h"

template <typename T, unsigned int capacity>
class HeapSortList : public List<T, capacity> {
    public:
        HeapSortList(std::initializer_list<T> initial_entries);
        void sort() override;
    
    private:
        void sort(T* array, unsigned int size);
        void heapify(T* array, unsigned int size, int rootIndex);
        void swap(T* inputArray, unsigned int index, unsigned int otherIndex);
};

#include "../src/HeapSortList.cpp"

#endif