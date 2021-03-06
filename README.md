# CMPSCI-4760:P1

Project Goal:
* Learning how to create chain of processes
* Understanding process inheritance

###How to run
Commands to run project from hoare server:

```
$ cd CMPSCI4760-p1
$ make
$ ./chain -s 6 -p 20 -i 2 -c 2
```
or
```
./newCmd.sh
```
This shell script is mainly for task 3 and 4 to get fraction. Can be used for other tasks as well.
In final commit, except task 8, other are commented out and there highlighted comment for those.


##Task List
List of task and their description for Project - 1. 

Github: https://github.com/SanzidaH/CMPSCI4760-p1.git


#### Task 1
Can be found in commit history.
> Run your program and observe the results for different number of processes.

Observations after running with different number of processes:

* Parent ID of a process in this process chain is sometime 1 instead of the process ID of previous process. This is happen becasue the parent terminates before its child and by a special system process (init) with PID as 1. 
* Somtimes processe Ids on terminal is not in order. That is because process schedular selects the processes to run. 
* The Process IDs (value of i) are inceremnting with every run when loop break.
* Parent ID of first process is constant.
* Child of last process is 0 since the fork function returns 0 to the child and returns the child's process ID to the parent.The last process is no longer parent.


#### Task 2
Can be found in commit history.
> Redraw Figure 3.2 by filling in actual PIDs of the processes in the figure for a run with command-line argument value of 4.

Redrawn Figure 3.2 [filename task2.PNG in git repo] by filling in actual PIDs of the processes in the figure for a run with command-line argument value of 4.
```
$ ./simplechain 4
```

#### Task 3
Can be found in last commit commented out.
> Experiment with different values for the number of processes up to a maximum of 100 processes. Observe the fraction that are adopted by init.

To observe fraction that are adopted by init, I wrote a shell script newCmd.sh. It shows the fraction that are adopted by init in terminal. It also produces a file named file1 to showing all the processes and file named infile showing the processes that adopted by init. We need update the "pno" variable within the shell script for different number of processes.

Observation: Fraction is getting higher with the increasing number of processes. 
```
$ ./newCmd.sh
```

#### Task 4
Can be found in last commit commented out.
> Place sleep(10); directly before the final fprintf statement in the code. Make the previous observation again.

Can be found in git commit history with messege "Task 4 added"

Observation: Fraction became lower than before. Also, it's getting lower with the increasing number of processes. 

#### Task 5
Can be found in last commit commented out.
> Put a loop around the final fprintf in your code. Have the loop execute k times. Put sleep(m); inside this loop just before the fprintf statement. Pass k and m using command line options. Run the program for several values of n, k, and m. Observe the results.

Observation: 
* There are k*n processes.
* Sometime process apeared before parent.  that is because child process runs concurrently with parent process in fork system and 
processor can move to another process when one process is blocked
* Sleep 

#### Task 6
Can be found in last commit commented out.
>Modify the code by adding the wait function call before the final fprintf statement. How does this affect the output
of the program? Are you able to execute with a value of n as 100?

Observation: 
* All the same process ID become in descending order. This is because when the parent process called wait() system call, it went in suspended state till the child process terminated. Since it is a chain process, all the child process complete their task first, then their parents get chance to be in ready state and it continue to happend until the original process got terminated. 
* First function returns -1 that indicates an error has been occured. and that child status is reported since there is no child.
* Yes, I could execute with a value of n as 100.

#### Task 7
Can be found in last commit commented out.
> Modify your code by replacing the final fprintf statement with four fprintf statements, one each for the four integers displayed. Only the last one should output a newline. What happens when you run this program? Can you tell which process generated each part of the output? Run the program several times and see if there is a difference in the output.

Observation: 
* The process id, parent id and child id are not consistent with order. So, it is not possible to identify which process generated each part of the output. After running several time, some result are totally not in order, even the each integers are not in a line in order, mostly in bottom the results. So, the difference is, the inconsistency gets more visible with increasing number of processes. 

#### Task 8
First input took from stdin, then redirected stdin from file. They are separate and labelled with comments.
Observations:
* Total number of printed process is less than n (passed number of processes), most of cases 2 process is less while taking input from stdin. Same fro redirected input.
* The processes are in order.









