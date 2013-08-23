/**
 * Sorting a vector via QuickSort algorithm in O(n * log n) on average.
 *
 * @author      Bogdan Constantinescu <bog_con@yahoo.com>
 * @since       2013.08.03
 * @version     1.0
 * @link        GitHub    https://github.com/z3ppelin/QuickSort
 * @licence     The MIT License (http://opensource.org/licenses/MIT); see LICENCE.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QuickSort.h"

/**
 * Main function. Reads vector, sorts it, and prints it.
 * @param     argc       Command line arguments no.
 * @param     argv       Command line arguments.
 * @return               Success/error code. (0 is a success, anything else is error).
 */
int main(int argc, char** argv) {
	printf("------ Begin QuickSort ------\n");
	int n, i = 0;
	int* vectorToSort;
	clock_t start, end;
	char error[128];

	/* read vector */
	if (argc == 1) {
		err("Err. The input file must be given as an argument.\n");
	}
	if (!readVectorFromFile(&vectorToSort, &n, argv[1], error)) {
		err(error);
	}

	/* print read vector */
	//printf("The read vector is: ");
	//printVector(vectorToSort, n);
	//printf("\n");

	/* sort vector */
	start = clock();
	quickSort(vectorToSort, 0, n - 1);
	end = clock();

	/* print sorted vector */
	printf("The sorted vector is: ");
	printVector(vectorToSort, n);
	printf("\n");

	/* free memory */
	free(vectorToSort);

	printf("Elapsed: %f seconds while sorting.\n", (double) (end - start) / CLOCKS_PER_SEC);
	printf("------- End QuickSort -------\n");
	return EXIT_SUCCESS;
}

/**
 * Prints error and exits program.
 * @param    msg   The error to print.
 */
void err(const char* msg) {
	printf(msg);
	printf("------- End QuickSort -------\n");
	exit(EXIT_FAILURE);
}

/**
 * Recursive function (based on Divide and Conquer algorithm) that sorts a vector (via QuickSort algorithm).
 * @param    v                    The vector to sort.
 * @param    left                 The left margin of the vector.
 * @param    right                The right margin of the vector.
 */
void quickSort(int* v, const int left, const int right) {
	if (left < right) {
		int i = partition(v, left, right);
		quickSort(v, left, i - 1);
		quickSort(v, i + 1, right);
	}
}

/**
 * Partition the vector, choose a pivot and arrange all elements lower
 * than it to the left, elements bigger than it to the right.
 *
 * @param    v                    The vector to sort.
 * @param    left                 The left margin of the vector.
 * @param    right                The right margin of the vector.
 * @return                        The pivot position.
 */
int partition(int* v, const int left, const int right) {
	int i = left + 1, j, aux, pivot, pivotPos;

	srand(time(NULL));
	pivotPos = (rand() % (right - left)) + left;
	pivot = v[pivotPos];

	/* make the pivot the first element */
	v[pivotPos] = v[left];
	v[left] = pivot;

	for (j = left + 1; j <= right; j++) {
		if (pivot > v[j]) {
			aux = v[j];
			v[j] = v[i];
			v[i] = aux;
			i++;
		}
	}

	/* move the pivot between elements < pivot and elements > pivot */
	v[left] = v[i - 1];
	v[i - 1] = pivot;

	return i - 1;
}

/**
 * Reads array from file.
 * @param      v     The address of the array to store read elements.
 * @param      n     The address of the number of elements array has.
 * @param      file  The file where to read array from.
 * @param      err   An error message, if any occcurred during reading.
 * @return           1 if everything went fine, 0 otherwise. 
 */
int readVectorFromFile(int** v, int* n, char* file, char* err) {
	FILE *inputFile = fopen(file, "rt");
	int countReadedElements = 0, i = 0;

	if (inputFile == NULL) {
		strcpy(err, "Err. Could not open file.\n");
		return 0;
	}
	if (fscanf(inputFile, "%d", n) != 1) {
		fclose(inputFile);
		strcpy(err, "Err. Could not read number of elements.\n");
		return 0;
	}
	*v = (int*) malloc(sizeof(int) * (*n));
	for (i = 0; i < *n; i++) {
		if (fscanf(inputFile, "%d", &(*v)[i]) != 1) {
			break;
		}
		countReadedElements++;
	}
	fclose(inputFile);
	if (countReadedElements != *n) {
		strcpy(err, "Err. Number of declared elements does not match with the one found in file.\n");
		return 0;
	}
	return 1;
}

/**
 * Prints an array 's elements.
 * @param    v        The vector to print.
 * @param    n        The number of elements vector has.    
 */
void printVector(const int* v, const int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
}
