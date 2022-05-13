#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    
    int index = 0;
    int length;
    float large, small;
    length = setlength;
    
    if(length != 0)
    {
        while(length)
        {
            s.average += *(numberset + index);
            ++index;
            --length;
        }
        s.average = s.average/setlength;
        
        index = 0;
        
        large = *(numberset + index);
        small = *(numberset + index);
        while(index < setlength-1)
        {
            if(*(numberset + (index+1)) > large)
            {
                large = *(numberset + (index+1));
            }
            if(*(numberset + (index+1)) < small)
            {
                small = *(numberset + (index+1));
            }
            ++index;
        }
        s.max = large;
        s.min = small;
    }
    else
    {
        s.average = 0.0/0.0;
        s.max = 0.0/0.0;
        s.min = 0.0/0.0;
    }
    return s;
    
}

