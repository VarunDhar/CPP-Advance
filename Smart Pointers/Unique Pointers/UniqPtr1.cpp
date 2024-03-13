#include<iostream>
#include<memory>
using namespace std;
int main(){
  //Smart pointers are mainly helpful for the purpose of automatic memory deallocation, hence preventing memory leaks.
  unique_ptr<int> ptr1 = make_unique<int>(20); // creating a unique pointer pointing to address storing value 20.
  cout<<*ptr1 <<" "<<ptr1; //Prints 20 and address ptr1 is pointing to.
  // unique_ptr<int> ptr2 = ptr1; Compilation error, as the unique pointer follows the property of exclusive ownership, hence, pointers cannot be shared.
  unique_ptr<int> ptr2 = move(ptr1);
  cout<<*ptr2 <<" "<<ptr2; //Prints 20 and address ptr2 (previously ptr1) is pointing to. Note, after using move ,ownership is transferred to ptr2 and ptr1 now becomes a nullpointer
}
