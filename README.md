# QuantumVisualizer
Project for Physics 5810
Generates the 2D wavefunction for the ground state of user defined potential.

CMake Qt5 GUI Template Compilation Instructions
-----------------------------------------------

You need Qt5 and CMake 2.8.11 or higher, as well as Gnunplot installed
and added to your path

-- Build instructions --
Inside the project's directory:

mkdir build
cd /build
cmake ../
make

./quantumvisualizer

-- Tutorials and resources --

Qt online docs
https://doc.qt.io/

## Running the application.

After typing ./quantumvisualizer into console, you will be 
greeted with a Qt window with a large white box on the left and two buttons on the right.
To add a peak to the potential, click on the "Add New Potential Button".
This will create a colored rectangle on the left, and a textbox on the right with the corresponding label.
To modify the potential peak's height, type in a number to the text box. To move the potential peak's location,
drag the rectangle to your heart's content.
Once you are done, click on the Generate Wavefunction button. This will compute the wavefunction, and after some
time, launch Gnuplot with the wavefunction graphed. After 30 seconds or after you close the window,
the application will close.

## Status
4-18-24 - Yes I know the wavefunction isn't being generated properly. The hamiltonian is being created properly however.
