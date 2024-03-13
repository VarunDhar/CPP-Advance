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
  unique_ptr<MyClass> ptr1= make_unique<MyClass>();
  //console will print "Constructor called".
  //In unique pointers, memory deallocation occurs at the end of the scope. So, to showcase this, we can create a separate scope.
  {
    unique_ptr<MyClass> ptr2= make_unique<MyClass>();
    //"Constructor called" prints
  }// as the end of the scope is reached, the destructor will be called for ptr2, and "Destructor called will be printed".
}
