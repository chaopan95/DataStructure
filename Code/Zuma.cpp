//
//  main.cpp
//  Zuma
//
//  Created by 潘超 on 2020/2/19.
//  Copyright © 2020 潘超. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void insert(char zuma[], int pos, char cha)
{
    int i = pos+1;
    char last = zuma[pos];
    char temp = zuma[pos];
    while(zuma[i]!='\0')
    {
        temp = zuma[i];
        zuma[i] = last;
        last = temp;
        i++;
    }
    zuma[i] = last;
    zuma[i+1] = '\0';
    zuma[pos] = cha;
}

void play(char zuma[])
{
    int i = 0;
    while(zuma[i]!='\0')
    {
        if (zuma[i]==zuma[i+1] && zuma[i+1]==zuma[i+2])
        {
            int j = i+3;
            while(zuma[j]!='\0')
            {
                zuma[j-3] = zuma[j];
                j++;
            }
            zuma[j-3] = zuma[j];
            i = 0;
            continue;
        }
        i++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char zuma[20001];
    cin.get(zuma, 10000);
    int n, pos;
    char cha;
    cin >> n;
    while(n--)
    {
        cin >> pos >> cha;
        insert(zuma, pos, cha);
        play(zuma);
        if (zuma[0]=='\0')
        {
            cout << '-' << endl;
        }
        else
        {
            cout << zuma << endl;
        }
    }
    return 0;
}
