cmake_minimum_required(VERSION 2.8.3)
project(wheel_monitor)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  can_msgs
  message_generation
)

add_message_files(
  FILES
  Wheels.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)
catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_executable(wheel_monitor_node src/wheel_monitor.cpp)

add_dependencies(wheel_monitor_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(wheel_monitor_node ${catkin_LIBRARIES})

 install(TARGETS wheel_monitor_node 
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

