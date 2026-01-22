# s21_matrix

## Information

### Historical Background

The first mentions of matrices (or as they were then called: "magic squares") were found in ancient China. 
They became famous in the middle of the 18th century thanks to the work of the famous mathematician Gabriel Cramer, who published his work "Introduction to the Analysis of Algebraic Curves", which described a fundamentally new algorithm for solving systems of linear equations. 
Soon after, the works of Carl Friedrich Gauss on the "classical" method of solving linear equations, the Cayley-Hamilton theorem, the works of Karl Weierstrass, Georg Frobenius, and other outstanding scientists were published. 
It was not until 1850 that James Joseph Sylvester introduced the term "matrix" in his work.

## Matrix

A matrix is a collection of numbers arranged in a fixed number of rows and columns.

Matrix A is a rectangular table of numbers arranged in m rows and n columns:

```
    1 2 3
A = 4 5 6
    7 8 9
```

```
     1  2  3  4
В =  5  6  7  8
     9 10 11 12
```

You can get the desired element with the help of indices, as follows
A[1,1] = 1, where the first index is the row number, the second is the column number.

Matrix A will have elements with the following indices:

```
    (1,1) (1,2) (1,3)
A = (2,1) (2,2) (2,3)
    (3,1) (3,2) (3,3)
```

The order of a matrix is the number of its rows or columns. 
The main diagonal of a square matrix is the diagonal from the upper left to the lower right corner. 
A rectangular matrix (B) is a matrix with the number of rows not equal to the number of columns. 
A square matrix (A) is a matrix with the number of rows equal to the number of columns.

A column matrix is a matrix with only one column:

```
    (1,1)
A = (2,1)
    (n,1)
```

A row matrix is a matrix that has only one row:

```
A = (1,1) (1,2) (1,m)
```

Tip: A column matrix and a row matrix are also often called vectors.

A diagonal matrix is a square matrix in which all elements outside the main diagonal are zero. 
An identity matrix is a diagonal matrix with all diagonal elements equal to one:

```
    1 0 0
A = 0 1 0
    0 0 1
```

A triangular matrix is a square matrix with all elements on one side of the main diagonal equal to zero.

```
    1 2 3
A = 0 4 5
    0 0 6
```

### Matrix structure in C language:

```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

## Build

The project is built using **gcc** and **make**. All build rules are defined in the provided `Makefile`.

### Build static library

To compile the source files and create the static library `matrix.a`:

```bash
make matrix.a
```

### Rebuild

To clean all build artifacts and rebuild the library from scratch:

```bash
make rebuild
```

### Clean

To remove all generated object files, static libraries, test binaries, and coverage files:

```bash
make clean
```

## Tests

Unit tests are implemented using the **Check** testing framework.

### Run unit tests

To build and execute all unit tests:

```bash
make test
```

This target compiles the test sources located in the `unit_tests` directory, links them with the `matrix.a` library, and runs the resulting test binary.

### Code coverage report

To generate a code coverage report using **gcov** and **lcov**:

```bash
make gcov_report
```

After execution, an HTML coverage report will be available in:

```
gcov_files/report/index.html
```

### Memory leak check

To run unit tests under **Valgrind** and check for memory leaks:

```bash
make valgrind
```

Only errors and leak information are displayed in the output.

### Code formatting

To check code formatting without modifying files:

```bash
make n
```

To automatically format the code using `clang-format`:

```bash
make i
```
