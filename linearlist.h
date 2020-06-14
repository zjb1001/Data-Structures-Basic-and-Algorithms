#ifndef    LINEARLIST_H
#define    LINEARLIST_H

#include <iostream>

template<typename T>
class linearList
{
    public:
        ~linearList() {};

        //  method
        virtual  int  getSize() const  =  0;
        virtual  bool isEmpty() const  =  0;
        virtual  T&   get(const int& idx) const  =  0;
        virtual  int  indexOf(const T& theElement) const  =  0;
        virtual  void insert(const int& idx, const T&)  =  0;
        virtual  void erase(const int& idx)  =  0;
        virtual  void output(std::ostream& out)  const  =  0;
};

#endif
