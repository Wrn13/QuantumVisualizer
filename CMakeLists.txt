cmake_minimum_required(VERSION 3.0)
project(QuantumVisualizer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

find_package(GSL REQUIRED)

add_library(lambda_lanczos
            INTERFACE modules/lambda-lanczos/include)

set(quantumvisualizer_SRC
  src/main.cpp
  src/view/quantumvisualizer.cpp
  src/model/Hamiltonian.cpp
  src/model/Potential.cpp
  src/controller/GnuplotPipe.cpp
)

# Tell CMake to create the helloworld executable
add_executable(quantumvisualizer ${quantumvisualizer_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(quantumvisualizer Qt5::Widgets)
target_link_libraries(quantumvisualizer GSL::gsl GSL::gslcblas)
target_link_libraries(quantumvisualizer GSL::gsl GSL::gslcblas)

# Install the executable
install(TARGETS quantumvisualizer DESTINATION bin)

# Create testing target
add_executable(QuantumVisualizerTest src/tests/QuantumVisualizerTest.cpp)

target_link_libraries(QuantumVisualizerTest Qt5::Widgets)
target_link_libraries(QuantumVisualizerTest GSL::gsl GSL::gslcblas)

#Enable Testing Functionality
enable_testing()

# Define Tests
add_test(
    NAME QuantumVisualizerTest
    COMMAND $<TARGET_FILE:QuantumVisualizerTest>
)
