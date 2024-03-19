#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <type_traits>

template <typename T, unsigned int capacity>
class List {

    protected:
        const unsigned int MAX_LIST;
        T entries[capacity+1];
        unsigned int count;

    public:
        List();
        List(std::initializer_list<T> initial_entries);
        ~List();
        bool empty();
        bool full();
        void insert(int pos, T entry);
        void delete_value(int pos, T& entry);
        void retrieve(int pos, T& entry);
        void replace(int pos, T entry);
        void clear();
        unsigned int size();
        virtual void sort() = 0;
        T* begin();
        T* end();
        bool operator==(const List<T, capacity>& other) const;
        void swap(unsigned int pos, unsigned int other_pos);
};

#include "../src/List.cpp"

#endif