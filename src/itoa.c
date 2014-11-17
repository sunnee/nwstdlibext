//
//  NWStdExtensions.cpp
//  NWAppDataTransfer
//
//  Created by Alexandr Kavalchuk on 11.08.14.
//  Copyright (c) 2014 nwaves. All rights reserved.
//

#include "nwunstd.h"

#if __NW_ITOA

char* itoa(int value, char* result, int base)
{
    // check that the base if valid
    if ((base < 2) || (base > 36))
    {
        *result = 0;
        return result;
    }
	
    char* s1 = result;
    char* s2 = result;
    int q, r;
    char char_values[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    if (value < 0)
    {
        value = value * (-1);
        *s1   = '-';
        s1++;
        s2++;
    }
    
    do
    {
        q   = (int) value / base;
        r   = value % base;
        *s1 = char_values[r];
        s1++;
        value = q;
    }
    while(value > 0);
	
    *s1 = '\0';
    s1--;
    
    //Reverse
    char  tmp;
    while(s2 < s1)
    {
        tmp = *s1;
        *s1 = *s2;
        *s2 = tmp;
        
        s1--;
        s2++;
    }
    
    return result;
};

#endif