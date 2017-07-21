#ifndef _Rscram_H
#define _Rscram_H

#ifdef __cplusplus
//#include <Rcpp.h>
#include <RcppArmadillo.h>
RcppExport SEXP attribute_test(SEXP arg1, SEXP arg2, SEXP arg3);
RcppExport SEXP settings_test(SEXP, SEXP);
RcppExport SEXP scaffold_test(SEXP, SEXP, SEXP);
RcppExport SEXP gate_test(SEXP, SEXP, SEXP, SEXP);

#endif
#endif