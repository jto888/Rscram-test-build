#include "Rscram.h"
#include "settings.h"


//using namespace Rcpp; Rcpp namespace items are specifically called below
using namespace scram::core;

SEXP settings_test(SEXP arg1, SEXP arg2)  {
Rcpp::IntegerVector set_key=arg1;
Rcpp::NumericVector set_val=arg2;

Settings settings;

for(int i=0; i<set_key.size(); i++) {

	switch(set_key[i]) {
		
		case 0 :
		settings.algorithm(static_cast<Algorithm>((int) set_val[i]));			
		break;
		
		case 1 :
	// not intented to be called, but if it were it would look like this:
		settings.approximation(static_cast<Approximation>((int) set_val[i]));	
		break;
		
		case 2 :
	// no need to interpret Boolean values, if key is called, set to true
		settings.probability_analysis(true);
		break;
		
		case 3 :
		settings.importance_analysis(true);
		break;
		
		case 4 :
		settings.uncertainty_analysis(true);
		break;
		
		case 5 :
		settings.safety_integrity_levels(true);
		break;
		
		case 6 :
		settings.ccf_analysis(true);
		break;
		
		case 7 :
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
// Rcpp can't wrap the Algorithm or Approximation type for return confirmation, so ...
std::string report_algorithm, report_approximation;
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

return  Rcpp::List::create(Rcpp::Named("algorithm")=Rcpp::wrap(report_algorithm),	
	 Rcpp::Named("approximation")=Rcpp::wrap(report_approximation),
	 Rcpp::Named("probability_analysis")=Rcpp::wrap(settings.probability_analysis()),	
	 Rcpp::Named("importance_analysis")=Rcpp::wrap(settings.importance_analysis()),	
	 Rcpp::Named("uncertainty_analysis")=Rcpp::wrap(settings.uncertainty_analysis()),	
	 Rcpp::Named("safety_integrity_levels")=Rcpp::wrap(settings.safety_integrity_levels()),
     Rcpp::Named("ccf_analysis")=Rcpp::wrap(settings.ccf_analysis()),	 
	 Rcpp::Named("prime_implicants")=Rcpp::wrap(settings.prime_implicants()),	
	 Rcpp::Named("mission_time")=Rcpp::wrap(settings.mission_time()),	 
	 Rcpp::Named("seed")=Rcpp::wrap(settings.seed()),	
	 Rcpp::Named("num_trials")=Rcpp::wrap(settings.num_trials()),	
	 Rcpp::Named("num_bins")=Rcpp::wrap(settings.num_bins()),	
	 Rcpp::Named("num_quantiles")=Rcpp::wrap(settings.num_quantiles()),	
	 Rcpp::Named("limit_order")=Rcpp::wrap(settings.limit_order()),
	 Rcpp::Named("time_step")=Rcpp::wrap(settings.time_step()),	
	 Rcpp::Named("cut_off")=Rcpp::wrap(settings.cut_off())
	 );	
	
}