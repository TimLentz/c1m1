/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief This program analiyzes an array of data and creates 
 * a report
 *
 * This program contains functions that can analyze an array
 * of unsidnged char data and create a report on the maximum, 
 * minimum, mean, and median of the data set.
 *
 * @author Tim Lentz
 * @date 5/3/2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  struct report r;
  /* Statistics and Printing Functions Go Here */
  sort_array(test, SIZE);

  r.median = find_median(test, SIZE);
  r.mean = find_mean(test,SIZE);
  r.max = find_maximum(test,SIZE);
  r.min = find_minimum(test,SIZE);

  print_statistics(r);
  print_array(test,SIZE);
  
  
}

/* Add other Implementation File Code Here */

  void sort_array(unsigned char a[], int len){
    int i, n;
    for(i=0; i<len-1;i++){
      for(n=0; n<len-i-1; n++){
        if(a[n] < a[n+1]){
          int temp = a[n];
          a[n] = a[n+1];
          a[n+1] = temp;
        }
      }
    }
  }

  void print_statistics(struct report r){
    printf("Median: %.1f \n",r.median);
    printf("Mean: %.1f \n",r.mean);
    printf("Maximum: %d \n",r.max);
    printf("Minimum: %d \n",r.min);
  }

  void print_array(unsigned char a[], int len){
    printf("Array: ");
    for(int i=0; i<len; i++){
      printf("%d ", a[i]);
    }
    printf("\n");
  }

  float find_median(unsigned char a[], int len){
    if(len%2){
      return a[(len-1)/2];
    } else {
      return (a[len/2] + a[len/2 -1])/2;
    }
  }

  float find_mean(unsigned char a[], int len){
    int total=0;
    for(int i=0; i<len; i++){
      total+=a[i];
    }
    return total/len;
  }

  int find_maximum(unsigned char a[], int len){
    int max=a[0];
    for(int i=1; i<len;i++){
      if(a[i]>max){
        max=a[i];
      }
    }
    return max;
  }
  int find_minimum(unsigned char a[], int len){
    int min=a[0];
    for(int i=1; i<len;i++){
      if(a[i]<min){
        min=a[i];
      }
    }
    return min;
  }