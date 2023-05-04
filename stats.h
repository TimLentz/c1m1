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
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
struct report{
    int min, max;
    float median, mean;
};
/**
 * @brief prints the statistics of an array
 *
 * prints minimum, maximum, mean, and median
 *
 * @param struct report contains statistics
 */
void print_statistics(struct report);
/**
 * @brief prints an array
 *
 * @param char[] contains input data
 * @param len length of input array
 */
void print_array(unsigned char[], int);
/**
 * @brief finds the median of an array
 *
 * @param char[] contains input data
 * @param len length of input data
 *
 * @return float median of the array
 */
float find_median(unsigned char[], int);
/**
 * @brief finds the mean of an array
 *
 * @param char[] contains input data
 * @param len length of input data
 *
 * @return float mean of the array
 */
float find_mean(unsigned char[], int);
/**
 * @brief finds the max of an array
 *
 * @param char[] contains input data
 * @param len length of input data
 *
 * @return int max of the array
 */
int find_maximum(unsigned char[], int);
/**
 * @brief finds the min of an array
 *
 * @param char[] contains input data
 * @param len length of input data
 *
 * @return int min of the array
 */
int find_minimum(unsigned char[], int);
/**
 * @brief sorts the array from greatest to least
 *
 * @param char[] contains input data
 * @param len length of input data
 */
void sort_array(unsigned char[], int);

#endif /* __STATS_H__ */
