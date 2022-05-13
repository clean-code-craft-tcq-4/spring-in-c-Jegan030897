#include "stats.h"
#include "math.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    
    int index = 0;
    float sum = 0.0;
    float large = numberset[0];
    float small = numberset[0];
    
    if(setlength != 0)
    {
        for(index = 0;index < setlength; index++)
        {
            sum = sum + numberset[index];
            if(numberset[index] > large)
            {
                large = numberset[index];
            }
            
            if(numberset[index] < small)
            {
                small = numberset[index];
            }
        }
        s.average = (sum/setlength);
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

