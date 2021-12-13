// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_ConstSimIonization_H
#define cepcsw_ConstSimIonization_H

#include "cepcsw/SimIonizationObj.h"

#include "edm4hep/Vector3d.h"
#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class MCParticle;
class ConstMCParticle;
}
namespace cepcsw {
class SimPrimaryIonizationCluster;
class ConstSimPrimaryIonizationCluster;
}


namespace cepcsw {


class SimIonization;
class SimIonizationCollection;
class SimIonizationCollectionIterator;

/** @class ConstSimIonization
 *  Simulated Ionization
 *  @author: Wenxing Fang, IHEP
 */
class ConstSimIonization {

  friend SimIonization;
  friend SimIonizationCollection;
  friend SimIonizationCollectionIterator;

public:
  /// default constructor
  ConstSimIonization();
  ConstSimIonization(unsigned long long cellID, float time, int type, edm4hep::Vector3d position);

  /// constructor from existing SimIonizationObj
  ConstSimIonization(SimIonizationObj* obj);

  /// copy constructor
  ConstSimIonization(const ConstSimIonization& other);

  /// copy-assignment operator
  ConstSimIonization& operator=(const ConstSimIonization& other);

  /// support cloning (deep-copy)
  ConstSimIonization clone() const;

  /// destructor
  ~ConstSimIonization();


public:

  /// Access the ID of the sensor that created this hit
  const unsigned long long& getCellID() const;

  /// Access the proper time of the hit in the lab frame in [ns].
  const float& getTime() const;

  /// Access the type.
  const int& getType() const;

  /// Access the the hit position in [mm].
  const edm4hep::Vector3d& getPosition() const;


  /// Access the MCParticle that caused the Ionization.
  const ::edm4hep::ConstMCParticle getMCParticle() const;
  /// Access the PrimaryIonization that caused the Ionization.
  const ::cepcsw::ConstSimPrimaryIonizationCluster getPrimaryIonization() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimIonizationObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstSimIonization& other) const { return m_obj == other.m_obj; }
  bool operator==(const SimIonization& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstSimIonization& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimIonizationObj* m_obj;
};

} // namespace cepcsw


#endif
