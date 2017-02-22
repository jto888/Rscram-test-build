Rscram-test-build
=================

Attempted build of SCRAM sources using Rtools on Windows and Rcpp

It is known that Olzhas is demonstrating “Modern C++” and this test build is
critical to close integration of the FaultTree package on R with SCRAM.

The current attempt to build one of the most basic components of SCRAM as
element.cc **has been successful!**

Rtools support for C++11 consists of separate 32- and 64-bit builds of gcc 4.9.3
and mingw-w64 v3 compiled by Jeroen Ooms and others. However it has been found
that during installation of Rtools an option to set the PATH environment sets
the path to Rtools\gcc-4.6.3\bin. What is needed is for this early PATH setting
to be Rtools\mingw\_32\bin in order to enable (i386 and x64) multiarch build
using gcc 4.9.3.

 

[Setting the path to Rtools\\mingw_64\\bin only works with a --no-multiarch
argument in the R INSTALL command.]

It is still mystifying that the build command is for g++  -std=c++0x . . .
although I have provided CXX_STD = CXX11 in a Makevars.win file AND I have
indicated SystemRequirements: C++11 in the DESCRIPTION file. However, all seems
well.
