// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_ConstSimPrimaryIonizationCluster_H
#define cepcsw_ConstSimPrimaryIonizationCluster_H

#include "cepcsw/SimPrimaryIonizationClusterObj.h"

#include "edm4hep/Vector3d.h"
#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class MCParticle;
class ConstMCParticle;
}


namespace cepcsw {


class SimPrimaryIonizationCluster;
class SimPrimaryIonizationClusterCollection;
class SimPrimaryIonizationClusterCollectionIterator;

/** @class ConstSimPrimaryIonizationCluster
 *  Simulated Primary Ionization
 *  @author: Wenxing Fang, IHEP
 */
class ConstSimPrimaryIonizationCluster {

  friend SimPrimaryIonizationCluster;
  friend SimPrimaryIonizationClusterCollection;
  friend SimPrimaryIonizationClusterCollectionIterator;

public:
  /// default constructor
  ConstSimPrimaryIonizationCluster();
  ConstSimPrimaryIonizationCluster(unsigned long long cellID, int size, float time, int type, edm4hep::Vector3d position);

  /// constructor from existing SimPrimaryIonizationClusterObj
  ConstSimPrimaryIonizationCluster(SimPrimaryIonizationClusterObj* obj);

  /// copy constructor
  ConstSimPrimaryIonizationCluster(const ConstSimPrimaryIonizationCluster& other);

  /// copy-assignment operator
  ConstSimPrimaryIonizationCluster& operator=(const ConstSimPrimaryIonizationCluster& other);

  /// support cloning (deep-copy)
  ConstSimPrimaryIonizationCluster clone() const;

  /// destructor
  ~ConstSimPrimaryIonizationCluster();


public:

  /// Access the ID of the sensor that created this hit
  const unsigned long long& getCellID() const;

  /// Access the number of electrons created by this primary ionization.
  const int& getSize() const;

  /// Access the proper time of the hit in the lab frame in [ns].
  const float& getTime() const;

  /// Access the type.
  const int& getType() const;

  /// Access the the hit position in [mm].
  const edm4hep::Vector3d& getPosition() const;


  /// Access the MCParticle that caused the hit.
  const ::edm4hep::ConstMCParticle getMCParticle() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimPrimaryIonizationClusterObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstSimPrimaryIonizationCluster& other) const { return m_obj == other.m_obj; }
  bool operator==(const SimPrimaryIonizationCluster& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstSimPrimaryIonizationCluster& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimPrimaryIonizationClusterObj* m_obj;
};

} // namespace cepcsw


#endif
