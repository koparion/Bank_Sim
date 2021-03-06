//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT queue: Circular array-based implementation.
 Listing 14-5.
 @file ArrayQueue.cpp */

#include "ArrayQueue.h"  // Header file
#include <iostream>
using namespace std;

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(DEFAULT_CAPACITY - 1), count(0)
{
} // end default constructor

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
   return count == 0;
} // end isEmpty

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   bool result = false;
   if (count < DEFAULT_CAPACITY)
   {
      // Queue has room for another item
      back = (back + 1) % DEFAULT_CAPACITY;
      items[back] = newEntry;
      count++;
      result = true;
   } // end if
   
   return result;
} // end enqueue

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
   bool result = false;
   if (!isEmpty())
   {
      front = (front + 1) % DEFAULT_CAPACITY;
      count--;
      result = true;
   } // end if
   
   return result;
} // end dequeue

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   if (isEmpty())
      throw PrecondViolatedExcep("peekFront() called with empty queue");
   
   // Queue is not empty; return front
   return items[front];
} // end peekFront

//template<class ItemType>
//void ArrayQueue<ItemType>::print()
//{
//    printf("enqueued customer: %d\n", items[front]);
//}


// End of implementation file.