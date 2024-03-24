#ifndef MERGE_SORT_LIST
#define MERGE_SORT_LIST

#include <initializer_list>
#include "List.h"

template <typename T, unsigned int capacity>
class MergeSortList : public List<T, capacity> {
    public:
        MergeSortList(std::initializer_list<T> initial_entries);
        void sort() override;
    private:
        void sort(T* inputArray, unsigned int inputLength);
        void merge(T* inputArray, T* leftHalfArray, unsigned int leftLength,
            T* rightHalfArray, unsigned int rightLength);
};

#include "../src/MergeSortList.cpp"

#endif