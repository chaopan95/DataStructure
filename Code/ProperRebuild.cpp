//
//  main.cpp
//  ProperRebuild
//
//  Created by 潘超 on 2020/3/27.
//  Copyright © 2020 潘超. All rights reserved.
//

#include <iostream>

int find_r1(int *pre, int *post, int r2, int r)
{
    while (pre[r]!=post[r2])
    {
        r--;
    }
    return r;
}

int find_l2(int *pre, int *post, int l1, int l)
{
    while (pre[l1]!=post[l])
    {
        l++;
    }
    return l;
}

void ppi(int *pre, int *post, int b1, int e1, int b2, int e2)
{
    if (b1==e1)
    {
        std::cout << pre[b1] << " ";
    }
    if (b1<e1)
    {
        int p1 = b1;
        int p2 = e2;
        int l1 = p1 + 1;
        int r2 = p2 - 1;
        int r1 = find_r1(pre, post, r2, e1);
        int l2 = find_l2(pre, post, l1, b2);
        ppi(pre, post, l1, r1-1, b2, l2);
        std::cout << pre[p1] << " ";
        ppi(pre, post, r1, e1, l2+1, r2);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    std::cin >> n;
    int i = 0;
    int *pre = new int[n]{0};
    while (i<n)
    {
        std::cin >> pre[i];
        i++;
    }
    i = 0;
    int *post = new int[n]{0};
    while (i<n)
    {
        std::cin >> post[i];
        i++;
    }
    ppi(pre, post, 0, n-1, 0, n-1);
    delete []post;
    delete []pre;
    return 0;
}
