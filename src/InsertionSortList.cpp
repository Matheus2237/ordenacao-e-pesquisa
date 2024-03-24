#include "../include/InsertionSortList.h"

template <typename T, unsigned int capacity>
InsertionSortList<T, capacity>::InsertionSortList(std::initializer_list<T> initial_enries) : List<T, capacity>(initial_enries) {}

template <typename T, unsigned int capacity>
void InsertionSortList<T, capacity>::sort() {
    for (unsigned int i = 2; i <= this->count; ++i) {
        T compared = this->entries[i];
        unsigned int target_pos = i - 1;
        while (target_pos >= 1 && this->entries[target_pos] > compared) {
            this->entries[target_pos+1] = this->entries[target_pos];
            --target_pos;
        }
        this->entries[++target_pos] = compared;
    }
}