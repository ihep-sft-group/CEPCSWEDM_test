#!/usr/bin/env python

from Gaudi.Configuration import *

from Configurables import k4DataSvc
dsvc = k4DataSvc("EventDataSvc",
                  #input="test_edm.root"
                  #input="test_ag.root"
                  input="test_ag_nomcsaved.root"
)

from Configurables import PodioInput
podioinput = PodioInput("PodioReader", collections=[
    "MCParticle",
    "SimPrimaryIonizationClusterCollection"
    ])

from Configurables import EdmReadDCAlg
alg = EdmReadDCAlg("EdmReadDCAlg")

# ApplicationMgr
from Configurables import ApplicationMgr
ApplicationMgr( TopAlg = [podioinput, alg],
                EvtSel = 'NONE',
                EvtMax = -1,
                ExtSvc = [dsvc],
                OutputLevel=DEBUG
)
