#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    
    int index = 0;
    int length;
    float large, small;
    large = numberset[0];
    small = numberset[0];
    length = setlength;
    
    if(length != 0)
    {
        for(index = 0;index < setlength; index++)
        {
            sum = sum + numberset[i];
            if(numberset[i] > large)
            {
                large = numberset[i];
            }
            
            if(numberset[i] < small)
            {
                small = numberset[i];
            }
        }
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

