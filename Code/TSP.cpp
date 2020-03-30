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
    int id = -1;
    int dp = 1;
    Village *next = nullptr;
};

struct Villages
{
    Village *cur = nullptr;
}v[1000001];

void add(int i, int j)
{
    in[j]++;
    if (v[i].cur==nullptr)
    {
        v[i].cur = new Village{i};
    }
    if (v[j].cur==nullptr)
    {
        v[j].cur = new Village{j};
    }
    Village *cur = v[i].cur;
    while(cur->next!=nullptr)
    {
        cur = cur->next;
    }
    cur->next = new Village{j};
}

int max(int i, int j)
{
    return i>j?i:j;
}

void topological_sort(int n)
{
    int len = 0;
    int res = 0;
    Village *cur;
    for (int i=0; i<n; i++)
    {
        if (!in[i])
        {
            idx[len++] = i;
        }
    }
    for (int i=0; i<len; i++)
    {
        cur = v[idx[i]].cur->next;
        while(cur!=nullptr)
        {
            v[cur->id].cur->dp = max(v[idx[i]].cur->dp+1, v[cur->id].cur->dp);
            in[cur->id]--;
            if(!in[cur->id])
            {
                idx[len++] = cur->id;
            }
            res = max(res, v[cur->id].cur->dp);
            cur = cur->next;
        }
    }
    std::cout << res << std::endl;
}

void print(int n)
{
    for (int i=0; i<1; i++)
    {
        std::cout << v[i].cur->id << " (in degree: " << in[i] << ")-> ";
        Village *cur = v[i].cur->next;
        while (cur!=nullptr)
        {
            std::cout << cur->id << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
}
/*
class TSP
{
    Village **v;
    int size;
    int *in;
    int *idx;
public:
    TSP(int _size)
    {
        size = _size;
        v = new Village*[size];
        for (int i=0; i<size; i++)
        {
            v[i] = new Village{i};
        }
        in = new int[size]{};
        idx = new int[size]{};
    }
    ~TSP()
    {
        for (int i=0; i<size; i++)
        {
            remove_village(v[i]);
        }
        delete []v;
        delete []in;
        delete []idx;
    }
    void remove_village(Village *cur)
    {
        if (cur!=nullptr)
        {
            remove_village(cur->next);
            delete cur;
        }
    }
    void add(int i, int j)
    {
        in[j]++;
        //v[i]->id = i;
        Village *cur = v[i];
        while(cur->next!=nullptr)
        {
            cur = cur->next;
        }
        cur->next = new Village{j};
    }
    void print()
    {
        for (int i=0; i<size; i++)
        {
            std::cout << v[i]->id << " (in degree: " << in[i] << ")-> ";
            Village *cur = v[i]->next;
            while (cur!=nullptr)
            {
                std::cout << cur->id << " ";
                cur = cur->next;
            }
            std::cout << std::endl;
        }
    }
    int max(int i, int j)
    {
        return i>j?i:j;
    }
    void topological_sort()
    {
        int len = 0;
        Village *cur;
        int res = 0;
        for (int i=0; i<size; i++)
        {
            if (!in[i])
            {
                idx[len++] = i;
            }
        }
        for (int i=0; i<len; i++)
        {
            cur = v[idx[i]]->next;
            while (cur!=nullptr)
            {
                v[cur->id]->dp = max(v[idx[i]]->dp+1, cur->dp);
                in[cur->id]--;
                if (!in[cur->id])
                {
                    idx[len++] = cur->id;
                }
                res = max(res, v[cur->id]->dp);
                cur = cur->next;
            }
        }
        std::cout << res << std::endl;
    }
};
*/
int main(int argc, const char * argv[]) {
    // insert code here...
    // Topological sorting
    int n, m, i, j;
    std::cin >> n >> m;
    //TSP tsp(n);
    while(m--)
    {
        std::cin >> i >> j;
        add(i-1, j-1);
    }
    topological_sort(n);
    return 0;
}
