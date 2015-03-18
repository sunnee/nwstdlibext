//
//  NW STR DIGIT
//
//  Created by Alexandr Kavalchuk on 11.08.14.
//  Copyright (c) 2006-2015 Alexandr Kavalchuk (nWaves).
//  All rights reserved.
//

#include "nwunstd.h"
#include <locale.h>

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

const char* sscandigit(const char* str, long long* i, double* d, bool* is_double)
{
    int        n = 0;
    long long _i = 0;
    double    _d = 0.0f;
    bool      _is_double = false;
    
    if (sscanf(str, "%lld%n", &_i, &n) > 0)
    {
        str += n;
        
        if (*str != 0)
        {
            const char* decimal_point = localeconv()->decimal_point;
            if (strcmp(str, decimal_point) == 0)
            {
                _is_double = true;
            }
        }
        
        if ((_is_double == true) || (*str == '.'))
        {
            str++;
            if (sscanf(str, "%lf%n", &_d, &n) > 0)
            {
                str += n;
                
                double divider = pow(10, n);
                _d = _d/divider;
                _d = _d + (double)(_i);
                _is_double = true;
            }
            else
            {
                str--;
            }
        }
        
        if (_is_double)
        {
            *d = _d;
            *i = (long long)(_d);
        }
        else
        {
            *i = _i;
            *d = (double)(_i);
        }
    }
    
    if (is_double != NULL) *is_double = _is_double;
    
    return str;
}

#endif