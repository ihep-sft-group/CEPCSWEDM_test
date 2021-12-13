// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_SimPrimaryIonizationClusterOBJ_H
#define cepcsw_SimPrimaryIonizationClusterOBJ_H

// data model specific includes
#include "cepcsw/SimPrimaryIonizationClusterData.h"

#include "podio/ObjBase.h"

// forward declarations
namespace edm4hep {
class ConstMCParticle;
}


namespace cepcsw {

class SimPrimaryIonizationCluster;
class ConstSimPrimaryIonizationCluster;

class SimPrimaryIonizationClusterObj : public podio::ObjBase {
public:
  /// constructor
  SimPrimaryIonizationClusterObj();
  /// copy constructor (does a deep-copy of relation containers)
  SimPrimaryIonizationClusterObj(const SimPrimaryIonizationClusterObj&);
  /// constructor from ObjectID and SimPrimaryIonizationClusterData
  /// does not initialize the internal relation containers
  SimPrimaryIonizationClusterObj(const podio::ObjectID id, SimPrimaryIonizationClusterData data);
  virtual ~SimPrimaryIonizationClusterObj();

public:
  SimPrimaryIonizationClusterData data;
  ::edm4hep::ConstMCParticle* m_MCParticle;
};

} // namespace cepcsw


#endif
