#!/usr/bin/env python

from Gaudi.Configuration import *

from Configurables import k4DataSvc
dsvc = k4DataSvc("EventDataSvc")

from Configurables import EdmWriteDCAlg
alg = EdmWriteDCAlg("EdmWriteDCAlg")

from Configurables import PodioOutput
out = PodioOutput("out")
out.filename = "test_edm.root"
out.outputCommands = ["keep *"]

# ApplicationMgr
from Configurables import ApplicationMgr
ApplicationMgr( TopAlg = [alg, out],
                EvtSel = 'NONE',
                EvtMax = 2,
                ExtSvc=[dsvc],
                OutputLevel=DEBUG
)
