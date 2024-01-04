# Rat-in-a-Maze

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1).
We need to find all the possible paths for the rat to reach its destination.
The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). 
![image](https://github.com/M2rider/Rat-in-a-Maze/assets/129592380/5c9e6f55-ccdf-49b1-9a59-fd286c972946)

Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.
In a path, no cell can be visited more than one time.
![image](https://github.com/M2rider/Rat-in-a-Maze/assets/129592380/f7a7052a-b3b6-4111-bf79-66e5454d00e0)

I solved this problem using Backtracking.

Approach:
1. Start at the source(0,0) with an empty string and try every possible path i.e upwards(U), downwards(D), leftwards(L) and rightwards(R).
2. As the answer should be in lexicographical order so it’s better to try the directions in lexicographical order i.e (D,L,R,U)
3. Declare a 2D-array named visited because the question states that a single cell should be included only once in the path,so it’s important to keep track of the visited cells in a particular path.
4. If a cell is in path, mark it in the visited array.
5. Also keep a check of the “out of bound” conditions while going in a particular direction in the matrix. 
6. Whenever you reach the destination(n,n) it’s very important to get back as shown in the recursion tree.
7. While getting back, keep on unmarking the visited array for the respective direction.Also check whether there is a different path possible while getting back and if yes, then mark that cell in the visited array.
