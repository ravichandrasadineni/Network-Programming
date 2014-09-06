#include<stdio.h>
#include<stdlib.h>
#include"stringutility.h"
#define TRUE 1
#define FALSE 0
typedef int bool;

bool is_legal_int (char* integerString) {
    while (*integerString)
    {
        if (isdigit (*integerString) ) {
            integerString++;
        }
        else {
            return FALSE;
        }
    }
    return TRUE;
            
}
