Rscram-test-build
=================

Attempted build of SCRAM sources using Rtools  on Windows and Rcpp

 

The current attempt to build one of the most basic components of SCRAM as
element.cc has failed.

It is known that Olzhas is demonstrating “Modern C++” and it is likely that
current limitation to C++11 with boost headers added (via LinkingTo: BH) on
Windows is not sufficient.

Rtools support for C++11 consists of separate 32- and 64-bit builds of gcc 4.9.3
and mingw-w64 v3 compiled by Jeroen Ooms and others.

 

Further reference for requirements for such a build is contained in the
following links:

http://gallery.rcpp.org/articles/Rcpp-and-C++11-C++14-C++17/

https://support.rstudio.com/hc/en-us/articles/200486088-Using-Rcpp-with-RStudio

 

It may well be that C++14 support expected with R version 3.4.0 perhaps in April
2017 will be needed to complete this build.
