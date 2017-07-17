#include "scaffold.h"

//Rcpp namespace items are specifically called below
//using namespace Rcpp;

SEXP scaffold_test(SEXP arg1, SEXP arg2, SEXP arg3)  {

Rcpp::StringVector tag_v=arg1;
int df_rows = tag_v.size()-1;
Rcpp::StringVector name[1];
name[0]=tag_v[df_rows];
tag_v.erase(df_rows);
/*
//int_vec<-c(DF$ID, DF$Type, DF$MOE, DF$EType, DF$parent, DF$UType)
//num_vec<-c(DF$CFR, DF$PBF, DF$CRT, DF$P1, DF$P2, DF$UP1, DF$UP2)

Rcpp::IntegerVector ints_in=arg2;
//id_v=ints_in(0:df_rows);
//id_v=ints_in[(ints_in > (double) -1) & (ints_in < (double) df_rows)];
*/

std::vector<int> v(df_rows);
std::iota(v.begin(), v.end(), 0);
Rcpp::IntegerVector df1_v=Rcpp::wrap(v);
// Rcpp::as never worked in these cases, glad I tried Rcpp::wrap
//Rcpp::IntegerVector df1_v=Rcpp::as<Rcpp::IntegerVector>(v);
// why wouldn't this breakdown work???
//Rcpp::IntegerVector new_v[df_rows];
//new_v=Rcpp::wrap(v);

Rcpp::IntegerVector ints_in=arg2;
Rcpp::IntegerVector id_v=Rcpp::wrap(ints_in[df1_v]);
Rcpp::NumericVector nums_in=arg3;
Rcpp::NumericVector cfr_v=Rcpp::wrap(nums_in[df1_v]);

std::iota(v.begin(), v.end(), df_rows);
Rcpp::IntegerVector df2_v=Rcpp::wrap(v);
Rcpp::IntegerVector type_v=Rcpp::wrap(ints_in[df2_v]);
Rcpp::NumericVector pbf_v=Rcpp::wrap(nums_in[df2_v]);

std::iota(v.begin(), v.end(), 2*df_rows);
Rcpp::IntegerVector df3_v=Rcpp::wrap(v);
Rcpp::IntegerVector moe_v=Rcpp::wrap(ints_in[df3_v]);
Rcpp::NumericVector crt_v=Rcpp::wrap(nums_in[df3_v]);

std::iota(v.begin(), v.end(), 3*df_rows);
Rcpp::IntegerVector df4_v=Rcpp::wrap(v);
Rcpp::IntegerVector etype_v=Rcpp::wrap(ints_in[df4_v]);
Rcpp::NumericVector p1_v=Rcpp::wrap(nums_in[df4_v]);

std::iota(v.begin(), v.end(), 4*df_rows);
Rcpp::IntegerVector df5_v=Rcpp::wrap(v);
Rcpp::IntegerVector parent_v=Rcpp::wrap(ints_in[df5_v]);
Rcpp::NumericVector p2_v=Rcpp::wrap(nums_in[df5_v]);

std::iota(v.begin(), v.end(), 5*df_rows);
Rcpp::IntegerVector df6_v=Rcpp::wrap(v);
Rcpp::IntegerVector utype_v=Rcpp::wrap(ints_in[df6_v]);
Rcpp::NumericVector up1_v=Rcpp::wrap(nums_in[df6_v]);

std::iota(v.begin(), v.end(), 6*df_rows);
Rcpp::IntegerVector df7_v=Rcpp::wrap(v);
Rcpp::NumericVector up2_v=Rcpp::wrap(nums_in[df7_v]);

Rcpp::DataFrame df = Rcpp::DataFrame::create(
	Rcpp::Named("id")=Rcpp::wrap(id_v), 
	Rcpp::Named("parent")=Rcpp::wrap(parent_v),
	Rcpp::Named("tag")=Rcpp::wrap(tag_v),
	Rcpp::Named("moe")=Rcpp::wrap(moe_v),
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
}

