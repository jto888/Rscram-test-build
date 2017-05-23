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
Rtools\gcc-4.6.3\bin on the PATH. What is needed is for this early PATH setting
to be Rtools\mingw\_32\bin in order to enable (i386 and x64) multiarch build
using gcc 4.9.3. [In all cases Rtools\\bin must be first in the PATH].

 

[Setting the path to Rtools\\mingw_64\\bin only works with a --no-multiarch
argument in the R INSTALL command.]

It is still mystifying that the build command is for g++ -std=c++0x . . .
although I have provided CXX_STD = CXX11 in a Makevars.win file AND I have
indicated SystemRequirements: C++11 in the DESCRIPTION file. However, the C++11
standard is being applied.

 

Next attempts to build through event.cc has been found to require ccfgroup.cc
(the call for \#include “ccfgroup.h” is in the event.cc NOT the event.h, which
was a little deceiving). Also, in ccfgroup.cc there are includes for
"expression/arithmetic.h" and "expression/constant.h" so the expression folder
is now required in src.  Within these expression headers lies an \#include back
to “src/expression.h”; however, this cannot be found during the R build. Edits
within these files now call for \#include “../expression.h” to make this work.

 

Use of auto command from C++14 is first encountered in ccfgroup.cc. So, build
failure occurs with only C++11 support. As of this date, 5-23-2017, R version
3.4.0 exists (it was just updated last month) with reported support for C++14;
however, Rtools 3.4 (not yet frozen) does not include support for C++14.

At this point test build development for Rscram will have to proceed on Ubuntu
Linux and the Windows test build must be suspended.

 
