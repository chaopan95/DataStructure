//
//  main.cpp
//  TSP
//
//  Created by 潘超 on 2020/3/28.
//  Copyright © 2020 潘超. All rights reserved.
//

#include <iostream>

int in[1000001] = {};
int idx[1000001] = {};
struct Village
{
    int id;
    Village *next_village;
    Village (int i, Village *next=nullptr):id(i), next_village(next){}
};

struct Villages
{
    int dp;
    Village *next;
    Villages():dp(1), next(nullptr){}
    void connect(int);
}v[1000001];

void Villages::connect(int j)
{
    in[j]++;
    if (next==nullptr)
    {
        next = new Village(j);
    }
    else
    {
        next = new Village(j, next);
    }
}

int max(int i, int j)
{
    return i>j?i:j;
}

void topological_sort(int n)
{
    int len = 0;
    int res = 0;
    Village *next;
    for (int i=0; i<n; i++)
    {
        if (!in[i])
        {
            idx[len++] = i;
        }
    }
    for (int i=0; i<len; i++)
    {
        next = v[idx[i]].next;
        while(next!=nullptr)
        {
            v[next->id].dp = max(v[idx[i]].dp+1, v[next->id].dp);
            in[next->id]--;
            if(!in[next->id])
            {
                idx[len++] = next->id;
            }
            res = max(res, v[next->id].dp);
            next = next->next_village;
        }
    }
    std::cout << res << std::endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    // Topological sorting

    int n, m, i, j;
    std::cin >> n >> m;
    while(m--)
    {
        std::cin >> i >> j;
        v[i-1].connect(j-1);
    }
    topological_sort(n);
    return 0;
}
