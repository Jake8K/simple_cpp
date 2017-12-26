//
//  iterativeMS.cpp
//  LabH
//
//  Created by http://www.algorithmist.com/index.php/Merge_sort.c
//

#include "iterativeMS.hpp"

/* Merge sort
 // The merge sort divides the array into two sub-arrays, sorts them and then
 // calls merge to merge the two arrays back together.
 */
void Merge( int a[], int b[], int c[], int m, int n )
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if( a[i] < b[j] )
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    
    while ( i < m )
    {
        c[k++] = a[i++];
    }
    
    while ( j < n )
    {
        c[k++] = b[j++];
    }
}

void merge_sort( int key[], int n )
{
    int j, k, m, *w;
    for( m = 1; m < n; m *= 2 );
    //if (m != n)
    //{
    //    printf ("ERROR: Size of the array is not power of 2.");
    //}
    //else
    {
        w = new int[n];
        for( k = 1; k < n; k *= 2 )
        {
            for( j = 0; j < (n - k); j += 2 * k )
            {
                Merge(key + j, key + j + k, w + j, k, k);
            }
            
            for ( j = 0; j < n; j++) key[j] = w[j];
        }
        delete w;
    }
}