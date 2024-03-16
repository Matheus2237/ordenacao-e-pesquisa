#include "../include/List.h"
#include <stdexcept>

template <typename T, unsigned int capacity>
List<T, capacity>::List():
    MAX_LIST(capacity),
    count(0)
{}

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