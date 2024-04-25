#ifndef SET_H
#define SET_H

#include <iostream>

class set {

 public:

  typedef size_t size_type;
  typedef int value_type;

  static const size_type CAPACITY = 5;

  /*
   * Set constructor
   */
  set();

  // Get the size of the set
  size_t getSize() { return CAPACITY; } //

  /**
   *
   * Contains method
   * Check if the Set contains a value type.
   *
   * Will return the index of the value type or -1 if there is no value found;
   *
   */
  value_type contains(const value_type &) const; //

  /**
   *
   * Add method
   * Add a new value type to the Set.
   *
   * Parameter: Value type to add to the Set.
   *
   * ^ Note: You cannot add a value that is not unique in the Set. There cannot
   * be reoccuring values.
   *
   * No return
   *
   */
  void add(const value_type&); //

  /**
   *
   * Remove method
   * Remove a value type from the Set.
   *
   * Parameter: Value type to remove from the Set.
   *
   * No return
   *
   */
  void remove(const value_type&); //


  /**
   *
   * Check if a set is a subset of this instance of the set.
   * Returns true if the set is a subset and false if not.
   *
   */
  bool subset(const set&) const; //


  /**
   *
   * Check if a set is a proper subset of this instance of the set.
   * A set is a proper subset if it is not the same set.
   * Returns true if the set is a subset and false if not.
   *
   */
  bool proper_subset(const set&) const; // 

  /**
   *  Union operator - the union of two sets is a new larger set that contains
   *  all the number within the first set plus the unique numbers not found in
   *  the first set in the second set.
   */
  set operator+(const set& addend); //
                                   
  /**
   *  Subtraction operator - The subtraction of two sets is a new smaller set
   *  that contains all the values that were not contained in both sets
   */
  set operator-(const set& removeEnd); //
  
  /**
   *  Overloading the += operator to activate the += member function of the
   *  first set and use the second set as the argument
   *
   *  Ex: first_set += second_set;
   *
   */
  void operator+=(const set&); //

  /**
   *  Overloading the -= operator to activate the -= member function of the
   *  first set and use the second set as the argument
   *
   *  Ex: first_set -= second_set;
   *
   */
  void operator-=(const set&); //
  

/**
 *  RELATIONAL OPERATORS:
 *
 *  == -> Both sets have the same elements and size (order does not MATTER)
 *  != -> Both sets are not the same
 *  >= -> Set is equal but also has more elements and size than the other or is
 *  equal. 
 *  <= -> Same as above but switched
 *  > -> Set is equal but has more elements. Cannot be the same Set.
 *  < -> Same as above but switched
 *
 */


  bool operator==(const set&);

  bool operator!=(const set&);

  bool operator>=(const set&);

  bool operator<=(const set&);

  bool operator>(const set&);

  bool operator<(const set&);






 private:
  value_type data[CAPACITY];
  size_type used;
};

#endif
