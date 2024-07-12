# My Quick Reference Guide for C/C++ Development


# 1. StaticMembers.cpp
A static member inside a class is a shared member or resource of all the objects created from that class. All objects of that class will share the same resource (copy) and access this same member which is allocated only once. (It is basically a class characteristic and not an object’s one.)

When defining a static member we should declare it once again outside of the class definition to be visible in other code parts as well (global variable but with scope resolution to be accessible through the class only).

When we declare a static method this can only access static variables!

NOTE:
A static class member is allocated only once for all the objects of that class. 

We can access the static members and static function either through the object or through the class name with scope resolution specifier.

In the example StaticMembers.cpp you will find out that interestingly while constructing the 2 objects of the class Test count is incremented by one each time so the final result while printing the count variable in the first 2 print statements will be 2.

The huge benefit of utilizing the static member:
Assume that you have a Class constructing cars. You want to know the price of that car without constructing a car. So the price will be a static member.

Or either if you want to specify prefixes when creating objects.

The same with global or static variables inside functions.

Main usages:

1.  counter
2.  shared memory
3.  read write
4.  provide information about the class

# 2. TemplateUsages.cpp
Templates are basically a set of orders/rules to the compiler, to write code for us. The basic purpose of templates is to create a function that its body could be the same but it will be called for different types. The templated function IS NOT an actual function. It is created only when it's called based on how it's called. Even if there could be syntax errors, in case of not calling the function, some compilers even won't prompt for those errors. 

## Difference Between `push_back` and `emplace_back` for `std::vector` in C++

In C++, `std::vector` provides two methods for adding elements to the end of the vector: `push_back` and `emplace_back`. Both methods serve to append elements, but they have differences in terms of how they handle the construction of elements. Here’s a detailed comparison:

### `push_back`
- **Function**: `push_back` takes a single argument, which is the value to be added to the end of the vector.
- **Construction**: It constructs a copy of the argument and adds that copy to the vector. This means that if the argument is a temporary or an object that can be moved, a move constructor will be used. If the argument is an lvalue, a copy constructor will be used.
- **Example**:
  ```cpp
  std::vector<int> vec;
  int value = 10;
  vec.push_back(value); // Uses copy constructor
  vec.push_back(20);    // Uses move constructor if possible

