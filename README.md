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

Create task:
```ruby
LiteSchedulerTask <Task Name>(<Task Function>, <Interval>);
```


Enable task:
```ruby
<Task Name>.enable();
```

Set scheduler size:
```ruby
LiteScheduler <Scheduler Name>;
```

Add task to scheduler:
```ruby
<Scheduler Name>.addTask(&<Task Name>);
```

In loop(), add the following call to schedule all task
```ruby
<Scheduler Name>.execute();
```
   
