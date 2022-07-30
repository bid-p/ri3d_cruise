#pragma once

#include "main.h"

#define Async(code) src::Actions::doAsync([]() code);

static constexpr uint32_t NUM_WORKERS = 3;

namespace src::Actions {
void workerExec(void*);

static const pros::Task asyncWorker1(workerExec, nullptr, "asyncWorker1");
static const pros::Task asyncWorker2(workerExec, nullptr, "asyncWorker2");
static const pros::Task asyncWorker3(workerExec, nullptr, "asyncWorker3");
}  // namespace src::Actions
