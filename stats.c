#include <stdio.h>
#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    s.min=s.max=numberset[0];
    float maxThreshold = 0;
    
    alerter_funcptr alerters[] = {emailAlerter,ledAlerter};
    
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
        return s;
    }
    check_and_alert(maxThreshold, alerters, s);
    
    return s;
    
}

void
emailAlerter(void)
{
    emailAlertCallCount = 1;
}

void
ledAlerter(void)
{
    ledAlertCallCount = 1;
}

void
check_and_alert(float maxThreshold,alerter_funcptr alerters[],struct Stats computedStats)
{
	(*alerters[0])();
    (*alerters[1])();
    if(emailAlertCallCount == 1)
    {
        printf("Function emailAlerter() was executed\n");
    }
    
    if(ledAlertCallCount == 1)
    {
        printf("Function ledAlertCallCount() was executed\n");
    }
	
	if(maxThreshold != 0)
	{
		printf("The array element has crossed threshold value = %f",maxThreshold);
	}
    
    printf("Statistics min = %f, max = %f, average = %f",computedStats.min,computedStats.max,computedStats.average);
}
