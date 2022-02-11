/**



 * @Author: Sanzida Hoque



 * @Date: 02/07/2022



**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {

    pid_t childpid = 0;
    int i, j;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s processes\n", argv[0]);
        return 1;
    }

    int opt, nprocs = 4, nchars = 80, sleeptime = 3, niters = 1;

    while ((opt = getopt(argc, argv, "s:p:c:i:")) != -1) {

        switch (opt) {
        case 's':
            sleeptime = atoi(optarg);
            break;

        case 'p':
            nprocs = atoi(optarg);
            break;

        case 'c':
            nchars = atoi(optarg);
            break;

        case 'i':
            niters = atoi(optarg);
            break;

        case '?':
            if (opt == 'c')
                perror("chain: Error: Option requires an argument");
            else
                perror("chain: Error: Unknown option character");
            return 1;

        }

    }

    fprintf(stderr, "sleeptime: %d\n", sleeptime);
    fprintf(stderr, "nprocs: %d\n", nprocs);
    fprintf(stderr, "nchars: %d\n", nchars);
    fprintf(stderr, "niters: %d\n", niters);

    //#### Task 3, 4 ####
    /*  for (i = 1; i < nprocs; i++) {
        //sleep(10);
        if (childpid = fork())
          break;
      }
      fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long) getpid(), (long) getppid(), (long) childpid);

    */
    //#### Task 5 ####

    /*   for (i = 1; i < nprocs; i++)
          if (childpid = fork())
             break;

       for(j = 1; j<= niters; j++) {
          sleep(sleeptime);
          fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
          }
    */
    //#### Task 6 ####

    /*    for (i = 1; i < nprocs; i++)
          if (childpid = fork())
             break;
       childpid = wait(NULL);
       for(j = 1; j<niters; j++) {
          //sleep(sleeptime);
          fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
          }

    */

    // n = atoi(argv[1]);

    //#### Task 7 ####
    /*   for (i = 1; i < nprocs; i++)
          if (childpid = fork())
             break;
       for(j = 1; j<=niters; j++) {
          sleep(sleeptime);
          fprintf(stderr, "i:%d ", i);
          fprintf(stderr, "process ID:%ld ", (long)getpid());
          fprintf(stderr, "parent ID:%ld ", (long)getppid());
          fprintf(stderr, "child ID:%ld\n", (long)childpid);
          }
    */
    //#### Task 8 ####

    char mybuf[nchars], c;

    /**  nchars characters from stdin one character at a time **/

    if (!isatty(STDIN_FILENO)) {
        perror("chain: Error: stdin is not a terminal");
        exit(EXIT_FAILURE);
    }

    for (j = 0; j <= nchars; j++) {
        c = getc(stdin);
        mybuf[j] = c;
    }

    mybuf[nchars] = '\0';

    /**  Redirect the stdin from a file **/

    /*    while (fgets(mybuf, nchars+1, stdin) != NULL){
        if (strlen(mybuf) == nchars){
          break;
         }
      else
      {
        perror("Not n charecter");
      }
    }*/

    for (i = 1; i < nprocs; i++)
        if (childpid = fork())
            break;

    fprintf(stderr, "%ld: %s\n", (long) getpid(), mybuf);

    return 0;

}
