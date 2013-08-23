QuickSort Algorithm
===================

About
------------
Quicksort is a comparison based sorting algorithm developed by Tony Hoare that, on average, makes O(n log n) comparisons to sort *n* items.
In the worst case, it makes O(n^2) comparisons, though this behavior is rare. 
Quicksort is often faster in practice than other O(n log n) algorithms.

Running code examples
------------
**C** implementation:

You should compile the source file first.

    cd C/
    gcc -o QuickSort QuickSort.c (Linux)
    ./QuickSort ../in/inputBig.txt (Linux)
    
    compile with Visual Studio | MinGW | DevC++ (Windows)
    QuickSort.exe ../in/inputBig.txt (Windows)

**Java** implementation:

Contains also a JUnit test file.

Used java 1.6.0_33, junit 4.10 to compile source files.

    cd Java/
    java QuickSort ../in/inputBig.txt (Windows & Linux)
    java -cp "<path_to_junit_4.x_jar_file>;./" org.junit.runner.JUnitCore QuickSortTest (Windows)
    java -cp "<path_to_junit_4.x_jar_file>:./" org.junit.runner.JUnitCore QuickSortTest (Linux)

To compile yourself the source files:

    cd Java/
    javac QuickSort.java (Windows & Linux)
    javac -cp "<path_to_junit_4.x_jar_file>;./" QuickSortTest.java (Windows)
    javac -cp "<path_to_junit_4.x_jar_file>:./" QuickSortTest.java (Linux)

For the input files in *in/* folder the expected results are: the sorted vectors.
