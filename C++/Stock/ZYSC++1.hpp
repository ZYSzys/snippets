//
//  ZYSC++1.hpp
//  First
//
//  Created by 章贝贝 on 3/15/17.
//  Copyright © 2017 章贝贝. All rights reserved.
//

#ifndef ZYSC__1_hpp
#define ZYSC__1_hpp

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
class Student
{
private:
    char name[10];
    char sex[5];
    int age;
    int birth[10];
public:
    char *Getname(const char *a)
    {
        return strcpy(name, a);
        //return name;
    }
};
void PrintHello(int n);
void Swap(int *x, int *y);
void Quick_Sort(int *s, int l, int r);
void Merge(int a[], int low, int mid, int high);
void Merge_Sort(int a[], int start, int end);
#endif /* ZYSC__1_hpp */
