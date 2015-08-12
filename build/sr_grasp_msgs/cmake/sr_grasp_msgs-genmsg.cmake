# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "sr_grasp_msgs: 1 messages, 1 services")

set(MSG_I_FLAGS "-Isr_grasp_msgs:/home/catheter/catheter_position/src/sr_grasp_msgs/msg;-Iactionlib_msgs:/opt/ros/indigo/share/actionlib_msgs/cmake/../msg;-Imoveit_msgs:/opt/ros/indigo/share/moveit_msgs/cmake/../msg;-Ipcl_msgs:/opt/ros/indigo/share/pcl_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Iobject_recognition_msgs:/opt/ros/indigo/share/object_recognition_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Ishape_msgs:/opt/ros/indigo/share/shape_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Itrajectory_msgs:/opt/ros/indigo/share/trajectory_msgs/cmake/../msg;-Ioctomap_msgs:/opt/ros/indigo/share/octomap_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(sr_grasp_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/catheter/catheter_position/src/sr_grasp_msgs/msg/KCL_ContactStateStamped.msg" NAME_WE)
add_custom_target(_sr_grasp_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sr_grasp_msgs" "/home/catheter/catheter_position/src/sr_grasp_msgs/msg/KCL_ContactStateStamped.msg" "geometry_msgs/Vector3:std_msgs/Header:geometry_msgs/Point"
)

get_filename_component(_filename "/home/catheter/catheter_position/src/sr_grasp_msgs/srv/KCL_Sensor_Bias.srv" NAME_WE)
add_custom_target(_sr_grasp_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sr_grasp_msgs" "/home/catheter/catheter_position/src/sr_grasp_msgs/srv/KCL_Sensor_Bias.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(sr_grasp_msgs
  "/home/catheter/catheter_position/src/sr_grasp_msgs/msg/KCL_ContactStateStamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sr_grasp_msgs
)

### Generating Services
_generate_srv_cpp(sr_grasp_msgs
  "/home/catheter/catheter_position/src/sr_grasp_msgs/srv/KCL_Sensor_Bias.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sr_grasp_msgs
)

### Generating Module File
_generate_module_cpp(sr_grasp_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sr_grasp_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(sr_grasp_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(sr_grasp_msgs_generate_messages sr_grasp_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/catheter/catheter_position/src/sr_grasp_msgs/msg/KCL_ContactStateStamped.msg" NAME_WE)
add_dependencies(sr_grasp_msgs_generate_messages_cpp _sr_grasp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/catheter/catheter_position/src/sr_grasp_msgs/srv/KCL_Sensor_Bias.srv" NAME_WE)
add_dependencies(sr_grasp_msgs_generate_messages_cpp _sr_grasp_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sr_grasp_msgs_gencpp)
add_dependencies(sr_grasp_msgs_gencpp sr_grasp_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sr_grasp_msgs_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(sr_grasp_msgs
  "/home/catheter/catheter_position/src/sr_grasp_msgs/msg/KCL_ContactStateStamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sr_grasp_msgs
)

### Generating Services
_generate_srv_lisp(sr_grasp_msgs
  "/home/catheter/catheter_position/src/sr_grasp_msgs/srv/KCL_Sensor_Bias.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sr_grasp_msgs
)

### Generating Module File
_generate_module_lisp(sr_grasp_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sr_grasp_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(sr_grasp_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(sr_grasp_msgs_generate_messages sr_grasp_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/catheter/catheter_position/src/sr_grasp_msgs/msg/KCL_ContactStateStamped.msg" NAME_WE)
add_dependencies(sr_grasp_msgs_generate_messages_lisp _sr_grasp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/catheter/catheter_position/src/sr_grasp_msgs/srv/KCL_Sensor_Bias.srv" NAME_WE)
add_dependencies(sr_grasp_msgs_generate_messages_lisp _sr_grasp_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sr_grasp_msgs_genlisp)
add_dependencies(sr_grasp_msgs_genlisp sr_grasp_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sr_grasp_msgs_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(sr_grasp_msgs
  "/home/catheter/catheter_position/src/sr_grasp_msgs/msg/KCL_ContactStateStamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sr_grasp_msgs
)

### Generating Services
_generate_srv_py(sr_grasp_msgs
  "/home/catheter/catheter_position/src/sr_grasp_msgs/srv/KCL_Sensor_Bias.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sr_grasp_msgs
)

### Generating Module File
_generate_module_py(sr_grasp_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sr_grasp_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(sr_grasp_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(sr_grasp_msgs_generate_messages sr_grasp_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/catheter/catheter_position/src/sr_grasp_msgs/msg/KCL_ContactStateStamped.msg" NAME_WE)
add_dependencies(sr_grasp_msgs_generate_messages_py _sr_grasp_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/catheter/catheter_position/src/sr_grasp_msgs/srv/KCL_Sensor_Bias.srv" NAME_WE)
add_dependencies(sr_grasp_msgs_generate_messages_py _sr_grasp_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sr_grasp_msgs_genpy)
add_dependencies(sr_grasp_msgs_genpy sr_grasp_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sr_grasp_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sr_grasp_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sr_grasp_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(sr_grasp_msgs_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
add_dependencies(sr_grasp_msgs_generate_messages_cpp moveit_msgs_generate_messages_cpp)
add_dependencies(sr_grasp_msgs_generate_messages_cpp pcl_msgs_generate_messages_cpp)
add_dependencies(sr_grasp_msgs_generate_messages_cpp sensor_msgs_generate_messages_cpp)
add_dependencies(sr_grasp_msgs_generate_messages_cpp object_recognition_msgs_generate_messages_cpp)
add_dependencies(sr_grasp_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(sr_grasp_msgs_generate_messages_cpp shape_msgs_generate_messages_cpp)
add_dependencies(sr_grasp_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sr_grasp_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sr_grasp_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(sr_grasp_msgs_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
add_dependencies(sr_grasp_msgs_generate_messages_lisp moveit_msgs_generate_messages_lisp)
add_dependencies(sr_grasp_msgs_generate_messages_lisp pcl_msgs_generate_messages_lisp)
add_dependencies(sr_grasp_msgs_generate_messages_lisp sensor_msgs_generate_messages_lisp)
add_dependencies(sr_grasp_msgs_generate_messages_lisp object_recognition_msgs_generate_messages_lisp)
add_dependencies(sr_grasp_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(sr_grasp_msgs_generate_messages_lisp shape_msgs_generate_messages_lisp)
add_dependencies(sr_grasp_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sr_grasp_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sr_grasp_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sr_grasp_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(sr_grasp_msgs_generate_messages_py actionlib_msgs_generate_messages_py)
add_dependencies(sr_grasp_msgs_generate_messages_py moveit_msgs_generate_messages_py)
add_dependencies(sr_grasp_msgs_generate_messages_py pcl_msgs_generate_messages_py)
add_dependencies(sr_grasp_msgs_generate_messages_py sensor_msgs_generate_messages_py)
add_dependencies(sr_grasp_msgs_generate_messages_py object_recognition_msgs_generate_messages_py)
add_dependencies(sr_grasp_msgs_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(sr_grasp_msgs_generate_messages_py shape_msgs_generate_messages_py)
add_dependencies(sr_grasp_msgs_generate_messages_py geometry_msgs_generate_messages_py)
