#include "Rscram.h"
#include "element.h"

// these includes were used to drive test build of header only expression sources
//#include "expression.h"
//#include "expression/constant.h"
//#include "expression/boolean.h"
//#include "expression/numerical.h"

using namespace Rcpp;
using namespace scram::mef;

SEXP attribute_test(SEXP arg1, SEXP arg2, SEXP arg3)  {
 Attribute my_attr;

 my_attr.name = as<std::string>(arg1);
 my_attr.value = as<std::string>(arg2);
 my_attr.type = as<std::string>(arg3);
 
  Attribute z_attr=my_attr;
 
// z_attr=my_attr;

return List::create(		
	Named("name")=wrap(z_attr.name),	
	Named("value")=wrap(z_attr.value),		
	Named("type")=wrap(z_attr.type)
	);	
/*
// namespace specification not required if "using namespace..." declarations are made
// but it must be assured there are no naming conflicts.

 scram::mef::Attribute my_attr;

 my_attr.name = Rcpp::as<std::string>(arg1);
 my_attr.value = Rcpp::as<std::string>(arg2);
 my_attr.type = Rcpp::as<std::string>(arg3);
 
  scram::mef::Attribute z_attr;
 
 z_attr=my_attr;

return List::create(		
	Rcpp::Named("name")=wrap(z_attr.name),	
	Rcpp::Named("value")=wrap(z_attr.value),		
	Rcpp::Named("type")=wrap(z_attr.type)
	);	
*/	
}
