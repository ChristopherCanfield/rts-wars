#pragma once

#include <Poco/Runnable.h>
#include <Poco/UUID.h>
#include <memory>

// Christopher D. Canfield
// March 2014
// Task.hpp

namespace cdc
{
	class TaskQueue;

	///<summary>A task that can be run concurrently.</summary>
	class Task :
		public Poco::Runnable
	{
	public:
		typedef std::shared_ptr<Task> SharedPtr;

		Task(TaskQueue& taskQueue);

		virtual ~Task() {}

		///<summary>Returns the task's unique id.</summary>
		///<return>the task's unique id.</return>
		const Poco::UUID& getTaskId() const;

		void run() override final;

	protected:
		///<summary>Executed when run() is called. Subclasses should override this method.</summary>
		virtual void runTask() = 0;

	private:
		Task& operator=(const Task&);

		TaskQueue& taskQueue;
		Poco::UUID id;
	};
}