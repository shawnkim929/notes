#include <iostream>
#include <iomanip>

#include "bag.h"
#include "set.h"
#include "keyed_bag.h"

using namespace std;

int main() {


  // Set stuff

  cout << "Test:" << endl;

  set test;
  test.add(1);
  //test.add(1);
  test.add(2);
  test.add(5);

 cout << "1 location: " << test.contains(1) << endl;
  cout << "2 location: " << test.contains(2) << endl;
  cout << "5 location: " << test.contains(5) << endl;

  // Testing capacity stuff (I set it to 5 in the header for testing, it's
  // normally 30)

  cout << "----" << endl;

  set test2;
  test2.add(1);
  test2.add(5);
  test2.add(3);
  test2.add(4);

  // Adding the two shouldn't result in an error
  test += test2;



 cout << "1 location: " << test.contains(1) << endl;
  cout << "2 location: " << test.contains(2) << endl;
  cout << "5 location: " << test.contains(5) << endl;
    cout << "3 location: " << test.contains(3) << endl;
  cout << "4 location: " << test.contains(4) << endl;
 set test3;
  test3.add(1);
  //test.add(1);
  test3.add(2);
  test3.add(5);
  test3.add(3);
  test3.add(4);


  cout << "== " << (test == test2) << endl;
  cout << "== 2 " << (test == test3) << endl;

  cout << ">= " << (test >= test2) << endl;
  cout << "<= " << (test <= test2) << endl;
  cout << "> " << (test > test2) << endl;
  cout << "< " << (test < test2) << endl;

  
  test -= test3;

 cout << "1 location: " << test.contains(1) << endl;
  cout << "2 location: " << test.contains(2) << endl;
  cout << "5 location: " << test.contains(5) << endl;
    cout << "3 location: " << test.contains(3) << endl;
  cout << "4 location: " << test.contains(4) << endl;

  cout << "keyed bag test:" << endl;

  keyed_bag testb;

  typedef keyed_bag::item item;
  

  testb.insert(1, 1);
  testb.insert(1, 2);
  testb.insert(1, 3);
  //testb.insert(1, 1);



}
