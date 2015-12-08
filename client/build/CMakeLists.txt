#cmake_minimum_required (VERSION 2.6)
#project (R_Ttype)
#add_executable(Tutorial client/common/main.cpp)

#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(R-Type)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}" ../common ../unix ../windows ../../common ../../server ../../common/Thread)
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Define sources and executable
set(EXECUTABLE_NAME "r-type_client")
add_executable(${EXECUTABLE_NAME}
  ../../common/Network.hpp
  ../../common/Thread/ThreadUnix.hpp
  ../common/main.cpp
  ../common/RenderWindow.cpp
  ../common/Vector2.cpp
  ../common/APanel.cpp
  ../common/Bind.cpp
  ../common/SoundManager.cpp
  ../common/Button.cpp
  ../common/ButtonFactory.cpp
  ../common/Color.cpp
  ../common/DemoPanel.cpp
  ../common/Font.cpp
  ../common/GamePanel.cpp
  ../common/JoinPanel.cpp
  ../common/InputManager.cpp
  ../common/LoadingPanel.cpp
  ../common/StartPanel.cpp
  ../common/PanelFactory.cpp
  ../common/Player.cpp
  ../common/RoomPanel.cpp
  ../common/AMenuElement.cpp
  ../common/Client.cpp
  ../common/Settings.cpp
  ../common/Text.cpp
  ../common/Texture.cpp
  ../common/Volume.cpp
  ../common/ProtocoleClient.cpp
  ../common/SettingsLoader.cpp
  ../common/SettingsPanel.cpp
  ../common/Sprite.cpp
  )


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)

#Find Thread
find_package (Threads)

message("CMAKE_BUILD_TYPE is ${CMAKE_CXX_FLAGS}")

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${R-Type_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${R-Type_VERSION_MINOR}")
include(CPack)
