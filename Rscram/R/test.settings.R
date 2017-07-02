test.settings<- function(set_keys, set_vals){
	.Call( "settings_test",set_keys, set_vals, PACKAGE = "Rscram" )

}