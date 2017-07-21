mission_time=8760
SmallTree<-ftree.make(type="or", label="SmallTree MEF Example")
SmallTree<-addLogic(SmallTree, at="top", type="and", tag="g1", label="Gate 1")
SmallTree<-addExposed(SmallTree, at="g1", dist="exponential", mttf=1/2.0e-5, tag="e1", label="Element 1")
SmallTree<-addExposed(SmallTree, at="g1", dist="exponential", mttf=1/1.0e-5, tag="e2", label="Element 2")
SmallTree<-addLogic(SmallTree, at="top", type="and", tag="g2", label="Gate 2")
SmallTree<-addExposed(SmallTree, at="g2", dist="exponential", mttf=1/2.0e-5, tag="e3", label="Element 3")
SmallTree<-addExposed(SmallTree, at="g2", dist="exponential", mttf=1/1.0e-5, tag="e4", label="Element 4")
