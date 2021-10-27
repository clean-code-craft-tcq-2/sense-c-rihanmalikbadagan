#include "stats.h"
#define MAX 10.2

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
typedef int (*alerter_funcptr)(void);
void check_and_alert(float maxThreshold,alerter_funcptr alerters[],struct Stats computedStats);
int emailAlerter(void);
int ledAlerter(void);

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    s.min=s.max=numberset[0];
    float maxThreshold = 0;
    
    alerter_funcptr alerters[] = {emailAlerter,ledAlerter};
    alerters[0]();
    alerters[1]();
    
    if (setlength > 0)
    {
        for(int i = 0; i < setlength ; i++)
        {
            s.average =+ numberset[i];
        
            if(s.min > numberset[i])
            {
                s.min = numberset[i];   
            }
        
            if(s.max < numberset[i])
            {
                s.max = numberset[i];   
            }
            
            if(s.max >= MAX)
            {
                maxThreshold = s.max;
            }
        }
        s.average = s.average/setlength;
    }
    else
    {
        printf("[ERROR] Invalid argument passed, returning zero\n");
        return compute_statistics;
    }
    check_and_alert(maxThreshold, alerters, computedStats);
    
    return compute_statistics;
    
}

int emailAlerter(void)
{
    emailAlertCallCount = 1;
    return emailAlertCallCount;
}

int ledAlerter(void)
{
    ledAlertCallCount = 1;
    return ledAlertCallCount;
}

void
check_and_alert(float maxThreshold,alerter_funcptr alerters[],struct Stats computedStats)
{
    if(emailAlertCallCount == 1)
    {
        printf("Function emailAlerter() was executed\n");
    }
    
    if(ledAlertCallCount == 1)
    {
        printf("Function ledAlertCallCount() was executed\n");
    }
    
    printf("Statistics min = %d, max = %d, average = %d",computedStats.min,computedStats.max,computedStats.average);
}
