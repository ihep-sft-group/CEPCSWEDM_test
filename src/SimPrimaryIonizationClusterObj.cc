// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "cepcsw/SimPrimaryIonizationClusterObj.h"
#include "edm4hep/MCParticleConst.h"
namespace cepcsw {

SimPrimaryIonizationClusterObj::SimPrimaryIonizationClusterObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_MCParticle(nullptr)
{  }

SimPrimaryIonizationClusterObj::SimPrimaryIonizationClusterObj(const podio::ObjectID id, SimPrimaryIonizationClusterData data) :
  ObjBase{id, 0}, data(data)
{  }

SimPrimaryIonizationClusterObj::SimPrimaryIonizationClusterObj(const SimPrimaryIonizationClusterObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_MCParticle(nullptr)
{
  if (other.m_MCParticle) {
    m_MCParticle = new ::edm4hep::ConstMCParticle(*(other.m_MCParticle));
  }
}

SimPrimaryIonizationClusterObj::~SimPrimaryIonizationClusterObj() {

  if (m_MCParticle) delete m_MCParticle;
}
} // namespace cepcsw

