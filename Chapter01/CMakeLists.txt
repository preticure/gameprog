add_executable(Chapter01)

target_sources(Chapter01
    PRIVATE
        game.cpp
        game.h
        main.cpp)

target_link_libraries(Chapter01 PRIVATE SDL3::SDL3)

set_target_properties(Chapter01 PROPERTIES
    OUTPUT_NAME "tChapter01")
