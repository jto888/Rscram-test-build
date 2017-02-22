test.element<- function( Name, Value, Type){
	outlist<-.Call( "element_test", Name, as.character(Value), Type, PACKAGE = "Rscram" )
	outlist
}