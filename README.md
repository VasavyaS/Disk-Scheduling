# Disk-Scheduling

Title: Implementing Disk Scheduling algorithms

Description:

Disk scheduling is done by operating systems to schedule I/O requests arriving for the disk. Disk scheduling is also known as I/O scheduling. Disk scheduling is important because:
-->Multiple I/O requests may arrive by different processes and only one I/O request can be served at a time by the disk controller. Thus other I/O requests need to wait in the waiting queue and need to be scheduled.
-->Two or more requests may be far from each other so can result in greater disk arm movement.
-->Hard drives are one of the slowest parts of the computer system and thus need to be accessed in an efficient manner.

In our program we follow the below steps to solve the above stated problem:

We simulate the motion of the disk arm by taking a set of requests for cylinders/tracks to read and then determining the order in which they will be read. We also calculate the total distance (number of cylinders) the disk arm had to traverse in the three algorithms using the same set of random numbers.

We generate the requests randomly and pass it through all the algorithms. We assume the disk arm starts at track 50.

Process to run:

To run, download DiskScheduling.cpp file. In the Ubuntu terminal, run the below command from the folder where the file is located to compile the program:

g++ DiskScheduling.cpp 

On compiling you would notice an a.out file is generated. Now run the below command to get the output:

./a.out

References:

www.freecodecamp.org
www.geeksforgeeks.org
www.stackoverflow.com



