#include <cassert>
#include "set.h"

using namespace std;

set::set() {
  this->used = 0;
}

set::value_type set::contains(const set::value_type& value) const {

  for(int x = 0; x < this->used; x++) {
    if(this->data[x] == value) {
      return x;
    }
  }
  
  return -1;
}

void set::add(const set::value_type& value) {
 
  assert(this->used + 1 <= CAPACITY);
  assert(this->contains(value) == -1); // Close if value is found in the set

  this->data[used] = value;
  this->used++;

}

bool set::subset(const set& checkSet) const {

  for(int x = 0; x < checkSet.used; x++) {
    if(this->contains(checkSet.data[x]) == -1) {
      return false;
    }
  }
  return true;

}

bool set::proper_subset(const set& checkSet) const {
  
  return (this->subset(checkSet) && (this->used != checkSet.used));

}


void set::remove(const set::value_type& value) {
  
  assert(this->contains(value) != -1); // Close if value does not exist in the set
  
  for(int x = 0; x < this->used; x++) {
    if(this->data[x] == value) {
      for(int y = x; y < this->used - 1; y++) {
        this->data[y] = this->data[y+1];
      }
      used--;
      return;
    }
  }
  
}

void set::operator-=(const set& rhs) {
  
  for(int x = 0; x < rhs.used; x++) { 
    
    if((this->contains(rhs.data[x]) != -1)) {
      this->remove(rhs.data[x]);
    }

  }

}


void set::operator+=(const set& rhs) {
  set check;

  check = *this;
  check -= rhs;


  assert((rhs.used + check.used <= set::CAPACITY));

  for(int x = 0; x < rhs.used; x++) {
    
    if(this->contains(rhs.data[x]) == -1) {
      this->add(rhs.data[x]);
    }
  }

}

set set::operator+(const set& addend) {

  set answer;
  answer += *this;
  answer -= addend;
  
  assert((addend.used + answer.used  <= set::CAPACITY));

  answer += addend;

  return answer;
}

set set::operator-(const set& removeEnd) {

  set answer;
  answer += *this;
  answer -= removeEnd;
  return answer;

}


bool set::operator==(const set& rhs) {

  return(this->subset(rhs) && (rhs.used == this->used));

}

bool set::operator!=(const set& rhs) {
  return(!(*this == rhs));
}

bool set::operator>=(const set& rhs) {
  return((*this == rhs) || ((this->proper_subset(rhs)) && (this->used > rhs.used)));
}

bool set::operator<=(const set& rhs) {
  return((*this == rhs) || ((this->proper_subset(rhs)) && (this->used < rhs.used)));
}

bool set::operator>(const set& rhs) {
  return((*this >= rhs) && (*this != rhs));
}

bool set::operator<(const set& rhs) {
    return((*this <= rhs) && (*this != rhs));
}




