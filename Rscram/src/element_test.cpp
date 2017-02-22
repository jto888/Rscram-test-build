#include "Rscram.h"
#include "element.h"

using namespace Rcpp;
using namespace scram::mef;

SEXP element_test(SEXP arg1, SEXP arg2, SEXP arg3)  {
 Attribute my_attr;
Rcpp::StringVector valstring="value";
Rcpp::StringVector typstring="float";
 my_attr.name = as<std::string>(valstring[0]);
 my_attr.value = as<std::string>(arg2);
 my_attr.type = as<std::string>(typstring[0]);
 
 
 /*
 //What I really want to do here is construct an Element object
Element my_element=Element(as<std::string>(arg1);

// add my_attr to the new Element object
my_element.AddAttribute(my_attr);

// then return the result of HasAttribute to R
return wrap(my_element.HasAttribute(my_attr.name));

//However I am certain there is something I don't know about Element construction.
 */
 
  Attribute z_attr=my_attr;
 
// z_attr=my_attr;

return List::create(		
	Named("name")=wrap(z_attr.name),	
	Named("value")=wrap(z_attr.value),		
	Named("type")=wrap(z_attr.type)
	);	
	
}
