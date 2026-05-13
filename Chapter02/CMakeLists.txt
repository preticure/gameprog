add_executable(Chapter02)

target_sources(Chapter02
    PRIVATE
        actor.cpp
        anim_sprite_component.cpp
        bg_sprite_component.cpp
        component.cpp
        game.cpp
        main.cpp
        ship.cpp
        sprite_component.cpp)

target_link_libraries(Chapter02 PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)

set_target_properties(Chapter02 PROPERTIES
    OUTPUT_NAME "tChapter02")

add_custom_command(TARGET Chapter02 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rm -rf 
        "$<TARGET_FILE_DIR:Chapter02>/Assets"
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_CURRENT_SOURCE_DIR}/Assets"
        "$<TARGET_FILE_DIR:Chapter02>/Assets"
)
