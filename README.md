# SudokuSolver
About : In this project I have created a solver which will solve a 9X9 Sudoku entered by the user.

Tools Required : Code Editor, GCC Compiler

Language Used : C++

Algorithm Used : Backtracking

#Functions :
01. main() :- It will show a user-friendly menu to user and call the respective function based upon user selection.
02. input() :- It will take input from user in the form of 9X9 matrix and pass the matrix for further process.
03. SolveSudoku() :- In this function we will apply backtracking by taking one number form 1-9 we will try to find the whole solution if we get the answer then it will return true otherwise we come backtrack to this function and change the previous value. We will do this till we get the solution or if the solution is not possible we will show the message to user.
04. isValid() :- To check that the input is valid or not. Input is invalid if the no. enter is already present in respective row, column and 3X3 Matrix.
05. FindEmpty() :- It will find the empty spaces in the matrix (Empty Spaces are denoted by ‘0’) and as the row and column is passed by reference we will get the row number and column number of the empty space.
06. isSafe() :- It will call all the functions which are required to be true so that all the conditions for solving the sudoku is fulfilled.
07. SafeInRow() :- It will check that the number we are picking (or passing from SolveSudoku() function) should not be present in the row.
08. SafeInCol() :- It will check that the number we are picking (or passing from SolveSudoku() function) should not be present in the column.
09. SafeInBox() :- It will check that the number we are picking (or passing from SolveSudoku() function) should not be present in the respective 3X3 matrix.
10. inst() :- It will tell the user instructions to enter the data in the program.
11. about() :- It will tell the user about Sudoku.
12. print() :- It will print the resultant matrix.
