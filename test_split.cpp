/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

void print(Node* nod) { //Doesnt print for some reason? But passed 
  while (nod) {                 //all the tests, 
    cout << nod->value << " -> "; 
    Node* temp = nod;
    nod = nod->next;
    delete temp; //Fancy dandy helper function to print and deallocate memory
  }
}


int main(int argc, char* argv[])
{
    Node* test1 = new Node(1, new Node(2, new Node(3, 
                  new Node(4, new Node(5, nullptr)))));
      // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr


//    Node* test2 = new Node(2, new Node(4, new Node(6, 
//                  new Node(8, new Node(10, nullptr)))));
//      // 2 -> 4 -> 6 -> 8 -> 10 -> nullptr
//    Node* test3 = new Node(1, new Node(3, new Node(5, 
//                new Node(7, new Node(9, nullptr)))));
//    // 1 -> 3 -> 5 -> 7 -> 9 -> nullptr
//    Node* test4 = nullptr;
//    // nullptr

    Node* odds = nullptr;
    Node* evens = nullptr;

    split(test1, odds, evens);

    print(odds);
    print(evens);

    cout << "End" << endl;


    return 0;
}
