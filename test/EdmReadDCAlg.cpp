#include "EdmReadDCAlg.h"
#include "edm4hep/MCParticleCollection.h"

DECLARE_COMPONENT(EdmReadDCAlg)

EdmReadDCAlg::EdmReadDCAlg(const std::string& name, ISvcLocator* svcLoc)
    : GaudiAlgorithm(name, svcLoc)
{
    declareProperty("MCParticleCol", m_mcParCol, "MCParticle collection (input)");
}

StatusCode EdmReadDCAlg::initialize()
{
    debug() << "begin initialize EdmReadDCAlg" << endmsg;
    return GaudiAlgorithm::initialize();
}

StatusCode EdmReadDCAlg::execute()
{
    debug() << "begin execute EdmReadDCAlg" << endmsg;

    auto mcCol = m_mcParCol.get();
    for ( auto p : *mcCol ) {
        info() << p.getObjectID().index<<",pdg="<<p.getPDG() << " : [";
        for ( auto it = p.daughters_begin(), end = p.daughters_end(); it != end; ++it ) {
            info() << " " << it->getObjectID().index;
        }
        info() << " ]; ";
    }
    info() << "}" << endmsg;
    auto simPrimaryCol = m_SimPrimaryIonizationCol.get();
    info() << "simPrimaryCol="<<simPrimaryCol<< endmsg;
    for (auto simprimaryhit : *simPrimaryCol) {
        auto position = simprimaryhit.getPosition();
        info() << "SimPrimaryIonization cellID: " << simprimaryhit.getCellID()
               << " position: ("
               << position[0] << ", " << position[1] << ", " << position[2]
               << ")"
               << endmsg;
        auto tmp_mc  = simprimaryhit.getMCParticle();
        info() << "is mc obj avaliable="<<tmp_mc.isAvailable()<< endmsg;
        info() << "mc obj id: " << tmp_mc.getObjectID().index<< endmsg;
        info() << "mc obj pdg: " << tmp_mc.getPDG()<< endmsg;
    }

    return StatusCode::SUCCESS;
}

StatusCode EdmReadDCAlg::finalize()
{
    debug() << "begin finalize EdmReadDCAlg" << endmsg;
    return GaudiAlgorithm::finalize();
}
