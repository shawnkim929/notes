#ifndef keyed_bag_h
#define keyed_bag_h

#include <cassert>
#include <stddef.h>

class keyed_bag
{
public:


	keyed_bag();

	typedef int value_type;

  
  typedef struct item {
    value_type value;
    int key;
  } item;

	
	//size_t data type is an integer data type that can hold
	//only non-negative numbers.  each c++ implementation 
	//guarantees that the values of the size_t type can hold the
	//size of any variable that can be declared on your machine.
	typedef size_t size_type;
	
	static const size_type CAPACITY = 30;
	
	size_type size() const{ return used;}

  // Addition for the keyed bag
  // Checks if a key is in the bag and returns true if it is in the bag
  // and false if otherwise.
  bool contains(int);

  //Precondition: size() < CAPACITY, and the bag does not 
  //yet contain any item with the given key
  //Postcondition:  A new copy of entry has been added to the bag, 
  //with the given key.
  void insert(const value_type&, int);

  // Remove an item associated with a key
  bool erase(const int);

  //
  //  Check if the bags have any sharing keys
  //  Returns true if there are any keys shared.
  //
  bool checkKey(const keyed_bag&);

  // Precondition: None of the bags share the same key.
  //union operator - the union of two keyed_bags is a new larger keyed_bag that contains
  //all the numbers in the first keyed_bag plus all the numbers in the second keyed_bag
  keyed_bag operator+(const keyed_bag& b);
 
  // Precondition: None of the bags share the same key.
  //overloading the += operator to activate the += member function of the 
  //first keyed_bag and use the second keyed_bag as the argument
  //ex first_bag += second_bag;
  void operator+=(const keyed_bag& addend);

  // subtraction operator - the subtraction between two keyed_bags is the removal of
  // one keyed_bag from another removing all elements contained in one keyed_bag from the larger.
  keyed_bag operator-(const keyed_bag& b);

  // overloading the -= operator to activate the -= member function of the first
  // keyed_bag and use the second keyed_bag as the argument
  // ex first_bag -= second_bag;
  void operator-=(const keyed_bag& addend);

private:
  item data[CAPACITY];
  size_type used;

};

#endif
