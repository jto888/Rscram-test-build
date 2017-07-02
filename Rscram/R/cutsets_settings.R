## this is a test function to demonstrate how SCRAM settings would be made for typical
## arguments to the FaultTree.SCRAM::scram.cutsets function.

cutsets_settings<-function(method="mocus") {
keys<-0
vals<-switch(method,
	bdd=0,
	zbdd=1,
	mocus=2)
return(test.settings(keys,vals))
}