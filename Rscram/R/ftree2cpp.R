## ftree2cpp
## initial demonstration of scaffolding from FaultTree on R to SCRAM core
##
ftree2cpp<-function(DF) {
  if(!FaultTree::test.ftree(DF)) stop("first argument must be a fault tree")

## test that there are no empty gates, all tree leaves must be basic component events
## Identify gates and events by ID
	gids<-DF$ID[which(DF$Type>9)]
	pids<-DF$CParent
	if(length(setdiff(gids, pids))>0) {
	stop(paste0("no children at gate(s) ID= ", setdiff(gids, pids)))
	}

	if(any(DF$Type==13) || any(DF$Type==15)) {
	stop("ALARM, and VOTE gates are not implemented for SCRAM calls")
	}
	if(any(DF$Type==14) ) {
	warning("PRIORITY gates are implemented as AND gates in SCRAM calls")
	}
	if(any(DF$Type==3)) {
	stop("Pure Demand event not implemented for SCRAM calls")
	}
##  issue warning if default tags must be issued.
	if(any(DF$Tag[which(DF$Type<9)]=="")) {
	warning("Not all basic-events have tags, defaults applied")
	}

## Validate mission_time setting for application of Active or Latent events
	mt<-DF$P2[which(DF$ID==min(DF$ID))]
	if(!mt>0 && (any(DF$Type==1) || any(DF$Type==2))) {
		warning("mission_time not avaliable for application on Active or Latent events, SCRAM default has been applied")
	}
## This warning should never be seen Note: DF$Type==5 with DF$EType==1 might have exposure time override
	if(!mt>0 && any(DF$Type==5)) {
		warning("mission_time not avaliable for exposed events, SCRAM default has been applied")
	}

##  DF might be the DF object within the scram.cutsets environment
## in that event the DFname must be provided
 hold_name<-paste(deparse(substitute(DF)))
  #if(DFname=="") {
## test and fail if hold_name=="DF" while no DFname provided
    #if(hold_name=="DF"){
      #stop("must provide DFname as an argument in any do.call function as done in scram.cutsets")
    #}else{
        DFname<-hold_name
    #}
  #}

## must assure that all tags are filled with unique strings
## MOE/MOB elements and gates must use source tags 
if(any(DF$Tag=="")) {
	blank_tags<-which(DF$Tag=="")
	for(df_row in blank_tags) {
## MOE sources are designated -1, while no MOE involvement designated as 0
		if(DF$MOE[df_row]<1) {		
			if(DF$Type[df_row]>9) {
				DF$Tag[df_row]=paste0("G_",DF$ID[df_row])
			}else{	
				if(DF$Type[df_row]==9) {
					DF$Tag[df_row]=paste0("H_",DF$ID[df_row])
				}else{
					DF$Tag[df_row]=paste0("E_",DF$ID[df_row])
				}
			}		
		}else{
## now need the else block for MOE/MOB
			DF$Tag[df_row]=DF$Tag[which(DF$ID==DF$MOE[df_row])]
		}
	}
}

char_vec<-c(DF$Tag, DFname)
int_vec<-c(DF$ID, DF$Type, DF$MOE, DF$EType, DF$CParent, DF$UType)
num_vec<-c(DF$CFR, DF$PBF, DF$CRT, DF$P1, DF$P2, DF$UP1, DF$UP2)

outdf<-.Call( "scaffold_test", char_vec, int_vec, num_vec, PACKAGE = "rscram" )
outdf 

}