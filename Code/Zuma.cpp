//
//  main.cpp
//  Zuma
//
//  Created by 潘超 on 2020/2/19.
//  Copyright © 2020 潘超. All rights reserved.
//

#include <iostream>
#include <cstring>

void insert(char zuma[], int pos, char cha)
{
    int size = int(strlen(zuma));
    for (int i=size; i>=pos; i--)
    {
        zuma[i+1] = zuma[i];
    }
    zuma[pos] = cha;
}

void play(char zuma[], int pos)
{
    int size = int(strlen(zuma));
    int i, j;
    i = j = pos;
    while (i>=0 && zuma[i]==zuma[pos])
    {
        i--;
    }
    while (j<size && zuma[j]==zuma[pos])
    {
        j++;
    }
    if (j-i>3)
    {
        pos = i++;
        for (; i<size; i++, j++)
        {
            zuma[i] = zuma[j];
        }
        play(zuma, pos);
    }
}

void sol()
{
    char zuma[20010];
    std::cin.get(zuma, 10001);
    int n, pos;
    char cha;
    std::cin >> n;
    while(n--)
    {
        std::cin >> pos >> cha;
        insert(zuma, pos, cha);
        play(zuma, pos);
        if (zuma[0]=='\0')
        {
            std::cout << "-" << std::endl;
        }
        else
        {
            std::cout << zuma << std::endl;
        }
    }
}

void debug()
{
    char zuma[20] = "aaaa";
    //play(zuma, 1);
    std::cout << strlen(zuma) << std::endl;
}

char *zuma(char *ss, int pos, char tmp[])
{
    int len = int(strlen(ss));
    
    int front, back;
    front = back = pos;
    char c = ss[pos];
    int count = 1;
 
    while (--front >= 0 && ss[front] == c) count++;
    while (++back < len && ss[back] == c) count++;
        
    if (count >= 3)
    {
                   // 更新字符串ss
        strcpy(tmp, ss + back);
        strcpy(ss + front + 1, tmp);
        return zuma(ss, front, tmp);
    }
    else return ss;
}

void sol2()
{
    #define N 20010
    char str[N];
    char tmp[N];
    std::cin.get(str, 10001);
    int n;
    std::cin >> n;
    while (n--)
    {
        int pos;
        char c;
        std::cin >> pos >> c;
        strcpy(tmp, str + pos);
        str[pos] = c;
        strcpy(str + pos + 1, tmp);
        char *p = zuma(str, pos, tmp);
        if (strlen(p) == 0) printf("-\n");
        else printf("%s\n", p);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    sol2();
    return 0;
}
