/**
 * Validating Benford's Law
 */

// Use this file to implement the program that reads
// Census data and compares the distribution of population
// digits to Benford's Law

/**
 * Validating Benford's Law for Census data
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Open the file
  FILE *f = fopen("co-est2021-alldata.csv", "r");

  // Check the return code
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  // Declare character buffer
  char buf[1024];

  int firstLine = 1;

  float numLines = 0;
  
  float numDigits[10];
  for (int i = 0; i < 10; i++){
    numDigits[i] = 0;
  }
  
  // Loop over the remaining lines that have data
  while (fgets(buf, sizeof(buf), f) != NULL) {

    // Skip the first line that contains the field names
    if (firstLine) {
      firstLine = 0;
      continue;
    }

    // get the 10th value
    char *token;
    token = strtok(buf, ",");
    for (int i = 0; i < 8; i++){
      token = strtok(NULL, ",");
      }

    // Get the first digit
    char firstDigit = *token;
    
    numLines += 1;
    int value;
    value = firstDigit - '0';
    numDigits[value] += 1;
  }

  float percentages;

  for (int i = 0; i < 10; i++){
    percentages = numDigits[i] / numLines;
    printf("Fraction of Leading %d's: %.4f\n", i, percentages);
  }
  return 0;
}