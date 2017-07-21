test.gates<-function(DF)  {
  if(!FaultTree::test.ftree(DF)) stop("first argument must be a fault tree")
  
  DFname<-paste(deparse(substitute(DF)))
  ##cpp_args
  cpp_args<-ftree2cpp(DF,DFname)
  next_pos<-0L
  num_gates<-1L
 
  
	  while(next_pos < num_gates) {
	  
	  gate_info<-.Call( "gate_test", cpp_args[[1]], cpp_args[[2]], cpp_args[[3]], next_pos, PACKAGE = "Rscram" )
		
	  	  if(next_pos==0) {
		  num_gates<-gate_info[[5]]
		  listout<-list("fault-tree-name"=gate_info[[1]], list("gate"=gate_info[[2]], "gate-type"=gate_info[[3]], "children"=gate_info[[4]]))
		  
			next_pos<-next_pos+1L
		  }else{
		  listout<-c(listout,list("gate"=gate_info[[2]], "gate-type"=gate_info[[3]], "children"=gate_info[[4]]))
		  next_pos<-next_pos+1L
	  }
  

  }
  
  
  
  listout
  
  }
  
  
