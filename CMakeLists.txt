cmake_minimum_required(VERSION 2.8.3)
project(acura_steering)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  can_msgs
)


catkin_package()

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_executable(acura_steering_node src/acura_steering.cpp)
add_dependencies(acura_steering_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(acura_steering_node ${catkin_LIBRARIES})

 install(TARGETS acura_steering_node 
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

