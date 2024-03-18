#ifndef LIST_H
#define LIST_H

#include <type_traits>

template <typename T, unsigned int capacity>
class List {

    protected:
        const unsigned int MAX_LIST;
        T entries[capacity+1];
        unsigned int count;

    public:
        List();
        ~List();
        bool empty();
        bool full();
        void insert(int pos, T entry);
        void delete_value(int pos, T& entry);
        void retrieve(int pos, T& entry);
        void replace(int pos, T entry);
        void clear();
        unsigned int size();
        T* begin();
        T* end();
        virtual void sort() = 0;
};

#include "../src/List.cpp"

#endif