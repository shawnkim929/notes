#include "keyed_bag.h"
#include <algorithm>


keyed_bag::keyed_bag() {
  this->used = 0;
}

bool keyed_bag::contains(int key) {

  for(int x = 0; x < this->used; x++) {
    if(this->data[x].key == key) {
      return true;
    }
  }
  return false;
}

void keyed_bag::insert(const value_type& entry, int key)
{
  assert(size() < CAPACITY);
  assert(!contains(key));
  item entryItem;
  entryItem.value = entry;
  entryItem.key = key;
  data[used] = entryItem;
  ++used;
}

bool keyed_bag::erase(const int target)
{
  size_type index;

  index = 0;
  while((index < used) && (data[index].key != target))
    ++index;

  if(index == used)
    return false;

  --used;
  data[index] = data[used];
  return true;
}

bool keyed_bag::checkKey(const keyed_bag& check) {
  for(int x = 0; x < check.size(); x++) {
    if(x > this->used) {
      return false;
    }
    if(this->contains(check.data[x].key)) {
      return true;
    }
  }

  return false;
}

void keyed_bag::operator+=(const keyed_bag& addend)
{
  assert(size() + addend.size() <= CAPACITY);
  assert(this->checkKey(addend));

  std::copy(addend.data, addend.data + addend.used, data + used);
  used += addend.used;
}

keyed_bag keyed_bag::operator+(const keyed_bag& b)
{
  keyed_bag answer;

  assert(this->size() + b.size() <= keyed_bag::CAPACITY);
  assert(this->checkKey(b));

  answer += *this;
  answer += b;
  return answer;
}

void keyed_bag::operator-=(const keyed_bag& remove) {
  assert(size() - remove.size() >= static_cast<size_type>(0)); 

  int size = remove.CAPACITY;
  for(int x = 0; x < size; x++) {
    this->erase(remove.data[x].key);
    
  }

}

keyed_bag keyed_bag::operator-(const keyed_bag& remove) {

  keyed_bag answer;
  assert(size() - remove.size() >= static_cast<size_type>(0)); 

  answer += *this;
  answer -= remove;

  return answer;

}
