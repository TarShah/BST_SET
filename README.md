This file will explain the commands that will be required to understand what the code actually does and ho wit functions:

1  Insert - This command will have 2 arguments. The set num indicates which set needs to be operated on (if set with this number does not exist already, then create it). ”data” indicates the data to be inserted into the set. Remember that after the insertion of data, the set properties must hold - specifically, the set should have unique elements in sorted order.
2  Delete - Similar to insert. In this case, if set with this number does not exist, return -1. One thing to note here is that - if the data to be deleted does not exist in the set, then do nothing and just print the original size of the set.
3  Belongs To - Check if the element ”data” belongs to the set ”set num”. If set does not
exist, return -1. Return 1 if it belongs, else return 0.
4  Union - Note that you need to store the result of union operation in set num1 (This means that set num2 will remain unchanged, unless set num1 is same as set num2). Ensure that the set properties hold even after union. If either of the sets doesn’t exist - create them.
5  Intersection - Similar instructions as Union.
6  Size - If set doesn’t exist, create and return 0.
7  Difference - Updates the first set to the differnce of both the sets.
8  Symmetric Difference - Updates the first set to the symmetric differnce of both the sets.
9  Print - Given the set number, print all its elements as comma-separated values. Do *not* include any whitespaces (Just include a linebreak at the end). 
