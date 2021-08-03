# Intro-to-C-Exercises

## Project description

As a part of my introduction to the programming language **C**, I coded nine basic problems that deal with a combination of linked lists, string manipulation, Hash tables, BSTs and more. In total, there are nine tasks and below are brief descriptions of each task (if you choose to look into more detail of the input and output, see the original .pdf, which you can find it [here](task.pdf). Note that each task is named "first", "second" etc. 

## Nine tasks:

Here are the nine tasks are a brief introduction into C-programming (and the links to them - have a look! :blush:):

1. **[first](/first/) - Right Truncatable Prime:** A program that will read an array from a file and print if the numbers in the file are right truncatable primes. A right truncatable prime is a prime number, where if you truncate any numbers from the right, the resulting number is still prime. For example, 3797 is a truncatable prime number number because 3797, 379, 37, and 3 are all primes.
2. **[second](/second/) - Linked Lists:** In this part, I had to implement a linked list that maintains a list of integers in sorted order. Thus, if the list contains 2, 5 and 8, then 1 will be inserted at the start of the list, 3 will be inserted between 2 and 5 and 10 will be inserted at the end.
3. **[third](/third/) - Hash tables:** In this part, I implemented a hash table containing integers. The hash table has 1000 buckets. An important part of a hash table is collision resolution. In this assignment, I used chaining with a linked list to handle a collision. This means that if there is a collision at a particular bucket then you will maintain a linked list of all values stored at that bucket. Note that a linear search was not implemented of the 1000 element array (resulting in a worst case run-time of O(n)). Hash function: key modulo the number of buckets.
4. **[fourth](/fourth/) - Matrix Multiplication:**  In this task, I created a program that multiplies two matrices and outputs the resulting matrix. The input matrices can be the same or different sizes. One of the main focuses of this task was to practice and test our ability to manage memory using malloc(). 
5. **[fifth](/fifth/) - Matrix Squares:** A magic square is an arrangement of the numbers from 1 to n<sup>2</sup> in an (n x n) matrix, with each number occurring exactly once, and such that the sum of the entries of any row, any column, or any main diagonal is the same. This program is supposed to take in information of the matrix oa neighboring .txt file, and then check if the matrix is in the magic square arrangment or not.
6. **[sixth](/sixth/) - Pig Latin:** In this program, I wrote C code that would read an input string from the argument (console) representing a sentence, and convert it into pig latin. Some assumptions in the user-input string is that there will be only characters and no numbers or punctuation. As a reference, the rules of pig latin are:

     * If the word begins with a consonant then take all the letters up until the first vowel and put them at the end and then add “ay” at the end.
     * If the word begins with a vowel then simply add “yay” to the end.

7. **[seventh](/seventh/) - String Operations:** In this task, I read an input string representing a sentence, formed a word whose letters are the last letters or punctuation of the words in the given sentence, and printed it. Here are some examples:
```
$./seventh Hello World!
o!
$./seventh Welcome to CS211
eo1
$./seventh Rutgers Scarlet Knights
sts
```
8. **[eighth](/eighth/) - Binary Search Tree:** For this program, I implemented a binary search tree that satisfies the binary search tree property: the key in each node must be greater than all keys stored in the left sub-tree, and smaller than all keys in right sub-tree. I also dynamically allocated space for each node and freed the space for the nodes at the end of the program.
9. **[ninth](/ninth/) - Deletion with BST:** This last program is an extension of the previous task where I also add code to accomodate a deletion feature. For one child, it is straightforward - you make the parent of the node to be deleted point to that child. In this scenario, special attention must be paid only when the node to be deleted is the root. Deleting a node with two children requires some more work. In this case, you must find the minimum element in the right subtree of the node to be deleted. Then you insert that node in the place where the node to be deleted was. This process needs to be repeated to delete the minimum node that was just moved.

## How can I view this project?

Viewing this project is pretty straightforward. Pick a task that you want to view, download the folder of that task, make the Makefile and executable (it should be made for you already but you can do it again just in case), and run! Have a look at [task.pdf](task.pdf) in order to know what to put in the arguments or the format of the .txt files that need to be scanned in to run the program. 
