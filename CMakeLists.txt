cmake_minimum_required(VERSION 3.27)
project(lab_OOP_6)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(lab_OOP_6
        src/main.cpp
        src/NPC/NPC.cpp
        src/NPC/Orc.cpp
        src/NPC/Squirrel.cpp
        src/NPC/Druid.cpp
        src/Factory/NPCFactory.cpp
        src/Visitor/BattleVisitor.cpp
        src/Observer/ConsoleObserver.cpp
        src/Observer/FileObserver.cpp
)