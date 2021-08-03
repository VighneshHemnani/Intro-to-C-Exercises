# Intro-to-C-Exercises

## Project description

As a part of my introduction to the programming language **C**, I coded nine basic problems that deal with a combination of linked lists, string manipulation, Hash tables, BSTs and more all in C. There are in total nine tasks and below are brief descriptions of each task (if you choose to look into more detail of the input and output, see the original .pdf, which you can find it [here](task.pdf). Note that each task is named "first", "second" etc. 

## Nine tasks:

Here are the nine tasks are a brief introduction into C-programming:

1. **first - Right Truncatable Prime:** A program that will read an array from a file and print if the numbers in the file are right truncatable primes. A right truncatable prime is a prime number, where if you truncate any numbers from the right, the resulting number is still prime. For example, 3797 is a truncatable prime number number because 3797, 379, 37, and 3 are all primes.
2. **second - Linked Lists:** In this part, I had to implement a linked list that maintains a list of integers in sorted order. Thus, if the list contains 2, 5 and 8, then 1 will be inserted at the start of the list, 3 will be inserted between 2 and 5 and 10 will be inserted at the end.
3. **third - Hash tables:** In this part, I implemented a hash table containing integers. The hash table has 1000 buckets. An important part of a hash table is collision resolution. In this assignment, I used chaining with a linked list to handle a collision. This means that if there is a collision at a particular bucket then you will maintain a linked list of all values stored at that bucket. Note that a linear search was not implemented of the 1000 element array (resulting in a worst case run-time of O(n)). Hash function: key modulo the number of buckets.
4. **fourth - Matrix Multiplication:**  In this task, I created a program that multiplies two matrices and outputs the resulting matrix. The input matrices can be the same or different sizes. One of the main focuses of this task was to practice and test our ability to manage memory using malloc(). 
5. **fifth - Matrix Squares:** A magic square is an arrangement of the numbers from 1 to n<sup>2</sup> in an (n x n) matrix, with each number occurring exactly once, and such that the sum of the entries of any row, any column, or any main diagonal is the same. This program is supposed to take in information of the matrix oa neighboring .txt file, and then check if the matrix is in the magic square arrangment or not.
6. **sixth - Pig Latin:** In this program, I wrote C code that would read an input string from the argument (console) representing a sentence, and convert it into pig latin. Some assumptions in the user-input string is that there will be only characters and no numbers or punctuation. As a reference, the rules of pig latin are:

     * If the word begins with a consonant then take all the letters up until the first vowel and put them at the end and then add “ay” at the end.
     * If the word begins with a vowel then simply add “yay” to the end.

7. **seventh - String Operations:** In this task, I read an input string representing a sentence, formed a word whose letters are the last letters or punctuation of the words in the given sentence, and printed it. Here are some examples:

```
$./seventh Hello World!
o!
$./seventh Welcome to CS211
eo1
$./seventh Rutgers Scarlet Knights
sts
```

8. **eighth - Binary Search Tree:** For this program, I implemented a binary search tree that satisfies the binary search tree property: the key in each node must be greater than all keys stored in the left sub-tree, and smaller than all keys in right sub-tree. I also dynamically allocated space for each node and freed the space for the nodes at the end of the program.
9. **ninth - Deletion with BST:** This last program is an extension of the previous task where I also add code to accomodate a deletion feature. For one child, it is straightforward - you make the parent of the node to be deleted point to that child. In this scenario, special attention must be paid only when the node to be deleted is the root. Deleting a node with two children requires some more work. In this case, you must find the minimum element in the right subtree of the node to be deleted. Then you insert that node in the place where the node to be deleted was. This process needs to be repeated to delete the minimum node that was just moved.

## How can I view this project?

1. You can view the .mp4 video demonstration of the webapp as well as the database in its entirety by going to the [demo video](demo_video.mp4) OR
2. You can download and run the files as you like:

Software needed:

   - Tomcat (or any preferred alternative)  
   - A browser (Safari, Chrome etc.)  
   - Database Management Tool (like MySQL Workbench)  
   - IDE (like Eclipse)  

   To view this project, you would first need to recreate the tables in the database: using your preferred software, you can use the creation table code in  [create_table_statements.pdf](create_table_statements.pdf) to create the empty tables. Then, you can import the sample data points that were provided to us so that way, you can view and run the code in the webapp. Then, once you have done that, you can download the webapp folder and run the [index.jsp](webapp/index.jsp) in your preferred IDE. Ensure that Tomcat is installed and working correctly, and then you can run the website on whichever browser you prefer.

## What can I find in this repo?

Here's a list of all the files in this repo and what they are:

1. [constraint_checking.pdf](constraint_checking.pdf) - A .pdf file that contains two queries that checks two constraints to ensure the database has been set up correctly.
2. [database.sql](database.sql) - A .sql file that contains all the tuples/data of each bar, beer, drinker and more information that was used in the database for this project. 
3. [demo_video.mp4](demo_video.mp4) - A .mp4 that runs through the entire project briefly: a sitemap of the web application, the database schema, the constraint checking, sample user testing of the dynamic queries' output via table and graphs as well as dynamic updation and deletion (plus error catching). 
4. [webapp](/webapp/) - A simple and clean web application made in Eclipse using HTMl, CSS and Javascript that displays tables and graph of results of dynamic queries from the user. Once set up properly, the web application also allows the user to dynamically update, modify or delete tuples from the database. Here are a few .gifs that help visualize the entire web application and a brief sitemap if you don't want to download and watch the demonstration video. 
5. [create_table_statements.pdf](create_table_statements.pdf) - A .pdf file that allows you to see the CREATE TABLE statements used in the SQL database. This also contains the different variables, primary keys and foriegn keys for each table.
