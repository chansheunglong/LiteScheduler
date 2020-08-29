#include "src/LiteScheduler.h"

void someAction();
void someAction2();
void someAction3();
void someAction4();
void someAction5();
void someAction6();
void someAction7();
void someAction8();
void someAction9();
void someAction10();

LiteSchedulerTask TASK_test1(&someAction, TIME_ALWAYS);
//LiteSchedulerTask TASK_test2(&someAction2, TIME_ALWAYS);
//LiteSchedulerTask TASK_test3(&someAction3, TIME_ALWAYS);
//LiteSchedulerTask TASK_test4(&someAction4, TIME_ALWAYS);
//LiteSchedulerTask TASK_test5(&someAction5, TIME_ALWAYS);
//LiteSchedulerTask TASK_test6(&someAction6, TIME_ALWAYS);
//LiteSchedulerTask TASK_test7(&someAction7, TIME_ALWAYS);
//LiteSchedulerTask TASK_test8(&someAction8, TIME_ALWAYS);
//LiteSchedulerTask TASK_test9(&someAction9, TIME_ALWAYS);
//LiteSchedulerTask TASK_test10(&someAction10, TIME_ALWAYS);

LiteScheduler runner;

void setup() {
  Serial.begin(115200);
  runner.addTask(&TASK_test1);
  //runner.addTask(&TASK_test2);
  //  runner.addTask(&TASK_test3);
  //  runner.addTask(&TASK_test4);
  //  runner.addTask(&TASK_test5);
  //  runner.addTask(&TASK_test6);
  //  runner.addTask(&TASK_test7);
  //  runner.addTask(&TASK_test8);
  //  runner.addTask(&TASK_test9);
  //  runner.addTask(&TASK_test10);
  TASK_test1.enable();
  //TASK_test2.enable();
  //  TASK_test3.enable();
  //  TASK_test4.enable();
  //  TASK_test5.enable();
  //  TASK_test6.enable();
  //  TASK_test7.enable();
  //  TASK_test8.enable();
  //  TASK_test9.enable();
  //  TASK_test10.enable();
}

void loop() {
  //uint32_t startTime = micros();
  runner.execute();
  //uint32_t endTime = micros();
  //Serial.println(endTime - startTime);
  delay(500);
}

void someAction() {
  //  Serial.print("TASK_test1...");
  //  delay(500);
  //  Serial.println("Done");
  //  Serial.flush();
}

void someAction2() {
  //  Serial.print("TASK_test2...");
  //  delay(500);
  //  Serial.println("Done");
  //  Serial.flush();
}

void someAction3() {
  //  Serial.print("TASK_test3...");
  //  delay(500);
  //  Serial.println("Done");
  //  Serial.flush();
}

void someAction4() {
  //  while (Serial.available()) {
  //    Serial.write(Serial.read());
  //    Serial.flush();
  //  }
}

void someAction5() {
}

void someAction6() {
}

void someAction7() {
}

void someAction8() {
}

void someAction9() {
}

void someAction10() {
}
