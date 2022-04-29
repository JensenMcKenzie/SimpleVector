/* SimpleVector.h - SimpleVector header for use in Exercises
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Homework 2
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <cstdlib>
using namespace std ;

template <class T>
class SimpleVector {

    private:
        T *aptr ;
        int array_size ;
        void subError() ;                     // Handles subscripts out of range

    public:
        SimpleVector() {                      // Default constructor
            aptr = 0 ;
            array_size = 0 ;
        }

        SimpleVector(int) ;                   // Constructor
        SimpleVector(const SimpleVector &) ;  // Copy constructor
        ~SimpleVector() ;                     // Destructor
        int size()
        { return array_size ; }
        T &operator[](const int &) ;          // Overloaded [] operator
} ;

//*************************************************************
//         Constructor for SimpleVector class                 *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s) {

    array_size = s ;
    aptr = new T [s] ;

    for (int count = 0 ; count < array_size ; count++)
        *(aptr + count) = T() ;
}

//************************************************
// Copy Constructor for SimpleVector class       *
//************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {

    array_size = obj.array_size ;
    aptr = new T [array_size] ;
    for(int count = 0 ; count < array_size ; count++)
        *(aptr + count) = *(obj.aptr + count) ;
}

//***************************************
// Destructor for SimpleVector class    *
//***************************************
template <class T>
SimpleVector<T>::~SimpleVector() {

    if (array_size > 0)
        delete [] aptr ;
}

//*************************************************************
//              SubError function                             *
// Displays an error message and terminates the program when  *
// a subscript is out of range.                               *
//*************************************************************
template <class T>
void SimpleVector<T>::subError() {

    cout << "ERROR: Subscript out of range.\n" ;
    exit(0) ;
}

//*************************************************************
//             Overloaded [] operator                         *
// This function returns a reference to the element           *
// in the array indexed by the subscript.                     *
//*************************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub) {

    if (sub < 0 || sub >= array_size)
        subError() ;
    return aptr[sub] ;
}

#endif
