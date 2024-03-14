#ifndef LIST_H
#define LIST_H

template <typename T, unsigned int capacity>
class List {

static_assert(std::is_arithmetic<T>::value && !std::is_same<T, bool>::value && !std::is_same<T, char>::value, "Classe aceita apenas tipos numericos");

private:
    const unsigned int MAX_LIST;
    T Entry[capacity+1];
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
    virtual void sort() = 0;
};

#include "../src/List.cpp"

#endif