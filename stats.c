#include "stats.h"
#include "math.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    
    int i = 0,length;
    float large = *(numberset+0);
    float small = *(numberset+0);
    length = setlength;
    
    if(setlength != 0)
    {
        while(length)
        {
            s.average += *(numberset + i);
            ++i;
            --length;
        }
        s.average = (s.average/setlength);
        
        i = 0;
        
        large = *(numberset + i);
        small = *(numberset + i);
        while(i < setlength-1)
        {
            if(*(numberset + (i+1)) > large)
            {
                large = *(numberset + (i+1));
            }
            
            if(*(numberset + (i+1)) < small)
            {
                small = *(numberset + (i+1));
            }
            ++i;
        }
        s.max = large;
        s.min = small;
    }
    else
    {
        s.average = 0;
        s.max = 0;
        s.min = 0;
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

