#include "../include/List.h"
#include <stdexcept>

template <typename T, unsigned int capacity>
List<T, capacity>::List(): MAX_LIST(capacity), count(0) {
    static_assert(std::is_arithmetic<T>::value && !std::is_same<T, bool>::value && !std::is_same<T, char>::value, "Classe aceita apenas tipos numericos");
}

template <typename T, unsigned int capacity>
List<T, capacity>::List(std::initializer_list<T> initial_entries): MAX_LIST(capacity), count(0) {
    static_assert(std::is_arithmetic<T>::value && !std::is_same<T, bool>::value && !std::is_same<T, char>::value, "Classe aceita apenas tipos numericos");
    for (T entry : initial_entries)
        this->insert(count+1, entry);
}

template <typename T, unsigned int capacity>
List<T, capacity>::~List() {}

template <typename T, unsigned int capacity>
bool List<T, capacity>::empty() {
    return count == 0;
}

template <typename T, unsigned int capacity>
bool List<T, capacity>::full() {
    return count == MAX_LIST;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::insert(int pos, T entry) {
    if (full()) throw std::out_of_range("Lista cheia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    for (int i = count; i >= pos; i--)
        entries[i+1] = entries[i];
    entries[pos] = entry;
    count++;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::delete_value(int pos, T& entry) {
    if (empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    entry = entries[pos];
    for (int i = pos; i < count; i++)
        entries[i] = entries[i+1];
    count--;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::retrieve(int pos, T& entry) {
    if (empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    entry = entries[pos];
}

template <typename T, unsigned int capacity>
void List<T, capacity>::replace(int pos, T entry) {
    if (empty()) throw std::out_of_range("Lista vazia!");
    if (pos < 1 || pos > count+1) throw std::out_of_range("Posicao invalida!");
    entries[pos] = entry;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::clear() {
    count = 0;
}

template <typename T, unsigned int capacity>
unsigned int List<T, capacity>::size() {
    return count;
}

template <typename T, unsigned int capacity>
T* List<T, capacity>::begin() {
    return &entries[1];
}

template <typename T, unsigned int capacity>
T* List<T, capacity>::end() {
    return &entries[count+1];
}

template <typename T, unsigned int capacity>
bool List<T, capacity>::operator==(const List<T, capacity>& other) const {
    if (this->count != other.count)
        return false;
    for (unsigned int i = 1; i <= this->count; ++i) {
        if (this->entries[i] != other.entries[i])
            return false;
    }
    return true;
}

template <typename T, unsigned int capacity>
void List<T, capacity>::swap(unsigned int pos, unsigned int other_pos) {
    T tmp = this->entries[pos];
    this->entries[pos] = this->entries[other_pos];
    this->entries[other_pos] = tmp;
}