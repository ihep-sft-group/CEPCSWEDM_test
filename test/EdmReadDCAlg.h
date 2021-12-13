#ifndef TEST_EDM4HEP_READ_DC_ALG_H
#define TEST_EDM4HEP_READ_DC_ALG_H

#include "k4FWCore/DataHandle.h"
#include "GaudiAlg/GaudiAlgorithm.h"
#include "cepcsw/SimPrimaryIonizationClusterCollection.h"

namespace edm4hep {
    class EventHeaderCollection;
    class MCParticleCollection;
    class SimTrackerHitCollection;
}

class EdmReadDCAlg : public GaudiAlgorithm
{

    public :

        EdmReadDCAlg(const std::string& name, ISvcLocator* svcLoc);

        virtual StatusCode initialize();
        virtual StatusCode execute();
        virtual StatusCode finalize();

    private :

        DataHandle<edm4hep::MCParticleCollection>                    m_mcParCol{"MCParticle", Gaudi::DataHandle::Reader, this};
        DataHandle<cepcsw::SimPrimaryIonizationClusterCollection>    m_SimPrimaryIonizationCol{"SimPrimaryIonizationClusterCollection", Gaudi::DataHandle::Reader, this};

};

#endif
