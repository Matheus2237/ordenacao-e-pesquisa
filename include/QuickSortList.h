#ifndef QUICK_SORT_LIST
#define QUICK_SORT_LIST

#include <initializer_list>
#include "List.h"

template <typename T, unsigned int capacity>
class QuickSortList : public List<T, capacity> {
    public:
        QuickSortList(std::initializer_list<T> initial_entries);
        void sort() override;
    
    private:
        int partition(T* inputArray, unsigned int lowIndex, unsigned int highIndex, T pivot);
        void sort(T* inputArray, unsigned int lowIndex, unsigned int highIndex);
        void swap(T* inputArray, unsigned int index, unsigned int otherIndex);
        int getRandomNumber(int lowIndex, int highIndex);
};

#include "../src/QuickSortList.cpp"

#endif