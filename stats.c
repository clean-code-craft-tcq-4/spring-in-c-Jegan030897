#include "stats.h"
#include "math.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    int i;
    
    if((numberset != 0) && (setlength != 0))
    {
        s.min = numberset[0];
        for(i=0; i<setlength; i++)
        {
            if(s.min > numberset[i])
                s.min = numberset[i];
            if(s.max < numberset[i])
                s.max = numberset[i];
            s.average += numberset[i];
        }
        s.average = (s.average/setlength);
    }
    
    if((numberset == 0) && (setlength == 0))
    {
        s.average = NAN;
        s.max = NAN;
        s.min = NAN;
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

