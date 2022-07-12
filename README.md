# N-Queens
PROBLEM STATEMENT:
The N Queen problem is the task of arranging N chess queens on a NxN 
hessboard in such a way that no two queens attack each other.

EXAMPLE:
The expected result is a binary matrix with 1s for the blocks containing queens.
The output matrix for the given 4 queen solution, for example, is as follows
               { 0,  1,  0,  0}
               { 0,  0,  0,  1}
               { 1,  0,  0,  0}
               { 0,  0,  1,  0}

APPROACH:
The objective is to place queens in different columns one by one,
starting with the leftmost column. We check for clashes with already
placed queens when placing a queen in a column. If we locate a row in
the current column with no collision, we mark that row and column as part
of the solution. We backtrack and return false if we can't discover such
a row due to clashes.
