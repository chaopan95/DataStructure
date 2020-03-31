//
//  main.cpp
//  Broadcast
//
//  Created by 潘超 on 2020/3/31.
//  Copyright © 2020 潘超. All rights reserved.
//

#include <iostream>

class Towns
{
    bool **mat;
    int n;
    bool res;
public:
    Towns(int size)
    {
        n = size;
        mat = new bool*[n]{};
        for (int i=0; i<n; i++)
        {
            mat[i] = new bool[n]{};
        }
        res = true;
    }
    ~Towns()
    {
        for (int i=0; i<n; i++)
        {
            delete []mat[i];
        }
        delete []mat;
    }
    void connect(int i, int j)
    {
        mat[i][j] = mat[j][i] = true;
        for (int k=0; k<n; k++)
        {
            if (k!=i && k!=j && mat[i][k] && mat[j][k])
            {
                res = false;
                break;
            }
        }
    }
    bool get_res()
    {
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, i, j;
    std::cin >> n >> m;
    Towns t(n);
    while(m--)
    {
        std::cin >> i >> j;
        t.connect(i-1, j-1);
    }
    //t.connect(1-1, 2-1);
    //t.connect(1-1, 3-1);
    //t.connect(2-1, 4-1);
    if (t.get_res())
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }
    return 0;
}
