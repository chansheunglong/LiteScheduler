#include <Arduino.h>

/*
  Task scheduler for Arduino that provide all basic feature
  and consume minimal system resource

  Version 1: 2020-08-29

  LiteScheduler is designed to only implement minimal feature for basic scheduling

  Scheduling overhead is around 8 microseconds per scheduling pass
  (ATMEGA328PB @ 16MHz, single scheduled task)

  Feature
  1)Periodic task execution
  2)Enable, disable task
  3)Check if the task is overrun

  More at:
  https://github.com/chansheunglong/LiteScheduler
*/

//Timming settings
#define ABSOLUTE_INTERVAL_TIME
//#define RELATIVE_INTERVAL_TIME

//Variable
#define LiteScheduler_Max_Task 10 //Set the maximum scheduled task

enum LiteSchedulerInterval {
  TIME_ALWAYS = 0,
  TIME_1S = 6000,
  TIME_1M = 60000,
  TIME_1H = 3600000
};

#define LiteSchedulerDebug
/*
  ##Example##

  Create task:
  LiteSchedulerTask <Task Name>(<Task Function>, <Interval>);

  Enable task:
  <Task Name>.enable();

  Set scheduler size:
  LiteScheduler <Scheduler Name>;

  Add task to scheduler:
  <Scheduler Name>.addTask(&<Task Name>);

  In loop(), add the following call to schedule all task
   <Scheduler Name>.execute();
*/

class LiteSchedulerTask {
  private:
    void(*callback) (void);
  public:
    bool isEnable = false;
    uint32_t interval = 0;
    uint32_t nextRunTime = 0;
    LiteSchedulerTask(void(*run)(void), uint32_t _interval) : callback(run) {
      interval = _interval;
    }
    void run() {
      callback();
    };
    void enable();
    void enableIfNot();
    void disable();
    void delay(uint32_t _delay);
    void changeInterval(uint32_t _interval);
    bool isOverrun();
};

class LiteScheduler {
  private:
    uint8_t taskListCounter = 0;
    LiteSchedulerTask *taskList[LiteScheduler_Max_Task];
  public:
    LiteScheduler() {
    };
    void execute();
    void addTask(LiteSchedulerTask *_task);
    void reset();
};
