## importance_settings
## a test function demonstrating how functionality of FaultTree.SCRAM::scram.probability would
## generate SCRAM settings.

importance_settings<-function(mission_time=8760) {
keys<-3
vals<-1
if(mission_time!=8760) {
if(!mission_time>0) stop("mission_time must be greater than zero")
keys<-c(keys,8)
vals<-c(vals,mission_time)
}
return(test.settings(keys, vals))
}