project(ecs_box2d)
cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)

configure_file(
    ${CMAKE_SOURCE_DIR}/resources/modular_ships.png
    ${CMAKE_BINARY_DIR}/resources/modular_ships.png 
    COPYONLY
)
configure_file(
    ${CMAKE_SOURCE_DIR}/resources/resources.json
    ${CMAKE_BINARY_DIR}/resources/resources.json 
    COPYONLY
)


add_subdirectory(pkgs/entityx)

add_definitions(-DIMGUI_USER_CONFIG="imconfig-SFML.h")

set (PKG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/include)
set (JSON_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/json/include)
set (ENTITYX_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/entityx)
set (IMGUI_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/pkgs/imgui
    ${CMAKE_SOURCE_DIR}/pkgs/imgui-sfml
)
set (BOX2D_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/Box2D/Box2D)

set (SRCS
    src/coordinates.cpp
    src/main.cpp
    src/mainwindow.cpp
    src/resourcemanager.cpp
    src/sfmldebugdraw.cpp

    src/systems/bodysystem.cpp
    src/systems/box2dsystem.cpp
    src/systems/controlsystem.cpp
    src/systems/rendersystem.cpp
)

set (IMGUI_SRCS
    pkgs/imgui/imgui.cpp
    pkgs/imgui/imgui_demo.cpp
    pkgs/imgui/imgui_draw.cpp
    pkgs/imgui-sfml/imgui-SFML.cpp
)

set (BOX2D_SRCS
    pkgs/Box2D/Box2D/Box2D/Collision/Shapes/b2ChainShape.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/Shapes/b2CircleShape.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/Shapes/b2EdgeShape.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/Shapes/b2PolygonShape.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2BroadPhase.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2BroadPhase.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2BroadPhase.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2CollideCircle.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2CollideEdge.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2CollidePolygon.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2Collision.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2Distance.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2DynamicTree.cpp
    pkgs/Box2D/Box2D/Box2D/Collision/b2TimeOfImpact.cpp
    pkgs/Box2D/Box2D/Box2D/Common/b2BlockAllocator.cpp
    pkgs/Box2D/Box2D/Box2D/Common/b2Draw.cpp
    pkgs/Box2D/Box2D/Box2D/Common/b2Math.cpp
    pkgs/Box2D/Box2D/Box2D/Common/b2Settings.cpp
    pkgs/Box2D/Box2D/Box2D/Common/b2StackAllocator.cpp
    pkgs/Box2D/Box2D/Box2D/Common/b2Timer.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2CircleContact.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2Contact.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2ContactSolver.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Contacts/b2PolygonContact.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2DistanceJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2FrictionJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2GearJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2Joint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2MotorJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2MouseJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2PulleyJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2RopeJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2WeldJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/Joints/b2WheelJoint.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/b2Body.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/b2ContactManager.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/b2Fixture.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/b2Island.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/b2World.cpp
    pkgs/Box2D/Box2D/Box2D/Dynamics/b2WorldCallbacks.cpp
    pkgs/Box2D/Box2D/Box2D/Rope/b2Rope.cpp
)

set (ENTITYX_LIBS
    entityx
)

set (IMGUI_LIBS
    sfml-window sfml-graphics sfml-system
)

add_library(box2d STATIC ${BOX2D_SRCS})
target_include_directories(box2d PRIVATE ${BOX2D_INCLUDE_DIR})

link_directories(${CMAKE_SOURCE_DIR}/pkgs/lib ${CMAKE_BINARY_DIR}/pkgs/entityx)

add_library(stdc++fs UNKNOWN IMPORTED)
if (MINGW)
    set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "C:/mingw-w64/x86_64-7.3.0-posix-seh-rt_v5-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/7.3.0/libstdc++fs.a")
else (MINGW)
    file(GLOB_RECURSE FILESYSTEM_LIBRARY_PATH /usr/lib/**/libstdc++fs.a)
    set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION ${FILESYSTEM_LIBRARY_PATH})
endif (MINGW)

add_executable(ecs_box2d
    ${IMGUI_SRCS}
    ${SRCS}
)
target_include_directories(ecs_box2d PRIVATE ${CMAKE_SOURCE_DIR}/src ${JSON_INCLUDE_DIR} ${PKG_INCLUDE_DIR} ${ENTITYX_INCLUDE_DIR} ${IMGUI_INCLUDE_DIRS} ${BOX2D_INCLUDE_DIR})
if (WIN32)
    target_link_libraries(ecs_box2d PRIVATE ${ENTITYX_LIBS} ${IMGUI_LIBS} box2d opengl32 gdi32 shell32 stdc++fs)
else (WIN32)
    target_link_libraries(ecs_box2d PRIVATE ${ENTITYX_LIBS} ${IMGUI_LIBS} box2d GL GLU stdc++fs)
endif (WIN32)
