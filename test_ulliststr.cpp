#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr test;

  test.pop_front();
  test.pop_back();

  test.push_back("three");
  test.push_front("two");
  test.push_front("eight");
  test.pop_front();
  test.push_front("one");
  test.push_back("seven");
  test.pop_back();

  for (size_t i = 0; i < test.size(); i++) {
    std::cout << test.get(i);
  }

}
