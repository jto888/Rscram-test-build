## uncertainty_settings
## a test function demonstrating how functionality of FaultTree.SCRAM::scram.probability would
## generate SCRAM settings.

uncertainty_settings<-function(mission_time=8760, ntrials=1000, nbin=20) {
keys<-4
vals<-1

if(mission_time!=8760) {
if(!mission_time>0) stop("mission_time must be greater than zero")
keys<-c(keys,8)
vals<-c(vals,mission_time)
}

if(ntrials!=1000) {
if(!ntrials>0) stop("number of trials must be greater than zero")
## could warn if trials less than say 100 or so . . . 
keys<-c(keys,10)
vals<-c(vals,ceiling(ntrials))
}

if(nbin!=20) {
if(!nbin>0) stop("number of bins must be greater than zero")
## could warn if nbins less than say 10 or so . . . 
## remember this R function sets both num_bins and num_quantiles the same
keys<-c(keys,11,12)
vals<-c(vals,ceiling(nbin),ceiling(nbin))
}

return(test.settings(keys, vals))
}