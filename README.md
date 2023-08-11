This file will explain the commands that will be required to understand what the code actually does and ho wit functions:

1  Insert - This command will have 2 arguments. The first number indicates which set needs to be operated on (if set with this number does not exist already, then create it). 
Second number indicates the data to be inserted into the set. 
Remember that after the insertion of data, the set properties hold - specifically, the set has unique elements in sorted order. 

2  Delete - Similar to insert. In this case, if set with this number does not exist, it returns -1. 
One thing to note here is that - if the data to be deleted does not exist in the set, then nothing is done and it prints the original size of the set. 

3  Belongs To - Check if the element (second number) belongs to the set (first number). 
If set does not exist, return -1. 
Return 1 if it belongs, else return 0. 

4  Union - Stores the result of union operation in set num1 (This means that set num2 will remain unchanged, unless set num1 is same as set num2). Ensure that the set properties hold even after union. If either of the sets doesn’t exist - it creates them.

5  Intersection - Similar instructions as Union.

6  Size - If set doesn’t exist, ir creates them and returns 0.

7  Difference - Updates the first set to the difference of both the sets, rest similar to Union.

8  Symmetric Difference - Updates the first set to the symmetric differnce of both the sets, rest similar to Union.

9  Print - Given the set number, print all its elements as comma-separated values. 

// New sets numbers should be created in a consecutive order
