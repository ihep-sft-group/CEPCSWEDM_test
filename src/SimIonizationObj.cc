// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "cepcsw/SimIonizationObj.h"
#include "edm4hep/MCParticleConst.h"
#include "cepcsw/SimPrimaryIonizationClusterConst.h"
namespace cepcsw {

SimIonizationObj::SimIonizationObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_MCParticle(nullptr),
  m_PrimaryIonization(nullptr)
{  }

SimIonizationObj::SimIonizationObj(const podio::ObjectID id, SimIonizationData data) :
  ObjBase{id, 0}, data(data)
{  }

SimIonizationObj::SimIonizationObj(const SimIonizationObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_MCParticle(nullptr),
  m_PrimaryIonization(nullptr)
{
  if (other.m_MCParticle) {
    m_MCParticle = new ::edm4hep::ConstMCParticle(*(other.m_MCParticle));
  }
  if (other.m_PrimaryIonization) {
    m_PrimaryIonization = new ::cepcsw::ConstSimPrimaryIonizationCluster(*(other.m_PrimaryIonization));
  }
}

SimIonizationObj::~SimIonizationObj() {

  if (m_MCParticle) delete m_MCParticle;
  if (m_PrimaryIonization) delete m_PrimaryIonization;
}
} // namespace cepcsw

