#ifndef PAIR_H
#define PAIR_H

template<class T>
class Pair
{
private:
    T first, second;
public:
    Pair();
    Pair(T first_val, T second_val);
    T get_first();
    T get_second();
};

template<class T, class D>
class DiffTypePair
{
private:
    T first;
    D second;
public:
    DiffTypePair();
    DiffTypePair(T first_val, D second_val);
    T get_first();
    D get_second();
};

#endif 
