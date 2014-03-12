#pragma once

#include "Task.hpp"

#include <Poco/ThreadPool.h>
#include <memory>
#include <mutex>
#include <vector>

// Christopher D. Canfield
// March 2014
// TaskQueue.hpp

namespace cdc
{
	///<summary>A queue that runs tasks concurrently.</summary>
	class TaskQueue
	{
	public:
		TaskQueue();
		~TaskQueue();

		///<summary>Processed items in the queue. Should be called once per tick.</summary>
		void update();

		///<summary>Adds the task to the queue. The task may be executed immediately, or it may be
		/// enqueued for later execution. This method is not thread-safe; all calls to it should be 
		/// made from the same thread.</summary>
		///<param name="task">The task to run.</param>
		void add(Task::SharedPtr task);

		///<summary>Removes the task from the running tasks list.</summary>
		///<param name="taskId">The id of the completed task.</param>
		void removeCompleted(const Poco::UUID& taskId);

	private:
		Poco::ThreadPool pool;

		// The list of running tasks. A task should be removed once it has finished running.
		std::vector<Task::SharedPtr> runningTasks;
		// Mutex for the running tasks list.
		std::mutex runningTasksMutex;

		// A queue of pending tasks. These have not yet started execution.
		std::queue<Task::SharedPtr> taskQueue;

		///<summary>Runs the specified task using the thread pool, and adds the task to the 
		/// running tasks list.</summary>
		///<param name="task">The task to run.</param>
		void runTask(Task::SharedPtr task);
	};
}
