#ifndef INSERTION_SORT_LIST
#define INSERTION_SORT_LIST

#include <initializer_list>
#include "List.h"

template <typename T, unsigned int capacity>
class InsertionSortList : public List<T, capacity> {
    public:
        InsertionSortList(std::initializer_list<T> initial_entries);
        void sort() override;
};

#include "../src/InsertionSortList.cpp"

#endif