#include "Rscram.h"
#include "element.h"
#include "event.h"
#include "fault_tree.h"

// smart pointer attempt not used
/// modified from initializer.cc
/// Constructs Element of type T from a name string.
template <class T>
std::enable_if_t<std::is_base_of<scram::mef::Element, T>::value, std::unique_ptr<T>>
ConstructElement(std::string name) {
//  std::string name = GetAttributeValue(xml_element, "name");
  auto element = std::make_unique<T>(std::move(name));
//  AttachLabelAndAttributes(xml_element, element.get());
  return element;
}
//*/

//Rcpp namespace items are specifically called below
//using namespace Rcpp;

SEXP gate_test2(SEXP chars_in, SEXP _ints_in, SEXP _nums_in, SEXP _gpp)  {
// Unpack the "by type" argument vectors into ftree-like named Rcpp vectors
// Note: we are also recovering the name of the inputting ftree to use as fault-tree name
Rcpp::StringVector tag_v=chars_in;
int df_rows = tag_v.size()-1;
Rcpp::StringVector name[1];
name[0]=tag_v[df_rows];
std::string ftree_name=(std::string) tag_v[df_rows];
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


/// Constructing all node elements to a single array in same order as input data 
// convert tag vector from Rcpp::CharacterVector to std::vector<std::string>
std::vector<std::string> tag_sv (tag_v.begin(), tag_v.end());
int N = tag_sv.size();

std::unique_ptr<scram::mef::FaultTree> fault_tree = ConstructElement<scram::mef::FaultTree>(ftree_name);

for (int node=0; node<N; node++)  {
		
	if(type_v[node]>9) {
/// this compiles 
std::unique_ptr<scram::mef::Gate> gate = ConstructElement<scram::mef::Gate>(tag_sv[node]);	
/// this doesn't
//fault_tree->Add(gate);
	}
/*
	else if(type_v[node]<9) {
std::unique_ptr<scram::mef::BasicEvent> basic_event = ConstructElement<scram::mef::BasicEvent(tag_sv[node]);	 
//fault_tree->Add(basic_event);
/// code should continue in this block to define the expression(s) for this event
	}
	else {
std::unique_ptr<scram::mef::HouseEvent> house_event = ConstructElement<scram::mef::HouseEvent(tag_sv[node]);	 
//fault_tree->Add(house_event);		
/// code should continue here to define the value of the event
	}
*/
}

	
//nodePtrs[0] = new scram::mef::Gate(tag_sv[0]);  // !!! Potential memory leak !!!


/// Prepare for gate definitions ///
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
//		nodePtrs[gpos[gpp]]->formula = new scram::mef::Formula(static_cast<scram::mef::Operator>(7));
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
// 	Rcpp::Named("gate")=Rcpp::wrap(nodePtrs[gpos[gpp]]->name()),
// 	Rcpp::Named("gate")=Rcpp::wrap(fault_tree->[gpos[gpp]]->name()),
	Rcpp::Named("gate-type")=Rcpp::wrap(gate_type),
	Rcpp::Named("children")=Rcpp::wrap(tag_v[chpos]),
	Rcpp::Named("num gates")=Rcpp::wrap(gpos.size())	
	);

return outlist;

}




