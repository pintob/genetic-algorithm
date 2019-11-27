//
// Created by bruno on 23/11/2019.
//

#ifndef ALGOGEN_SORTEDARRAY_H
#define ALGOGEN_SORTEDARRAY_H

#include <iostream>


class SortedArray{

public:
    SortedArray (const SortedArray& array);
    SortedArray (int size);
    virtual double score();
    virtual void mut();
    virtual void shuffle();
    virtual void fill(SortedArray& target);
    virtual ~SortedArray();

    friend std::ostream &operator<<(std::ostream &os, const SortedArray &array);


private:
    int *_array;
    int _size;
};


#endif //ALGOGEN_SORTEDARRAY_H
