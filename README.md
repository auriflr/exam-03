_This repositories containes the solutions to exam 03 for 42 school: for specific requirements and moulinette tests, try the exam and suffer like the rest of us_

# EXAM 03 🫥
## level 00 (50/100) 🌱
### ft_scanf (variadic functions) 🔦
Man scanf says: The scanf() family of functions scans input according to a format, as described below.  This format may contain conversion specifiers; the results from such conversions, if any, are stored through the pointer arguments.  The scanf() function reads input from the standard input stream stdin, fscanf() reads input from the stream pointer stream, and sscanf() reads its input from the character string pointed to by s.
You must program a function, not a program, but you will find a program in the folder because I wanted to make sure to test thoroughly, which you should do as well especially during the exam

### get_next_line (string manipulation) 🧩
Ofc we all know get_next_line. We still program it as a function. The idea of the exercise is to fix the broken_GNL you will find in your folder. However, I find it much easier to write it from scratch. There are some hidden little tricks, but overall it's pretty simple. This version passes and I find it easy and fast.

### filter (string manipulation) ‼️
Filter must be run like this: echo 'abcdefg' | ./a.out abc
And the output should be '***defg' so basically it turns av[1] into stars for the string we echo into it. It's pretty straightforward! This is the only program out of the three. Remember it returns 1 on errors and it must use perror when an error occurs with malloc, realloc, free, etc.

## level 01 (100/100) 🌿
This level is about backtracking algorithms and problem solvings. 
### n_queens (backtracking) ♟️
The N_Queens is a popular programming and mathematical problem. Here you'll find an explanation: https://www.geeksforgeeks.org/dsa/n-queen-problem-backtracking-3/. I suggest looking into it. It will not be tested with negative values, but it will be tested with numbers up until eleven, to check that you are able to handle numbers under 9. 
### permutations (backtracking) 🔤 
The permutations problem is another very popular programming problem: you must return all the possible compilations (in alphabetical order) of the given input string. This is really fun to program and pretty easy. Here's a link to know more: https://www.hello-algo.com/en/chapter_backtracking/permutations_problem/.
### powerset 🔢
I'm bad at explaining maths, but basically you will pass it a string of numbers like this one ./a.out 3 0 1 2 3. The first number is the number you're supposed to find the sum of in the set of numbers that comes after it (0 1 2 3). The output will be: 
0 1 2
1 2
0 3
3
To know more: https://www.geeksforgeeks.org/dsa/power-set/.
### rip (you guessed it, it's backtracking) ⚙️
This program is all about the balance between parenthesis, which is very important when programming. Remember to compile like this: ./a.out '(()' | cat -A, and not ./a.out (() | cat -A.
