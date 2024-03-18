#ifndef SELECTION_SORT_LIST
#define SELECTION_SORT_LIST

#include <initializer_list>
#include "List.h"

template <typename T, unsigned int capacity>
class SelectionSortList : public List<T, capacity> {
    public:
        SelectionSortList(std::initializer_list<T> initial_entries);
        void sort() override;
};

#include "../src/SelectionSortList.cpp"

#endif