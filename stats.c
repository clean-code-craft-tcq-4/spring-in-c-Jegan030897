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
        s.average = nan("");
        s.max = nan("");
        s.min = nan("");
    }
    return s;
    
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold)
    {
        (*alerters[0])();
        (*alerters[1])();
    }
}

void emailAlerter(void)
{
   emailAlertCallCount = 1;
}

void ledAlerter(void)
{
   ledAlertCallCount = 1;
}

