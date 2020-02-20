//
//  main.cpp
//  LightHouse
//
//  Created by 潘超 on 2020/2/19.
//  Copyright © 2020 潘超. All rights reserved.
//


#include <iostream>

void display(long long *pnt, long long hi)
{
    for (int i=0; i<=hi; i++)
    {
        std::cout << pnt[i] << '\t';
    }
    std::cout << std::endl;
}

void merge(long long *x, long long *y, long long lo, long long mi, long long hi)
{
    long long *temp_x = new long long[hi-lo+1];
    long long *temp_y = new long long[hi-lo+1];
    long long pos = 0;
    long long i = lo, j = mi+1;
    while(i<=mi && j<=hi)
    {
        if (x[i]<=x[j])
        {
            temp_x[pos] = x[i];
            temp_y[pos] = y[i];
            i++;
        }
        else
        {
            temp_x[pos] = x[j];
            temp_y[pos] = y[j];
            j++;
        }
        pos++;
    }
    while (i<=mi)
    {
        temp_x[pos] = x[i];
        temp_y[pos] = y[i];
        i++;
        pos++;
    }
    while(j<=hi)
    {
        temp_x[pos] = x[j];
        temp_y[pos] = y[j];
        j++;
        pos++;
    }
    for (i=0; i<hi-lo+1; i++)
    {
        x[i+lo] = temp_x[i];
        y[i+lo] = temp_y[i];
    }
    delete []temp_x;
    delete []temp_y;
}

void mergeSort(long long *x, long long *y, long long lo, long long hi)
{
    if (lo<hi)
    {
        long long mi = (lo+hi)/2;
        mergeSort(x, y, lo, mi);
        mergeSort(x, y, mi+1, hi);
        merge(x, y, lo, mi, hi);
    }
}

long long invertBetween(long long *pnt, long long lo, long long mi, long long hi)
{
    long long *temp = new long long[hi-lo+1];
    long long num = 0;
    long long right = 0;
    long long i = lo, j = mi+1;
    long long pos = 0;
    while (i<=mi && j<=hi)
    {
        if (pnt[i] <= pnt[j])
        {
            temp[pos] = pnt[i];
            i++;
            num += right;
        }
        else
        {
            temp[pos] = pnt[j];
            j++;
            right++;
        }
        pos++;
    }
    num += right*(mi-i+1);
    while (i<=mi)
    {
        temp[pos] = pnt[i];
        i++;
        pos++;
    }
    while (j<=hi)
    {
        temp[pos] = pnt[j];
        j++;
        pos++;
    }
    for (pos=0; pos<hi-lo+1; pos++)
    {
        pnt[pos+lo] = temp[pos];
    }
    delete []temp;
    return num;
}

long long invertSortPair(long long *pnt, long long lo, long long hi)
{
    if (lo<hi)
    {
        long long mi = (lo+hi)/2;
        long long n1 = invertSortPair(pnt, lo, mi);
        long long n2 = invertSortPair(pnt, mi+1, hi);
        long long n3 = invertBetween(pnt, lo, mi, hi);
        return n1+n2+n3;
    }
    return 0;
}

void swap(long long *x, long long *y, long long i, long long j)
{
    long long temp = x[i];
    x[i] = x[j];
    x[j] = temp;
    temp = y[i];
    y[i] = y[j];
    y[j] = temp;
}

void quickSort(long long *x, long long *y, long long lo, long long hi)
{
    long long i = lo, j = hi;
    while (i<j)
    {
        while (x[i]<=x[j] && i<j)
        {
            j--;
        }
        swap(x, y, i, j);
        while (x[i]<=x[j] && i<j)
        {
            i++;
        }
        swap(x, y, i, j);
    }
    if (lo<i)
    {
        quickSort(x, y, lo, i-1);
    }
    if (j<hi)
    {
        quickSort(x, y, j+1, hi);
    }
}

void debug()
{
    long long n = 4;
    long long x[] = {1, 2, 3, 4};
    long long y[] = {1, 3, 2, 4};
    //quickSort(x, y, 0, n-1);
    mergeSort(x, y, 0, n-1);
    display(x, n-1);
    display(y, n-1);
    std::cout << invertSortPair(y, 0, n-1) << std::endl;
}

void sol()
{
    long long n;
    std::cin >> n;
    long long *x = new long long[n]{};
    long long *y = new long long[n]{};
    long long i = 0;
    while(i<n)
    {
        std::cin >> x[i] >> y[i];
        i++;
    }
    quickSort(x, y, 0, n-1);
    //mergeSort(x, y, 0, n-1);
    std::cout << (n*(n-1))/2 - invertSortPair(y, 0, n-1) << std::endl;
    //std::cout << invertSortPair(y, 0, n-1) << std::endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    sol();
    return 0;
}

