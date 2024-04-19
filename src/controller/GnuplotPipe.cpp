//  file: GnuplotPipe.cpp
//
//  Definitions for the GnuplotPipe C++ class.
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02/06/06  original version, based on gnuplot_pipe
//      02/07/09  minor upgrades 
//      02/14/11  added #include <stdlib.h>
//      04/18/2024 Updated for use in QuantumVisualizer
//
//  Notes:
//    * This is still rather kludgey, with ad hoc delays added
//       to make it work.
//
//  To do:
//    * There are many things that could be implemented, including 
//       setting the style, outputting to postscript, resetting the plot
//    * Implement separate classes for the curves on an individual
//       plot as well as separate classes for different plot windows 
//    * Figure out how to set an appropriate delay adjusted to the
//       speed of the computer
//    
//
//*****************************************************************
// include files
#include <cmath>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
using std::ostringstream;

#include "GnuplotPipe.h"

//********************************************************************

// Constructor for GnuplotPipe (add more)
GnuplotPipe::GnuplotPipe ( )
{

  // Set defaults for filehandles and file names 
  gp_cmd = 0;
  fileout = 0;
  filename = "gnupipe1.dat";
  
  // Set titles to blanks
  title = " ";
  xlabel = " ";
  ylabel = " ";
  plot_title = " ";
  
  // Set min and max defaults to use autoscaling
  xmin = 0.;
  xmax = 0.;
  ymin = 0.;
  ymax = 0.;
  
  delay = 10000;   // This delay is software/hardware dependent.
                   //  Can we do better?
}

// Copy constructor (needs to be written)

// Destructor for GnuplotPipe
GnuplotPipe::~GnuplotPipe ()
{
   // put an appropriate destructor here
}


int
GnuplotPipe::init ( )
{
  ostringstream cmd_stream; 

  gp_cmd = popen ("gnuplot", "w");  // don't sleep  before running
  std::cout<<"Opened Gnuplot!\n";
  if (!gp_cmd) 
  {
    std::cout << "Could not open gnuplot! " << std::endl;
    return(1);
  }
  usleep(int(delay));  // wait a bit to let the gnuplot window open
  
  fileout = fopen (filename.c_str(), "a");

  gnuplot_cmd ("set timestamp");

  cmd_stream.str ("");
  cmd_stream << "set title \"" << title << "\"";
  gnuplot_cmd (cmd_stream.str());
  
  cmd_stream.str ("");
  cmd_stream << "set xlabel \"" << xlabel << "\"";
  gnuplot_cmd (cmd_stream.str());
  
  cmd_stream.str ("");
  cmd_stream << "set ylabel \"" << ylabel << "\"";
  gnuplot_cmd (cmd_stream.str());

  if (xmin == xmax)    // autoscaling condition
  {                      
    gnuplot_cmd ("set autoscale x");
  }
  else
  {
    cmd_stream.str ("");
    cmd_stream << "set xrange [" << xmin << ":" << xmax << "]";
    gnuplot_cmd (cmd_stream.str());
  }
  if (ymin == ymax)   // autoscaling condition
  {           
    gnuplot_cmd ("set autoscale y");
  }
  else
  {
    cmd_stream.str ("");
    cmd_stream << "set yrange [" << ymin << ":" << ymax << "]";
    gnuplot_cmd (cmd_stream.str());
  }

  // this string sets up the plots 
  cmd_stream.str ("");
  cmd_stream << "splot \"" << filename 
             << "\" using 1:2:3 title \"" << plot_title 
             << "\" w surface"; 
  plot_cmd = cmd_stream.str();
  gnuplot_cmd(plot_cmd);
  
  return (0);
}

int
GnuplotPipe::plot (const double x, const double y)
{
  // print the x-y data to a file 
  fprintf (fileout, "%e %e\n", x, y);
  fflush (fileout);  // flush the buffer so that gnuplot can read it 

  //gnuplot_cmd ("replot");
  gnuplot_cmd (plot_cmd);
  usleep (delay);

  return (0);
}

int
GnuplotPipe::gnuplot_cmd (const string &plot_cmd_local)
{
  ostringstream cmd_stream;
  cmd_stream << plot_cmd_local << std::endl;  // add in a return
  // std::cout << "cmd: " << cmd_stream.str() << std::endl;
  
  fprintf (gp_cmd, "%s", cmd_stream.str().c_str());
  fflush (gp_cmd);

  return (0);
}

int
GnuplotPipe::finish ()
{
  pclose (gp_cmd);  // close a gnuplot handle
  fclose (fileout);  // close the first data file

  return (0);
}

