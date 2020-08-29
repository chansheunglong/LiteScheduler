#include "LiteScheduler.h"

void LiteSchedulerTask::enable() {
  isEnable = true;
  nextRunTime = millis();
}

void LiteSchedulerTask::enableIfNot() {
  if (!isEnable) {
    enable();
  }
}

void LiteSchedulerTask::disable() {
  isEnable = false;
}

void LiteSchedulerTask::delay(uint32_t _delay) {
  nextRunTime = nextRunTime + _delay;
}

void LiteSchedulerTask::changeInterval(uint32_t _interval) {
  interval = _interval;
}

#define LiteSchedulerTask_Overrun_Threshold 10
bool LiteSchedulerTask::isOverrun() {
  return (millis() > (nextRunTime - interval + LiteSchedulerTask_Overrun_Threshold));
}

/*
  =========================================================================
*/

void LiteScheduler::addTask(LiteSchedulerTask *_task) {
  if (taskListCounter >= LiteScheduler_Max_Task) return; //Do not add task
  taskList[taskListCounter] = _task;
  taskListCounter++;
}

void LiteScheduler::execute() {
#ifdef LiteSchedulerDebug
  uint32_t scheduleStartTime = micros();
#endif

  uint32_t timeNow = millis();
  for (uint8_t i = 0; i < taskListCounter; i++) {
    if (taskList[i]->isEnable) {
      if (timeNow >= taskList[i]->nextRunTime) {
#ifdef ABSOLUTE_INTERVAL_TIME
        taskList[i]->nextRunTime = taskList[i]->nextRunTime + taskList[i]->interval;
#endif
#ifdef RELATIVE_INTERVAL_TIME
        taskList[i]->nextRunTime = timeNow + taskList[i]->interval;
#endif
        taskList[i]->run();
      }
    }
  }

#ifdef LiteSchedulerDebug
  uint32_t scheduleDuration = micros() - scheduleStartTime;
  Serial.print("LiteScheduler finish in ");
  Serial.print((scheduleDuration / 1000.0), 3);
  Serial.println(" ms");
  Serial.flush();
#endif
}

void LiteScheduler::reset() {
  uint32_t timeNow = millis();
  for (uint8_t i = 0; i < taskListCounter; i++) {
    if (taskList[i]->isEnable) {
      if (timeNow >= taskList[i]->nextRunTime) {
        taskList[i]->nextRunTime = timeNow;
      }
    }
  }
}
