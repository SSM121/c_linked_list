

#include "mylinkedlist.h"

/*************************
*Function Name: Main
*Summary: compute the logs of a list
*Inputs: two file names
*outputs: a file with them sorted and logs calculated
*Compile instructions: gcc -o LogTable.exe LogTable.c mylinkedlist.c
*Run instructions: after the function is called enter an existing input file then write the output file.
***********************
*psedocode:
*begin
* call a struct node to keep track of first
* get to things of type file and set as the input and output files. 
* open input file
* if the file = null 
*  print error
* open output file
* if the file is null
*  display error
* set first via running scan list
* set first due to bubble sort
* set first due tp remove duplicates
* run print file
* close both files
*end
***********************/
struct node *scan_file(FILE *ifile, struct node *first);
void print_file (struct node *first, FILE *ofile);



int main (int argc, char *argv[])
{

struct node *first = NULL;


FILE *ifile;
FILE *ofile;
int n, i;
ifile = fopen(argv[1], "r");
if (ifile == NULL)
{
	fprintf(stderr, "Insulting error message.\n");
	exit(1);
	}
	ofile = fopen(argv[2], "w");
	if (ofile == NULL)
	{
		fprintf(stderr, "Insulting error message 2.\n");
		exit(1);
		}
		
	first = scan_file(ifile, first);
	first = bubbleSort(first);
	first = removeDuplicates(first);
	print_file(first, ofile);
	fclose (ifile);
	fclose (ofile);
	return 0;
}
/*************************
*Function Name: scan_file
*Summary: reads the contents of the input file and prints to a list
*Inputs: a file name and a struct
*outputs: a struct

***********************
*psedocode:
*begin
* while loop if not the end of file
*  if scan is an intager
*   run the add to list funcrtion
*  endif
*end
***********************/
struct node *scan_file(FILE *ifile, struct node *first)
{
	while(!feof(ifile))
	{
		int i, n;
		
		if (fscanf(ifile, "%d", &n))//i==1 true
		{
			first = add_to_list(first, n);
		}
	}
	return first;
	
	
}
/*************************
*Function Name: print_file
*Summary: prints each number and there respected log from the list into the output file
*Inputs: a file name and a struct
*outputs: void

***********************
*psedocode:
*begin
* while loop first is not null
*  print the first number then a tab then the log then a new line
*  set first to the pointer first was in
*end
***********************/
void print_file (struct node *first, FILE *ofile)
{
	
	while (first != NULL)
	{
		fprintf(ofile, "%d\t%f\n", first->value, log10(first->value));
		first = first->next;
		
	}
}
	