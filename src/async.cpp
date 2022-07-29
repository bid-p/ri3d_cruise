#include "async.hpp"

#include <list>

#include "common.h"

static pros::Mutex asyncQueueLock;
static std::list<std::function<void()>> asyncExecQueue;

namespace src::Actions {

static pros::Task asyncExecTask([](void*) {
    while (1) {
        asyncQueueLock.take();
        asyncExecQueue.clear();  // clears queue on task start.
        asyncQueueLock.give();

        while (!pros::competition::is_disabled() && asyncExecTask.notify_take(0, TIMEOUT_MAX)) {  // waits to be notified to execute
            asyncQueueLock.take();

            auto func = asyncExecQueue.front();
            asyncExecQueue.pop_front();

            asyncQueueLock.give();

            func();  // pull+pop front function off queue and run it.
            pdelay(1);
        }
        pdelay(1);
    }
},
                                nullptr, "solo async worker");

void doAsync(std::function<void()> func) {
    asyncQueueLock.take();
    asyncExecQueue.push_back(func);  // adds to list of functions to be executed asynchronously.
    asyncQueueLock.give();

    asyncExecTask.notify();  // notifies async execution task to run function.
}

}  // namespace src::Actions