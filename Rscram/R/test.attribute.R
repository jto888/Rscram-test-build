test.attribute<- function( Name, Value, Type){
	outlist<-.Call( "attribute_test", Name, as.character(Value), Type, PACKAGE = "Rscram" )
	outlist
}