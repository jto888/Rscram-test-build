#include "Rscram.h"

//std::vector<int> findGatePositions(Rcpp::IntegerVector v);
//std::vector<int> findChildPositions(Rcpp::IntegerVector v, int& position);
//Rcpp namespace items are specifically called below
//using namespace Rcpp;

SEXP gate_test(SEXP chars_in, SEXP _ints_in, SEXP _nums_in, SEXP _gpp)  {
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

// Note: gpp holds the position in the gate position vector gpos 
// for the gate of interest.
Rcpp::IntegerVector gpp_v=_gpp;
int gpp=gpp_v[0];

// Using Armadillo to find the vector positions of gate nodes
arma::colvec type_a=Rcpp::as<arma::colvec>(type_v);
arma::uvec gpos_a=arma::find(type_a > 9);
std::vector<int> gpos(gpos_a.begin(), gpos_a.end());

// Using Armadillo to find the positions of children to this given gate(gpos[gpp])
arma::colvec parent_a=Rcpp::as<arma::colvec>(parent_v);
arma::uvec chpos_a=arma::find(parent_a==id_v[gpos[gpp]]);
Rcpp::IntegerVector chpos(chpos_a.begin(), chpos_a.end());

// Establish the string describing the type for this given gate
// using the same logic as constructed in ftree2mef
std::string gate_type;
if(type_v[gpos[gpp]]==10) {
	if(chpos.size()==1) {
		gate_type="passthrough";
	}else{
		gate_type="or";
	}	
}else{
	if(type_v[gpos[gpp]]==16) {
		gate_type="atleast";
	}else{
		gate_type="and";
	}
}




Rcpp::List outlist = Rcpp::List::create(
	Rcpp::Named("fault-tree-name")=Rcpp::wrap(name[0]), 
	Rcpp::Named("gate")=Rcpp::wrap(tag_v[gpos[gpp]]),
	Rcpp::Named("gate-type")=Rcpp::wrap(gate_type),
	Rcpp::Named("children")=Rcpp::wrap(tag_v[chpos]),
	Rcpp::Named("num gates")=Rcpp::wrap(gpos.size())	
	);

return outlist;

}


// attempts to place alternate methods of finding vector positions resulted in failed builds
// not worth resolving them.
/*
std::vector<int> findGatePositions(Rcpp::IntegerVector v) {
// using Armadillo
	arma::colvec av=Rcpp::as<arma::colvec>(v);
	arma::uvec gpos_a=arma::find(av > 9);
	std::vector<int> gpos(gpos_a.begin(), gpos_a.end());
	return gpos;
}

std::vector<int> findChildPositions(Rcpp::IntegerVector v, position) {
// using Armadillo
	arma::colvec av=Rcpp::as<arma::colvec>(v);
	arma::uvec chpos_a=arma::find(av == v(position));
	std::vector<int> chpos(gpos_a.begin(), chpos_a.end());
	return chpos;
}
*/

/*
// This function would work if only intending to export the results
// It fails when the returned object is used such as in findChildPositions below
std::vector<int> findGatePositions(Rcpp::IntegerVector v) {
	std::vector<int> results;

	auto it = std::find_if(std::begin(v), std::end(v), [](int i){return i > 9;});
	while (it != std::end(v)) {
	   results.emplace_back(std::distance(std::begin(v), it));
	   it = std::find_if(std::next(it), std::end(v), [](int i){return i > 9;});
	}
	
	return results;
}

// This approach fails due to numerous instances of variables "not captured"
std::vector<int> findChildPositions(Rcpp::IntegerVector v, int position) {
	std::vector<int> results;

	auto it = std::find_if(std::begin(v), std::end(v), [](int i){return i == v(position);});
	while (it != std::end(v)) {
	   results.emplace_back(std::distance(std::begin(v), it));
	   it = std::find_if(std::next(it), std::end(v), [](int i){return i == v(position);});
	}
	
	return results;
}
*/

