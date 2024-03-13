#include<iostream>
#include<memory>
using namespace std;
class MyClass{
  public:
  MyClass(){y
    cout<<"Constructor called";
  }
  ~MyClass(){
    cout<<"Destructor called";
  }
}
int main(){
  //the unique thing about a Weak pointer is, unlike a shared pointer, it doesn't keep the memory location alive when all the strong references have been destroyed.
  //Note - Shared pointer comes under strong references (strong pointers)
  weak_ptr<MyClass> weakptr1; 
  {
    shared_ptr<MyClass> sharedptr1= make_shared<MyClass>();
    //"Constructor called" prints
    weakptr1 = sharedptr1;
    //here, if we check, the memory location sharedptr1 points to has 1 weak reference and one strong reference(sharedptr1 itself).
    //so once the end of scope is reached, sharedptr1 will be destroyed, destructor will be called and the memory will be deallocated.
  }// as the end of the scope is reached, the destructor will be called for sharedptr1, and "Destructor called will be printed".

  //Now weakptr1 will store the address of the memory that sharedptr1 was pointing too, but that memory has been deallocated.
}
