test.scaffold<-function(DF)  {
  if(!FaultTree::test.ftree(DF)) stop("first argument must be a fault tree")
  
  DFname<-paste(deparse(substitute(DF)))
  
  cpp_args<-ftree2cpp(DF,DFname)
  ##cpp_args

outdf<-.Call( "scaffold_test", cpp_args[[1]], cpp_args[[2]], cpp_args[[3]], PACKAGE = "Rscram" )
outdf 


}