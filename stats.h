#define MAX 10.2
struct Stats{
  float average;
  float min;
  float max;
};

void
emailAlerter(void);
void
ledAlerter(void);
struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)(void);
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
