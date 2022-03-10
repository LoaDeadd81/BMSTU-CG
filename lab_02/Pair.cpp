#include "Pair.h"

#include <QString>
#include "Figure.h"

template class Pair<double>;

template class DiffTypePair<Figure, QString>;

template<class T>
Pair<T>::Pair()
{

}

template<class T>
Pair<T>::Pair(T first_val, T second_val) : first(first_val), second(second_val)
{

}

template<class T>
T Pair<T>::get_first()
{
    return  first;
}

template<class T>
T Pair<T>::get_second()
{
    return second;
}

template<class T, class D>
DiffTypePair<T, D>::DiffTypePair()
{

}

template<class T, class D>
DiffTypePair<T, D>::DiffTypePair(T first_val, D second_val) : first(first_val), second(second_val)
{

}

template<class T, class D>
T DiffTypePair<T, D>::get_first()
{
    return first;
}

template<class T, class D>
D DiffTypePair<T, D>::get_second()
{
    return second;
}
