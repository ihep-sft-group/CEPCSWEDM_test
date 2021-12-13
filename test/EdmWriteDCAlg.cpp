#include "EdmWriteDCAlg.h"
#include "edm4hep/EventHeaderCollection.h"
#include "edm4hep/MCParticleCollection.h"

DECLARE_COMPONENT(EdmWriteDCAlg)

EdmWriteDCAlg::EdmWriteDCAlg(const std::string& name, ISvcLocator* svcLoc)
    : GaudiAlgorithm(name, svcLoc)
{
}

StatusCode EdmWriteDCAlg::initialize()
{
    debug() << "begin initialize EdmWriteDCAlg" << endmsg;
    return GaudiAlgorithm::initialize();
}

StatusCode EdmWriteDCAlg::execute()
{
    debug() << "begin execute EdmWriteDCAlg" << endmsg;

    auto mcCol = m_mcParCol.createAndPut();
    auto simCol = m_SimPrimaryIonizationCol.createAndPut();

    auto p1 = mcCol->create();
    auto p2 = mcCol->create();

    for ( int i = 0; i < 4; ++i ) {
        auto d = mcCol->create();
        d.addToParents(p1);
        d.addToParents(p2);
        p1.addToDaughters(d);
        p2.addToDaughters(d);

        auto ionization = simCol->create();
        ionization.setMCParticle(d);
    }

    return StatusCode::SUCCESS;
}

StatusCode EdmWriteDCAlg::finalize()
{
    debug() << "begin finalize EdmWriteDCAlg" << endmsg;
    return GaudiAlgorithm::finalize();
}
