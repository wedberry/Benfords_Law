/**
 * Generating random data
 */

// Use this file to implement the program that generates
// random data with first digits obeying Benford's Law

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int benfordDigit(){
  double r = ((double) rand()) / RAND_MAX;

  if (r < .3010) {  
     return 1;
  } else if (r < .4770) { 
     return 2;
  } else if (r < .6020){
     return 3;
  } else if (r < .6990){
     return 4;
  } else if (r < .7780){
     return 5;
  } else if (r < .8450){
     return 6;
  } else if (r < .9030){
     return 7;
  } else if (r < .9540){
     return 8;
  } else {
     return 9;
  }
}

int main(int argc, char *argv[]) {

  int numValues = 0;
  int numDigits = 0;
  int uniformDigit = 2;

  // Process arguments with getopt
  int c;
  while ((c = getopt(argc, argv, "n:d:")) != -1) {
    switch (c) {
      case 'n':
        numValues = atoi(optarg);
        break;
      case 'd':
        numDigits = atoi(optarg);
        break;
    }
  }
  for (int n = 0; n < numValues; n++) {
    int result = benfordDigit();
  
    for (int d = 0; d < numDigits - 1; d++) {
      result = result * 10 + uniformDigit;
    }
  
  printf("%d\n", result);
  }
  
}