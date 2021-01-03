## Interactive Problems
========================

- A problem where your solution interacts with a grader (problem judge)

Interacting with judge
======================

- Printing output on console/screen is an expensive operation
- Compiler tries to store the output in a buffer
- When the program terminates, then it prints all if the output at one go

Flushes the buffered output
C++
----
fflush(stdout) if using printf scanf
cout<<flush if using cin cout

cout<<endl = cout<<'\n'<<flush;

Java
----
System.out.flush()

Python
------
stdout.flush()