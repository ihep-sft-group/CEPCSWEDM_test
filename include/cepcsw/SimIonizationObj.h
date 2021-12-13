// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_SimIonizationOBJ_H
#define cepcsw_SimIonizationOBJ_H

// data model specific includes
#include "cepcsw/SimIonizationData.h"

#include "podio/ObjBase.h"

// forward declarations
namespace edm4hep {
class ConstMCParticle;
}
namespace cepcsw {
class ConstSimPrimaryIonizationCluster;
}


namespace cepcsw {

class SimIonization;
class ConstSimIonization;

class SimIonizationObj : public podio::ObjBase {
public:
  /// constructor
  SimIonizationObj();
  /// copy constructor (does a deep-copy of relation containers)
  SimIonizationObj(const SimIonizationObj&);
  /// constructor from ObjectID and SimIonizationData
  /// does not initialize the internal relation containers
  SimIonizationObj(const podio::ObjectID id, SimIonizationData data);
  virtual ~SimIonizationObj();

public:
  SimIonizationData data;
  ::edm4hep::ConstMCParticle* m_MCParticle;
  ::cepcsw::ConstSimPrimaryIonizationCluster* m_PrimaryIonization;
};

} // namespace cepcsw


#endif
