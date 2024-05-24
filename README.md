# My Quick Reference Guide for C/C++ Development


# StaticMembers.cpp
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

# TemplateUsages.cpp
Templates are basically a set of orders/rules to the compiler, to write code for us. The basic purpose of templates is to create a function that its body could be the same but it will be called for different types. The templated function IS NOT an actual function. It is created only when it's called based on how it's called. Even if there could be syntax errors, in case of not calling the function, some compilers even won't prompt for those errors. 
