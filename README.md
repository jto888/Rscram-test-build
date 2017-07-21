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

A package can define the C++ standard most effectively using SystemRequirements
in the DESCRIPTION file.

 

Next attempts to build through event.cc has been found to require ccfgroup.cc
(the call for \#include “ccfgroup.h” is in the event.cc NOT the event.h, which
was a little deceiving). Also, in ccfgroup.cc there are includes for
"expression/numerical.h" and "expression/constant.h" so the expression folder is
now required in src. Within these expression headers lies an \#include back to
“src/expression.h”; however, this cannot be found during the R build. Edits
within these files now call for \#include “../expression.h” to make this work.

 

Use of auto command from C++14 is first encountered in ccfgroup.cc. So, build
failure occurs with only C++11 support. As of this date, 5-23-2017, R version
3.4.0 exists (it was just updated last month) with reported support for C++14;
however, Rtools 3.4 (not yet frozen) does not include support for C++14.

At this point test build development for Rscram will have to proceed on Ubuntu
Linux and the Windows test build must be suspended.

 

The .cc source files in the expression folder will not compile without
directives exampled in package RSiena that may take some trial and error yet.

https://stackoverflow.com/questions/39485359/in-rcpp-based-package-howto-write-makevars-in-project-with-subdirectories-in-src

The best solution appears to be to leave the headers in the expression folder,
but move the source files (\*.cc) into the main src folder. This results in some
modest edits to \#include directives in these files that could be built into a
script. In the source files that have been moved to src reference to their own
headers must now be to the expression folder. Any reference to src needs to be
altered to drop directory. In the header files left in the expression folder
reference to “src/ files needs to be altered to “../ for the R build system to
understand.

After some success with the builds incrementally through faulttree.cc and
paramater.cc I decided to go for the remaining src (excluding scram.cc, to be
rewritten as scram.cpp without a main function) at once.

The following issues were found:

1.  bdd.cc calls for boost/multiprecision/miller_rabin.hpp which was not in the
    BH package. Inserting this header file into the local library for BH enabled
    the compile to complete. This is not acceptable for a package build, so an
    issue has been raised on https://github.com/eddelbuettel/bh

2.  libxml++ library is required for config.cc, initializer.cc, version.cc.in
    and reporter.cc. Removing these files with headers results in a successful
    build.

I had some thought to building a complete scram inside of R and allowing all the
file read/write activity to take place, since loading model data into required
objects seems over my head. However, utilizing initializer and reporter would
entail system requirements for libxml++, libxml2, and
[glibmm-2.4](http://www.gtkmm.org/) (or a subset of it containing at least
Glib::ustring). This is more extensive than simply requiring a binary
installation of SCRAM. So this will not be happening.

Must now go back to considering the better solution of instantiating model
objects on my own and recovering analysis output directly.

 

### Facade and Scaffold

Having proven successful build of the scram core, development is now focused on
an R facade and scaffold to cpp. The scaffold is  accomplished by passing the
appropriate contents of an R ftree object to the C++ environment where scram
objects can be instantiated and analysis performed. An initial scaffold test is
executed using an R facade function named test.scaffold. This  transfers of a
table of data from R to C++ arrays, and proves accomplishment by returning a
view crafted in the C++ environment.

The next step has been to prove the interpretation of the fault tree data in C++
to define the model structure of the fault tree. Key to this interpretation is a
“find” function to identify unique gates and child nodes of each gate. In order
to accomplish this with limited C++ knowledge was to utilize the Armadillo C++
library for use of its find method for its container types. A function
test.gates proves this interpretation by returning the results of each gate
determined by a loop making multiple calls to a gate_test function in cpp.

Next steps are to instantiate model and fault-tree objects in scram and return
proof of that construction back to R.

Similarly to gates the attributes of each basic-event element must be
interpreted and ultimately instantiated in scram objects.

 
