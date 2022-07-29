#pragma once

#include "main.h"
#define Async(code) src::Actions::doAsync([]() code);

namespace src::Actions {
void doAsync(std::function<void()> func);
}  // namespace src::Actions
