#include "stdafx.h"
#include "TaskQueue.hpp"

// Christopher D. Canfield
// March 2014
// TaskQueue.hpp


using namespace cdc;
using namespace std;


TaskQueue::TaskQueue()
{
	// Match the size of the vector's backing array to the thread pool's capacity.
	runningTasks.reserve(pool.capacity());
}


TaskQueue::~TaskQueue()
{
}


void TaskQueue::update()
{
	while (!taskQueue.empty() && pool.available() > 0)
	{
		runTask(taskQueue.front());
		taskQueue.pop();
	}
}


void TaskQueue::add(Task::SharedPtr task)
{
	// Start the task immediately if a thread is available to do so. If not, enqueue the task.
	if (pool.available() > 0)
	{
		runTask(task);
	}
	else
	{
		taskQueue.push(task);
	}
}

void TaskQueue::runTask(Task::SharedPtr task)
{
	{
		// Acquire the mutex.
		lock_guard<mutex> lock(runningTasksMutex);

		// Add the task to the running tasks list.
		runningTasks.push_back(task);
			
		// Sort the running tasks list.
		sort(runningTasks.begin(), runningTasks.end(), [](const Task::SharedPtr& task1, const Task::SharedPtr& task2) {
			return (task1->getTaskId() < task2->getTaskId());
		});
	}

	pool.start(*task);
}

void TaskQueue::removeCompleted(const Poco::UUID& taskId)
{
	// Acquire the mutex.
	lock_guard<mutex> lock(runningTasksMutex);

	// Remove the completed task.
	runningTasks.erase(remove_if(runningTasks.begin(), runningTasks.end(), [&taskId](const Task::SharedPtr& task) {
		return task->getTaskId() == taskId;
	}));

	// Sort the runningTasks vector if it is not empty.
	if (!runningTasks.empty())
	{
		sort(runningTasks.begin(), runningTasks.end(), [](const Task::SharedPtr& task1, const Task::SharedPtr& task2) {
			return (task1->getTaskId() < task2->getTaskId());
		});
	}
}