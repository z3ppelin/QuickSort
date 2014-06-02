/** Header file for QuickSort Algorithm.
 * 
 * @author      Bogdan Constantinescu <bog_con@yahoo.com>
 * @since       2013.08.03
 * @version     1.0
 * @link        GitHub    https://github.com/z3ppelin/QuickSort
 * @licence     The MIT License (http://opensource.org/licenses/MIT); see LICENSE.txt
 */

#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

/* function prototypes */
void quickSort(int*, const int, const int);
int partition(int* v, const int, const int);
void err(const char*);
int readVectorFromFile(int**, int*, char*, char*);
void printVector(const int*, const int);

#endif /* _QUICK_SORT_H_ */
