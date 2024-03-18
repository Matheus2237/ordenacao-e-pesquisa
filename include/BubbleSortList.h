#ifndef BUBBLE_SORT_LIST
#define BUBBLE_SORT_LIST

#include <initializer_list>
#include "List.h"

template <typename T, unsigned int capacity>
class BubbleSortList : public List<T, capacity> {
    public:
        BubbleSortList(std::initializer_list<T> initial_entries);
        void sort() override;
};

#include "../src/BubbleSortList.cpp"

#endif