/**

 * @Author: Sanzida Hoque

 * @Date: 02/07/2022

**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char * argv[]) {

  pid_t childpid = 0;
  int i, j; // niter=1 , n=4, c=80, s=3;
  fprintf(stderr, "%d\n", argc);
  if (argc < 2) {
    fprintf(stderr, "Usage: %s processes\n", argv[0]);
    return 1;
  }
  int opt, nprocs = 4, nchars = 80, sleeptime = 3, niters = 1;
  // put ':' in the starting of the

  // string so that program can 

  //distinguish between '?' and ':' 

  while ((opt = getopt(argc, argv, "s:p:c:i:")) != -1){
    switch (opt){
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
    }
  }

  fprintf(stderr, "sleeptime: %d\n", sleeptime);
  fprintf(stderr, "nprocs: %d\n", nprocs);
  fprintf(stderr, "nchars: %d\n", nchars);
  fprintf(stderr, "niters: %d\n", niters);

  // n = atoi(argv[1]);

  // sleep(getopt (argc, argv, sleeptime));

  /* Make sure stdin is a terminal. */

  if (!isatty(STDIN_FILENO)){
    perror("chain: Error: Not a terminal");
    exit(EXIT_FAILURE);
  }

  char mybuf[nchars], c;
  for (j = 0; j < nchars; j++) {
    int len = read(STDIN_FILENO, & c, 1);
    if(len != 1)
      perror("chain: Error: Please enter one character at a time");
    mybuf[j] = c;
  }
  mybuf[nchars] = '\0';

  for (i = 1; i < nprocs; i++) {
    if (childpid = fork())
      break;
  }
  fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long) getpid(), (long) getppid(), (long) childpid);
  fprintf(stderr, "%ld: %s\n", (long) getpid(), mybuf);

  /*  char mybuf[nchars],c;

for (i = 1; i < nprocs; i++){
         if (childpid = fork())

         break;
   fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);

   for(j = 0; j < nchars; j++){

      read (STDIN_FILENO, &c, 1);

      mybuf[j] = c;}

   mybuf[nchars] = '\0';

   fprintf(stderr, "%ld: %s\n",(long)getpid(), mybuf);
   }*/

  return EXIT_SUCCESS;

}
