
include_directories(${TRELLO++_INCLUDE_DIRS})
include_directories(${CPR_INCLUDE_DIRS})

set(SOURCES
    client.cpp
    board.cpp
    board_options.cpp
    member.cpp
    request.cpp
    response.cpp
    utils.cpp
)

add_library(${TRELLO++_LIBRARIES} ${SOURCES})
target_link_libraries(${TRELLO++_LIBRARIES} ${CPR_LIBRARIES})