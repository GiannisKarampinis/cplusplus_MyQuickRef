# My Quick Reference Guide for C/C++ Development
<br><br>
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

# 3. Difference Between `push_back` and `emplace_back` for `std::vector` in C++

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
### `emplace_back`
- **Function**: `emplace_back` takes arguments that are forwarded to the constructor of the element being added. This means it constructs the element in-place at the end of the vector.
- **Construction**: It constructs the element directly in the memory allocated for the vector, thus avoiding unnecessary copying or moving. This can lead to better performance, especially for complex types that are expensive to copy or move.
- **Example**:
- ```cpp
  std::vector<std::pair<int, std::string>> vec;
  vec.emplace_back(10, "example"); // Directly constructs std::pair<int, std::string>(10, "example") at the end of the vector

### Key Differences
- **Efficiency**: emplace_back is often more efficient because it constructs the element directly in place, avoiding the overhead of copying or moving the element.
- **Construction**: push_back requires an existing object to be passed to it, while emplace_back can construct the object directly from the arguments provided.
- **Usage**: emplace_back is especially useful when the element to be added is constructed from multiple arguments or when the construction of the element is expensive and you want to avoid unnecessary copies or moves.

### Summary
In summary, use push_back when you already have an object to add to the vector and emplace_back when you want to construct the object directly in place with the provided arguments.

Sure! Here's a complete Markdown-formatted explanation you can include in your GitHub documentation or README:

# 🏷️ Pointer Tagging in C

## What is Pointer Tagging?
Pointer tagging is a low-level programming technique where you use unused bits of a pointer to store metadata — typically a small flag or tag — without needing extra memory or data structures.

This is possible because of **pointer alignment**.

---

## 📏 Memory Alignment and Least Significant Bits (LSBs)

Most data types are **aligned** in memory for performance and architectural reasons. For example, on most systems:
- An `int` is 4 bytes and aligned to 4-byte boundaries.
- This means its memory address must be divisible by 4.
- Valid addresses might be: `0x1000`, `0x1004`, `0x1008`, etc.

In binary, these aligned addresses **end in two zero bits**:
- `0x1004` = `0001 0000 0000 0100`
- The least significant bits (LSBs), bits 0 and 1, are `00`

Since these bits are guaranteed to be `0`, they can be reused for other purposes without affecting the actual pointer.

---

## 💡 How to Use Tagged Pointers

You can safely store flags in those unused bits. Here's a practical example using C:

```c
#include <stdint.h>
#include <stdio.h>

int main() {
    int x = 42;
    int *ptr = &x;

    // Tag the pointer (set bit 0)
    uintptr_t tagged = ((uintptr_t)ptr) | 0x01;

    // Check if tagged
    if (tagged & 0x01) {
        printf("Pointer is tagged.\n");
    }

    // Recover original pointer
    int *real_ptr = (int *)(tagged & ~0x01);
    printf("Original value: %d\n", *real_ptr);

    return 0;
}
```
## 🔐 Why Use Pointer Tagging?
Memory Efficiency: No extra fields or memory needed for flags.

Performance: Avoids cache misses and memory allocations.

Concurrency: Often used in lock-free data structures to store version bits or mark deletion.

## ⚠️ Warnings
Only use tagging if you're absolutely sure those bits are unused (i.e., due to guaranteed alignment).

Always cast pointers to uintptr_t for bitwise operations and back.

Never dereference a tagged pointer without untagging it first.

## ✅ Summary
Aligned memory addresses end in 0 (in binary), leaving some LSBs unused.

uintptr_t safely casts pointers to integers and back.

Tagged pointers are useful for metadata storage without extra space.

Commonly used in systems programming, memory allocators, and concurrent data structures.
