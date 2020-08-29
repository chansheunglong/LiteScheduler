# LiteScheduler
Task scheduler for Arduino that provide all basic feature and consume minimal system resource

Version 1: 2020-08-29

LiteScheduler is designed to only implement minimal feature for basic scheduling

Scheduling overhead is around 8 microseconds per scheduling pass (ATMEGA328PB @ 16MHz, single scheduled task)

------------

### Feature
1) Periodic task execution
2) Enable, disable task
3) Check if the task is overrun

------------

### Usage

##### Create task:
```
LiteSchedulerTask <Task Name>(<Task Function>, <Interval>);
```
e.g. LiteSchedulerTask TASK_test1(&someAction, TIME_ALWAYS);
----

##### Enable task:
```
<Task Name>.enable();
```
> e.g. TASK_test1.enable();
----


##### Create scheduler:
```
LiteScheduler <Scheduler Name>;
```
> e.g. LiteScheduler runner;
----

##### Add task to scheduler:
```
<Scheduler Name>.addTask(&<Task Name>);
```
> e.g. runner.addTask(&TASK_test1);
----

##### In loop(), add the following call to schedule all task
```
<Scheduler Name>.execute();
```
> e.g. runner.execute();
   
