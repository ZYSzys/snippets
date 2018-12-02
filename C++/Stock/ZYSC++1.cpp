//
//  ZYSC++1.cpp
//  First
//
//  Created by 章贝贝 on 3/15/17.
//  Copyright © 2017 章贝贝. All rights reserved.
//

#include "ZYSC++1.hpp"
void PrintHello(int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("Hello world!\n") ;
    }
}
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Quick_Sort(int *s, int l, int r)
{
    if(l < r)
    {
        int i = l, j = r, x = s[l];
        while(i < j)
        {
            while(i < j && s[j] >= x)
            {
                j--;
            }
            if(i < j)
            {
                s[i++] = s[j];
            }
            while(i < j && s[i] < x)
            {
                i++;
            }
            if(i < j)
            {
                s[j--] = s[i];
            }
        }
        s[i] = x;
        Quick_Sort(s, l, i-1);
        Quick_Sort(s, i+1, r);
    }
}
void Merge(int a[], int low, int mid, int high)
{
    int left_low = low;
    int left_high = mid;
    int right_low = mid+1;
    int right_high = high;
    int *temp = (int *)malloc(sizeof(int) * (high - low +1));
    int i, k;
    for(k = 0; left_low <= left_high && right_low <= right_high; )
    {
        if(a[left_low] < a[right_low])
        {
            temp[k++] = a[left_low++];
        }
        else
        {
            temp[k++] = a[right_low++];
        }
    }
    while(left_low <= left_high)
    {
        temp[k++] = a[left_low++];
    }
    while(right_low <= right_high)
    {
        temp[k++] = a[right_low++];
    }
    for(i = 0; i < high - low + 1; i++)
    {
        a[low+i] = temp[i];
    }
    free(temp);
}
void Merge_Sort(int a[], int start, int end)
{
    int mid;
    if(start < end)
    {
        mid = (start + end) / 2;
        Merge_Sort(a, start, mid);
        Merge_Sort(a, mid+1, end);
        Merge(a, start, mid, end);
    }
}




















//