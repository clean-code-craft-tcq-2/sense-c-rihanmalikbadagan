#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    s.min=s.max=numberset[0];
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
    }
    s.average = s.average/setlength;
    
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
