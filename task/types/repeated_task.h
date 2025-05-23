#pragma once

#include "base_task.h"

class RepeatedTask : public BaseTask
{
public:
	int counter = 0;
	int interval;

	RepeatedTask(int interval, std::function<void(RepeatedTask* self)> onUpdate, std::function<void(RepeatedTask* self)> onComplete);

	void Update(int deltaTick) override;
};

