#ifndef     ARRAYLIST_H
#define     ARRAYLIST_H

#include <iostream>
#include "linearlist.h"

template<typename T>
class arrayList 
{
    public:
        arrayList(int capacity);
        arrayList(const arrayList<T>& alist);        
        ~arrayList() { delete [] element; };

        int     getSize() const {return listsize;}
        bool    isEmpty() const {return listsize==0;}
        T&      get(int idx) const;
        int     indexOf(const T& theElement) const;
        void    insert(const int& idx, const T& theElement);
        void    erase(const int& idx);
        // void    output(std::ostream& out) const;
        void    changeLength1D(const int& oldLength, const int& newLength)
        {
            if (newLength < 0)
                std::cout << "new length must be over 0" << std::endl;

            T*  tmplist =   new T [newLength];
            int small  =  oldLength < newLength ? oldLength:newLength;
            std::copy(element, element + small, tmplist);

            delete [] element;          // release old memory

            element  =  tmplist;
            capacity =  newLength;
        }

        void    checkIndex(const int& idx)
        {
            if ( (idx < 0) or (idx > listsize) )
            {
                // std::ostream ss;
                // ss << "index= " << idx << " is not valid";
                throw std::invalid_argument("index is not valid");
            }
        }
        void  print() const;

    private:
        T*      element;
        int     listsize  =  0;
        int     capacity;

};

template<typename T>
arrayList<T>::arrayList(int capacity)
{
    this->capacity    =   capacity;
    element     =   new T [capacity];
}

template<typename T>
arrayList<T>::arrayList(const arrayList<T>& alist)
{
    element  =  alist.element;
    listsize =  alist.listsize;
    capacity =  alist.listsize;
}

template<typename T>
T&   arrayList<T>::get(int idx) const
{
    checkIndex(idx);
    return element[idx];
}

template<typename T>
int  arrayList<T>::indexOf(const T& theElement) const
{
    for (int ii=0; ii<listsize; ++ii)
        if (element[ii]==theElement)
            return ii;

    return -1;
}

template<typename T>
void arrayList<T>::insert(const int& idx, const T& theElement)
{
    checkIndex(idx);

    if (listsize > capacity/2)
        changeLength1D(capacity, capacity*2);

    std::copy(element+idx, element+listsize, element+idx+1);
    element[idx]  =  theElement;

    listsize++;
}

template<typename T>
void arrayList<T>::erase(const int& idx)
{
    checkIndex(idx);

    if (listsize < capacity/2)
        changeLength1D(capacity, capacity/2);

    std::copy(element+idx+1, element+listsize, element+idx);

    element[--listsize].~T();
}

// template<typename T>
// void arrayList<T>::output(std::ostream& out) const
// {
    // std::copy(element,  element+listsize, std::ostream_iterator<T>(std::cout, " "));
// }

/* template<typename T>
std::ostream&  operator<<(std::ostream& out, const arrayList<T>& x)
{
    x.output(out);
    return out;
} */

template<typename T>
void  arrayList<T>::print() const
{
    for  (int  ii=0;  ii < listsize;  ++ii)
        std::cout << element[ii] << " ";
    std::cout << std::endl;
}






#endif
