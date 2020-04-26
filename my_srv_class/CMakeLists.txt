cmake_minimum_required(VERSION 3.5)
project(my_srv_class)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(rclcpp REQUIRED)
find_package(my_messages REQUIRED)
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

include_directories(include)

add_executable(srv_test
    src/my_srv.cpp
    src/my_srv_main.cpp
)
ament_target_dependencies(srv_test
    rclcpp
    my_messages
)
add_executable(clnt_test
    src/my_clnt.cpp
    src/my_clnt_main.cpp
)
ament_target_dependencies(clnt_test
    rclcpp
    my_messages
)
add_executable(clnt_test2
    src/my_clnt_with_lambda.cpp
    src/my_clnt_main_with_lambda.cpp
)
ament_target_dependencies(clnt_test2
    rclcpp
    my_messages
)
install(TARGETS
    srv_test
    clnt_test
    clnt_test2
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
