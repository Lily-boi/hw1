#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) {
  if (!tail_ || tail_->last == ARRSIZE) { //is there no tail? 
                                  //or did we reach maximum capacity 
    Item* newItem = new Item();   //If so, make a new item to store data
    newItem->first = 0;
    newItem->last = 0;
    if (tail_) {     //If there was a tail, link it properly
      tail_->next = newItem;
      newItem->prev = tail_;
    }
    tail_ = newItem;
    if (head_ == nullptr) { //If we're making a completely new list, initialize head
      head_ = tail_;
    }
  }
  tail_->val[tail_->last++] = val; //set the new tail to value
  size_++; //increase the size
}

void ULListStr::push_front(const std::string& val) {
  if (!head_ || head_->first == 0) { //Is there no head?
                                //or are we full at front
    Item* newItem = new Item(); //If so, make a new item

    newItem->first = ARRSIZE - 1; 
    newItem->last = ARRSIZE;
    if (head_) {  //If head did exist, then make it the 2nd item
      head_->prev = newItem;
      newItem->next = head_;
    }
    head_ = newItem; //Set the new item as head
    if (tail_ == nullptr) { //If there was no tail, initialize it
      tail_ = head_;
    }
  } else {
    head_->first--;
  } 

  head_->val[head_->first] = val; //set new head to value
  size_++; //increase the size
}

void ULListStr::pop_back() {
  if (tail_ == nullptr) { //If there is no tail, we can't do anything
    return;
  } 

  tail_->last--; //get rid of the last item in tail
  size_--;

  if (tail_->first == tail_->last) { //If the tail is empty
    Item* temp = tail_; 
    tail_ = tail_->prev; //move the tail pointer back
    if (tail_) {   //If there still is a tail, then point at nullptr
      tail_->next = nullptr;
    } else { //If there is no tail, then its empty
      head_ = nullptr;
    }
    delete temp;
  }
}

void ULListStr::pop_front() {
  if (head_ == nullptr) { //Can't pop if there's nothing there
    return;
  }

  head_->first++;//skip the first item
  size_--;

  if (head_->first == head_->last) { //If the head is empty,
    Item* temp = head_;
    head_ = head_->next; //update the pointer to the next item
    if (head_) { //If there still is a head, update so there is no prev
      head_->prev = nullptr;
    } else { //Otherwise, its gotta be empty
      tail_ = nullptr;
    }
    delete temp;
  }
}

std::string const& ULListStr::back() const { //Just returns the last value in tail
  return (tail_->val[tail_->last - 1]);
}

std::string const& ULListStr::front() const {//Returns the first value in head
  return (head_->val[head_->first]);
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) { //If we're looking for something that is out of our range
    throw std::invalid_argument("Bad location");
  }

  Item* curr = head_; //start at the head item
  size_t index = loc;

  while (curr) { //cycle through the items
    size_t node_size = curr->last - curr->first; 

    if (index < node_size) { //if the index is in the item, we can return it
      return &curr->val[curr->first + index];
    }

    index -= node_size; //if the index isnt in the item, then go to the next and subtract how many we looked at
    curr = curr->next;
  }

  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
