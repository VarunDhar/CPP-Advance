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
  shared_ptr<MyClass> ptr1= make_shared<MyClass>(); // Shared pointers 
  //console will print "Constructor called".
  cout<<"Shared pointers: "<<ptr1.use_count(); // this function gives the count of shared owners for the specific memory address. Here it will print "Shared pointers: 1".
  //In shared pointers, destructor is called at the end of the scope, and  memory deallocation occurs when all the shared pointers (owners of the memory address) have been destroyed. So, to showcase this, we can create a separate scope.
  {
    shared_ptr<MyClass> ptr2= ptr1; //unlike unique pointers, here we can use equality assignment for the pointers, as the ownership isn't exclusive to one pointer.
    //"Constructor called" prints
    cout<<"Shared pointers: "<<ptr1.use_count(); // as a new owner has been added, this will print "Shared pointers: 2".
  }// as the end of the scope is reached, the destructor will be called for ptr2, and "Destructor called will be printed".
  cout<<"Shared pointers: "<<ptr1.use_count(); // as one owner was destroyed (destructor called for pointer ptr2), count will be reduced by 1 and it will print "Shared pointers: 1".
}
