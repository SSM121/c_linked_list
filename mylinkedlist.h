#ifndef My_linked_list_H // checks to make sure that this header wasnt already included
#define My_linked_list_H
#include <stdio.h>//standard input output
#include <stdlib.h>//extra library of useful stuff
#include <math.h>//provides the log10 function
//creates a struct named node with an int and a pointer back to another node
struct node
{
	int value;
	struct node *next;
};


struct node *add_to_list(struct node *first, int n);//add to list prototype 
struct node *bubbleSort(struct node *first);//bubblesort prototype 
void swap(struct node *a, struct node *b);//swap prototype
struct node *removeDuplicates(struct node *first);//rempove duplicates prototype
#endif