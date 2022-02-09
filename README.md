# CMPSCI-4760:P1

Project Goal:
* Learning how to create chain of processes
* Understanding process inheritance

##How to run
Commands to run project from hoare server:

```
$ cd CMPSCI4760-p1
$ make
$ ./simplechain
```

##Task List
List of task and their description for Project - 1. 

#### Task 1
> Run your program and observe the results for different number of processes.

Observations after running with different number of processes:

* Parent ID of a process is sometime 1 instead of the process ID of previous process. This is happen becasue the parent terminates before its child and by a special system process (init) with PID as 1. 
* Process IDs are inceremnting with every run.
* Parent ID of first process is constant.
* Child of last process is 0 since the fork function returns 0 to the child and returns
the child's process ID to the parent.The last process is no longer parent.

#### Task 2
> Redraw Figure 3.2 by filling in actual PIDs of the processes in the figure for a run with command-line argument value of 4.

Redrawn Figure 3.2 [filename task2.PNG in git repo] by filling in actual PIDs of the processes in the figure for a run with command-line argument value of 4.
```
$ ./simplechain 4
```

#### Task 3
> Experiment with different values for the number of processes up to a maximum of 100 processes. Observe the fraction that are adopted by init.

To observe fraction that are adopted by init, I wrote a shell script newCmd.sh. It shows the fraction that are adopted by init in terminal. It also produces a file named file1 to showing all the processes and file named infile showing the processes that adopted by init. We need update the "pno" variable within the shell script for different number of processes.

Observation: Fraction is getting higher with the increasing number of processes.
```
$ ./newCmd.sh
```

#### Task 4
> Place sleep(10); directly before the final fprintf statement in the code. Make the previous observation again.

Can be found in git commit history with messege "Task 4 added"

Observation: Fraction became lower than before. Also, it's getting lower with the increasing number of processes. 

#### Task 5
> Put a loop around the final fprintf in your code. Have the loop execute k times. Put sleep(m); inside this loop just before the fprintf statement. Pass k and m using command line options. Run the program for several values of n, k, and m. Observe the results.



