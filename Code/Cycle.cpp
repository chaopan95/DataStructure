//
//  main.cpp
//  Cycle
//
//  Created by 潘超 on 2020/4/19.
//  Copyright © 2020 潘超. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long N =1e5+5;
char s1[N], s2[2*N];

bool same(size_t n, char s1[], int pos, char s2[])
{
    int i = pos;
    int j = 0;
    while(j < n)
    {
        if (s1[i] != s2[j])
        {
            return false;
        }
        i++;
        j++;
        if (i == n)
        {
            i = 0;
        }
    }
    return true;
}

bool check_cycle(char s1[], char s2[])
{
    size_t n1 = strlen(s1);
    size_t n2 = strlen(s2);
    if (n1 != n2)
    {
        return false;
    }
    for (int pos = 0; pos < n1; pos++)
    {
        if (same(n1, s1, pos, s2))
        {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    while (~scanf("%s%s",s1, s2))
    {
        if (check_cycle(s1, s2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
