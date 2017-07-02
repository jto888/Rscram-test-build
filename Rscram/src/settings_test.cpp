#include "Rscram.h"
#include "settings.h"


using namespace Rcpp;
using namespace scram::core;

SEXP settings_test(SEXP arg1, SEXP arg2)  {
//cast in switch would not be required if algorithm is taken as IntegerVector
IntegerVector set_key=arg1;
NumericVector set_val=arg2;
std::string set_algorithm, set_approximation;
// Rcpp can't wrap the Algorithm or Approximation type for return confirmation, so ...
std::string report_algorithm, report_approximation;

Settings settings;
for(int i=0; i<set_key.size(); i++) {

	switch(set_key[i]) {
		
		case 0 :
		switch((int) set_val[i]) {
			
			case 0 :
			set_algorithm="bdd";
			break;
			
			case 1 :
			set_algorithm="zbdd";
			break;
			
			case 2 :
			set_algorithm="mocus";
			break;
			
			default :
			set_algorithm="bdd";
		}
	// algorithm can be set with a string thanks to helpful wrapper function
		settings.algorithm(set_algorithm);
		// cannot set just from int value, this fails:
		//settings.algorithm((int) set_val[i]);
		break;
		
		case 1 :
	// not intented to be called, but if it were it would look like this:
	/*	
		switch((int) set_val[i]) {
			case 0 :
			set_approximation="none";
			break;
			
			case 1 :
			set_approximation="rare event";
			break;
			
			case 2 :
			set_approximation="mcub";
			break;
			
			default :
			set_approximation="none";
		}
		settings.approximation(set_approximation);		
	*/
	// instead, do nothing
		break;
		
		case 2 :
	// no need to interpret value, if key is called, set to true
		settings.probability_analysis(true);
		break;
		
		case 3 :
	// no need to interpret value, if key is called, set to true
		settings.importance_analysis(true);
		break;
		
		case 4 :
	// no need to interpret value, if key is called, set to true
		settings.uncertainty_analysis(true);
		break;
		
		case 5 :
	// no need to interpret value, if key is called, set to true
		settings.safety_integrity_levels(true);
		break;
		
		case 6 :
	// no need to interpret value, if key is called, set to true
		settings.ccf_analysis(true);
		break;
		
		case 7 :
	// no need to interpret value, if key is called, set to true
		settings.prime_implicants(true);
		break;
		
		case 8 :
		 settings.mission_time((double) set_val[i]);
		 break;
		
		case 9 :
		 settings.seed((int) set_val[i]);
		 break;	 
		
		case 10 :
		 settings.num_trials((int) set_val[i]);
		 break;	
		
		case 11 :
		 settings.num_bins((int) set_val[i]);
		 break;	 
		
		case 12 :
		 settings.num_quantiles((int) set_val[i]);
		 break;	
		
		case 13 :
		 settings.limit_order((int) set_val[i]);
		 break;		 
		
		case 14 :
		 settings.time_step((double) set_val[i]);
		 break;	
		
		case 15 :
		 settings.cut_off((double) set_val[i]);
		 break;	
	}

}

// Prepare for return object
switch(settings.algorithm()) {
	
	case Algorithm::kBdd :
	report_algorithm="bdd";
	break;
	
	case Algorithm::kZbdd :
	report_algorithm="zbdd";
	break;
	
	case Algorithm::kMocus :
	report_algorithm="mocus";
	break;
	
	default:
	report_algorithm="unknown";
}
switch(settings.approximation()) {
	
	case Approximation::kNone :
	report_approximation="none";
	break;
	
	case Approximation::kRareEvent :
	report_approximation="rare event";
	break;
	
	case Approximation::kMcub :
	report_approximation="mcub";
	break;
	
	default:
	report_approximation="unknown";
}

return  Rcpp::List::create(Rcpp::Named("algorithm")=wrap(report_algorithm),	
	 Rcpp::Named("approximation")=wrap(report_approximation),
	 Rcpp::Named("probability_analysis")=wrap(settings.probability_analysis()),	
	 Rcpp::Named("importance_analysis")=wrap(settings.importance_analysis()),	
	 Rcpp::Named("uncertainty_analysis")=wrap(settings.uncertainty_analysis()),	
	 Rcpp::Named("safety_integrity_levels")=wrap(settings.safety_integrity_levels()),
     Rcpp::Named("ccf_analysis")=wrap(settings.ccf_analysis()),	 
	 Rcpp::Named("prime_implicants")=wrap(settings.prime_implicants()),	
	 Rcpp::Named("mission_time")=wrap(settings.mission_time()),	 
	 Rcpp::Named("seed")=wrap(settings.seed()),	
	 Rcpp::Named("num_trials")=wrap(settings.num_trials()),	
	 Rcpp::Named("num_bins")=wrap(settings.num_bins()),	
	 Rcpp::Named("num_quantiles")=wrap(settings.num_quantiles()),	
	 Rcpp::Named("limit_order")=wrap(settings.limit_order()),
	 Rcpp::Named("time_step")=wrap(settings.time_step()),	
	 Rcpp::Named("cut_off")=wrap(settings.cut_off())
	 );	

	
}