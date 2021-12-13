#ifndef TEST_EDM4HEP_WRITE_ALG_H
#define TEST_EDM4HEP_WRITE_ALG_H

#include "k4FWCore/DataHandle.h"
#include "GaudiAlg/GaudiAlgorithm.h"
#include "cepcsw/SimPrimaryIonizationClusterCollection.h"

namespace edm4hep {
    class MCParticleCollection;
}

class EdmWriteDCAlg : public GaudiAlgorithm
{

    public :

        EdmWriteDCAlg(const std::string& name, ISvcLocator* svcLoc);

        virtual StatusCode initialize();
        virtual StatusCode execute();
        virtual StatusCode finalize();

    private :

        DataHandle<edm4hep::MCParticleCollection> m_mcParCol{"MCParticle", Gaudi::DataHandle::Writer, this};
        DataHandle<cepcsw::SimPrimaryIonizationClusterCollection>    m_SimPrimaryIonizationCol{"SimPrimaryIonizationClusterCollection", Gaudi::DataHandle::Writer, this};
};

#endif  // TEST_EDM4HEP_WRITE_ALG_H
