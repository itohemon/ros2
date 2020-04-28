cmake_minimum_required(VERSION 3.5)
project(minimal_comp)

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
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
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

add_library(minimal_comp_node SHARED
    src/minimal_comp_node1.cpp
    src/minimal_comp_node2.cpp
)
target_compile_definitions(minimal_comp_node
    PRIVATE "MY_LIBRARY_BUILDING_LIBRARY"
)
target_compile_options(minimal_comp_node PUBLIC -Wall)
ament_target_dependencies(minimal_comp_node
    rclcpp
)

target_include_directories(minimal_comp_node
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if(NOT WIN32)
    ament_environment_hooks(
        "${ament_cmake_package_templates_ENVIRONMENT_HOOK_LIBRARY_PATH}"
    )
endif()

ament_export_interfaces(export_minimal_comp_node HAS_LIBRARY_TARGET)
ament_export_dependencies(rclcpp)
ament_export_libraries(minimal_comp_node)
ament_export_include_directories(include)

install(
    DIRECTORY include/
    DESTINATION include
)
install(TARGETS
    minimal_comp_node
    EXPORT export_minimal_comp_node
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

ament_package()
