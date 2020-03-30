//
//  main.cpp
//  Train
//
//  Created by 潘超 on 2020/3/25.
//  Copyright © 2020 潘超. All rights reserved.
//

#include <iostream>
#include <assert.h>

class stack
{
    int m;
    int *s;
    int cur;
public:
    stack(int size)
    {
        m = size;
        s = new int [m]{0};
        cur = -1;
    }
    ~stack()
    {
        delete []s;
    }
    void push(int a)
    {
        assert(cur<m);
        s[++cur] = a;
    }
    int pop()
    {
        assert(cur>-1);
        return s[cur--];
    }
    bool is_empty()
    {
        return (cur==-1);
    }
    bool is_full()
    {
        return (cur==m-1);
    }
    int top()
    {
        return s[cur];
    }
};

class vector
{
    int m;
    int *v;
    int cur;
public:
    vector(int size)
    {
        m = size;
        v = new int[m]{0};
        cur = -1;
    }
    ~vector()
    {
        delete []v;
    }
    void push(int a)
    {
        v[++cur] = a;
    }
    int get_value(int i)
    {
        return v[i];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m;
    std::cin >> n >> m;
    vector res(2*n);
    stack A(n);
    for (int i=n; i>0; i--)
    {
        A.push(i);
    }
    stack S(m);
    int *B = new int[n]{0};
    int temp;
    int i = 0;
    while(i<n)
    {
        std::cin >> B[i];
        i++;
    }
    int count = 0;
    for (i=0; i<n; i++)
    {
        if (A.is_empty())
        {
            if (S.is_empty() || B[i]!=S.top())
            {
                std::cout << "No" << std::endl;
                delete []B;
                return 0;
            }
            S.pop();
            res.push(2);
            count++;
        }
        else
        {
            if (!S.is_empty() && B[i]==S.top())
            {
                S.pop();
                res.push(2);
                count++;
                continue;
            }
            while(B[i]!=A.top())
            {
                if (S.is_full()||A.is_empty())
                {
                    std::cout << "No" << std::endl;
                    delete []B;
                    return 0;
                }
                temp = A.pop();
                S.push(temp);
                res.push(1);
                count++;
            }
            temp = A.pop();
            if (S.is_full())
            {
                std::cout << "No" << std::endl;
                delete []B;
                return 0;
            }
            S.push(temp);
            res.push(1);
            S.pop();
            res.push(2);
            count += 2;
        }
    }
    for (i=0; i<count; i++)
    {
        if (res.get_value(i)==1)
        {
            std::cout << "push" << std::endl;
        }
        else
        {
            std::cout << "pop" << std::endl;
        }
    }
    delete []B;
    return 0;
}
