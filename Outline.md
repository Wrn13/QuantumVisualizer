# Project Goal
Develop an application that solves the 2D harmonic oscillator equation 

# Steps
## Setup Devlopement Environment
- Setup Github page (done)
- Develop outline (done)
- Setup project structure (done)
- Configure CMake (done)

## Develop UI for the User-Defined Potentials
### Research Qt
Discover the structure of a Qt GUI (done)
#### Develop a way to create squares on a grid using mouse input
- Create class to draw squares on the drawable area, maybe with QPainter or QGraphicsView (in progress)
- Create a main area widget that tracks mouse position and events (in progress)
####  Create ui list which displays a selected potential and its corresponding height which the user can modify
- Need potential class (in progress)
- vector of potentials for list of current potentials
- Color code different potentials (optional)
#### Submit button
- Transfer control over to the backend sending the list of current potentials
## Develop Backend to Solve Schrodinger's Equation
### Develop algorithm to solve 2D Schrodinger Equation Numerically 
- Add list of current potentials to the potential matrix
#### Implement finite differences algorithm 
- Create class for Hamiltonian
- Create class for wavefunction
- Create algorithm to solve the schrodinger equation
- Transfer control back to UI passing the resulting wavefunction

## Display Results to the UI
- Display the results, possibly by piping through gnuplot
