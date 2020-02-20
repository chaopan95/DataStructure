//
//  main.cpp
//  Range
//
//  Created by 潘超 on 2020/2/17.
//  Copyright © 2020 潘超. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *pnt, int a, int b)
{
    int temp = pnt[a];
    pnt[a] = pnt[b];
    pnt[b] = temp;
}

void quickSort(int *pnt, int start, int end)
{
    int i, j;
    i = start;
    j = end;
    if (start<end)
    {
        while(i<j)
        {
            while(pnt[i]<=pnt[j] && i<j)
            {
                j--;
            }
            swap(pnt, i, j);
            while(pnt[i]<=pnt[j] && i<j)
            {
                i++;
            }
            swap(pnt, i, j);
        }
        quickSort(pnt, start, i-1);
        quickSort(pnt, i+1, end);
    }
}

void displayPoints(int *pnt, int size)
{
    for (int i=0; i<size; i++)
    {
        cout << pnt[i] << '\t';
    }
    cout << endl;
}

int binarySearch(int *pnt, int target, int lo, int hi, char s)
{
    if (lo==hi)
    {
        if (target < pnt[lo])
        {
            if (s == 'l')
            {
                return lo;
            }
            else
            {
                return lo-1;
            }
        }
        else if (target > pnt[lo])
        {
            if (s == 'l')
            {
                return lo+1;
            }
            else
            {
                return lo;
            }
        }
        else
        {
            return lo;
        }
    }
    int mi = (lo+hi)/2;
    if (target<=pnt[mi])
    {
        return binarySearch(pnt, target, lo, mi, s);
    }
    else
    {
        return binarySearch(pnt, target, mi+1, hi, s);
    }
}

void test()
{
    int pnt[] = {1, 3, 7, 9, 11};
    cout << binarySearch(pnt, 4, 0, 4, 'l') << endl;
    cout << binarySearch(pnt, 6, 0, 4, 'r') << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, a, b, count;
    cin >> n >> m;
    int *pnt = new int[n];
    int *result = new int[m]{};
    for (int i=0; i<n; i++)
    {
        cin >> pnt[i];
    }
    quickSort(pnt, 0, n-1);
    count = 0;
    while(count<m)
    {
        cin >> a >> b;
        result[count] = binarySearch(pnt, b, 0, n-1, 'r') - binarySearch(pnt, a, 0, n-1, 'l') + 1;
        cout << result[count] << endl;
        count++;
    }
    /*
    for(int i=0; i<m; i++)
    {
        cout << result[i] << endl;
    }
    */
    delete []result;
    delete []pnt;
    return 0;
}
