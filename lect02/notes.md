### Lecture 2: Abstract Data Types + implementing custom classes that behave intuitively 

## Last lecture

We working with linked list
l : 1 -> 2 -> 3-> 4 -> null

If we want store a sequence of values, use the C++ STL!!
Options are:

Singly linked list -- Abstract Data Type: 
1. std::forward_list lst = {1, 2, 3, 4};
lst.push_front(0);
lst.pop_front();
lst.reverse();

2. std::list (double linked list)

3. std::vector (dynamically resizable array)
