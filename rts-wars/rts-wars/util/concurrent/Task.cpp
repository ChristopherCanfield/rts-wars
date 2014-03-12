#include "stdafx.h"
#include "Task.hpp"

// Christopher D. Canfield
// March 2014
// Task.hpp

using namespace cdc;


Task::Task(TaskQueue& taskQueue) :
	taskQueue(taskQueue)
{
	id = Poco::UUIDGenerator::defaultGenerator().createRandom();
}

const Poco::UUID& Task::getTaskId() const 
{
	return id;
}

void Task::run()
{
	runTask();
	taskQueue.removeCompleted(id);
}