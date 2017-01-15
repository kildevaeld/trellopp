message(STATUS "Using GITHUB++_INCLUDE_DIRS: ${TRELLO++_INCLUDE_DIRS}.")


include_directories(${TRELLO++_INCLUDE_DIRS})
add_executable(trello main.cpp)
target_link_libraries(trello trello++)