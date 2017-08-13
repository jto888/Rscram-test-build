#include "Rscram.h"

//Rcpp namespace items are specifically called below
//using namespace Rcpp;

SEXP scaffold_test(SEXP chars_in, SEXP _ints_in, SEXP _nums_in)  {
// Unpack the "by type" argument vectors into ftree-like named Rcpp vectors
// Note: we are also recovering the name of the inputting ftree to use as fault-tree name
Rcpp::StringVector tag_v=chars_in;
int df_rows = tag_v.size()-1;
Rcpp::StringVector name[1];
name[0]=tag_v[df_rows];
tag_v.erase(df_rows);

Rcpp::IntegerVector ints_in=_ints_in;
Rcpp::NumericVector nums_in=_nums_in;

Rcpp::IntegerVector id_v(ints_in.begin(), std::next(ints_in.begin(), df_rows));
Rcpp::NumericVector cfr_v(nums_in.begin(), std::next(nums_in.begin(), df_rows));

Rcpp::IntegerVector type_v(ints_in.begin()+df_rows, std::next(ints_in.begin()+df_rows, df_rows));
Rcpp::NumericVector pbf_v(nums_in.begin()+df_rows, std::next(nums_in.begin()+df_rows, df_rows));

Rcpp::IntegerVector etype_v(ints_in.begin()+2*df_rows, std::next(ints_in.begin()+2*df_rows, df_rows));
Rcpp::NumericVector crt_v(nums_in.begin()+2*df_rows, std::next(nums_in.begin()+2*df_rows, df_rows));

Rcpp::IntegerVector parent_v(ints_in.begin()+3*df_rows, std::next(ints_in.begin()+3*df_rows, df_rows));
Rcpp::NumericVector p1_v(nums_in.begin()+3*df_rows, std::next(nums_in.begin()+3*df_rows, df_rows));

Rcpp::IntegerVector utype_v(ints_in.begin()+4*df_rows, std::next(ints_in.begin()+4*df_rows, df_rows));
Rcpp::NumericVector p2_v(nums_in.begin()+4*df_rows, std::next(nums_in.begin()+4*df_rows, df_rows));

Rcpp::NumericVector up1_v(nums_in.begin()+5*df_rows, std::next(nums_in.begin()+5*df_rows, df_rows));

Rcpp::NumericVector up2_v(nums_in.begin()+6*df_rows, std::next(nums_in.begin()+6*df_rows, df_rows));
//

Rcpp::DataFrame df = Rcpp::DataFrame::create(
	Rcpp::Named("id")=Rcpp::wrap(id_v), 
	Rcpp::Named("parent")=Rcpp::wrap(parent_v),
	Rcpp::Named("type")=Rcpp::wrap(type_v),
	Rcpp::Named("tag")=Rcpp::wrap(tag_v),
	Rcpp::Named("fail_rate")=Rcpp::wrap(cfr_v), 
	Rcpp::Named("probability")=Rcpp::wrap(pbf_v),
	Rcpp::Named("repair_time")=Rcpp::wrap(crt_v), 
	Rcpp::Named("etype")=Rcpp::wrap(etype_v),	
	Rcpp::Named("p1")=Rcpp::wrap(p1_v),	
	Rcpp::Named("p2")=Rcpp::wrap(p2_v),	
	Rcpp::Named("utype")=Rcpp::wrap(utype_v),	
	Rcpp::Named("up1")=Rcpp::wrap(up1_v),	
	Rcpp::Named("up2")=Rcpp::wrap(up2_v)	
	);

return df;

/*
arma::uvec gpos=arma::find(type_v > 9);
arma::uvec chpos_a=arma::find(parent_v==id_v[gpos(0)]);
Rcpp::IntegerVector chpos(chpos_a.begin(),chpos_a.end());
Rcpp::StringVector children=tag_v[chpos];

return Rcpp::wrap(gpos);
// this now works
//return Rcpp::wrap(children);
*/

}

