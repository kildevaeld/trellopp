#pragma once
#include <utility>

#ifndef TRELLO_FWD
#define TRELLO_FWD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)
#endif