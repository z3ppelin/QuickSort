
/**
 * Sorting a vector via QuickSort algorithm in O(n * log n) on average.
 *
 * @author      Bogdan Constantinescu <bog_con@yahoo.com>
 * @since       2013.07.08
 * @version     1.0
 * @link        GitHub  https://github.com/z3ppelin/QuickSort
 * @licence     The MIT License (http://opensource.org/licenses/MIT); see LICENCE.txt
 */

import java.io.FileInputStream;
import java.util.*;

public class QuickSort {

    /**
     * Main function. Reads vector, sorts it, and prints it.
     * @param   args    Command line arguments.
     */
    public static void main(String[] args) {
        System.out.println("------ Begin QuickSort ------");
        int[] vectorToSort = new int[0];
        long start, end;

        /* read vector */
        try {
            if (args.length == 0) {
                throw new Exception("The input file must be given as an argument.");
            }
            vectorToSort = readVectorFromFile(args[0]);
        } catch (Exception ex) {
            System.out.println("ERR. " + ex.getMessage());
            System.out.println("------- End QuickSort -------");
            System.exit(-1);
        }
        
        /* print read vector */
        //System.out.print("The read vector is: ");
        //printVector(vectorToSort);
        //System.out.println();
        
        /* sort vector */
        start = System.currentTimeMillis();
        quickSort(vectorToSort, 0, vectorToSort.length - 1);
        end = System.currentTimeMillis();

        /* print sorted vector */
        System.out.print("The sorted vector is: ");
        printVector(vectorToSort);
        System.out.println();

        System.out.println("Elapsed: " + ((double) (end - start) / 100) + " seconds while sorting.");
        System.out.println("------- End QuickSort -------");
    }

    /**
     * Recursive function (based on Divide and Conquer algorithm) that sorts a
     * vector (via Quick Sort algorithm).
     *
     * @param   v         The vector to sort.
     * @param   left      The left margin of the vector.
     * @param   right     The right margin of the vector.
     */
    public static void quickSort(int[] v, int left, int right) {
        if (left < right) {
            int i = partition(v, left, right);
            quickSort(v, left, i - 1);
            quickSort(v, i + 1, right);
        }
    }

    /**
     * Partition the vector, choose a pivot and arrange all elements lower than
     * it to the left, elements bigger than it to the right.
     *
     * @param   v       The vector to sort.
     * @param   left    The left margin of the vector.
     * @param   right   The right margin of the vector.
     * @return          The pivot position.
     */
    public static int partition(int[] v, int left, int right) {
        int i = left + 1, j, aux, pivot, pivotPos;
        pivotPos = left + (int) (Math.random() * ((right - left) + 1));
        pivot = v[pivotPos];

        /* make pivot the first element */
        v[pivotPos] = v[left];
        v[left] = pivot;

        for (j = left + 1; j <= right; j++) {
            if (pivot > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
            }
        }

        /* move pivot between elements < pivot and elements > pivot */
        v[left] = v[i - 1];
        v[i - 1] = pivot;

        return i - 1; // pivot pos
    }

    /**
     * Prints an array 's elements.
     * @param   v       The vector to print.
     */
    public static void printVector(int[] v) {
        for (int i = 0; i < v.length; i++) {
            System.out.print(v[i] + " ");
        }
    }
    
    /**
     * Reads array from file.
     * 
     * @param   file        The file where to read array from.
     * @return              The read vector.
     * @throws  Exception 
     */
    public static int[] readVectorFromFile(String file) throws Exception {
        Scanner sc;
        FileInputStream fis = null;
        int n;
        int[] v;
        try {
            fis = new FileInputStream(file);
            sc = new Scanner(fis);
            if (!sc.hasNextInt()) {
                throw new Exception("Could not read the number of elements.");
            }
            n = sc.nextInt();
            v = new int[n];
            for (int i = 0; i < n; i++) {
                if (sc.hasNextInt()) {
                    v[i] = sc.nextInt();
                } else {
                    throw new Exception("Number of declared elements does not match with the one found in file.");
                }
            }
            fis.close();
        } catch (Exception ex) {
            if (fis != null) {
                try {
                    fis.close();
                } catch (Exception e) {
                }
            }
            throw ex;
        }
        return v;
    }
}
