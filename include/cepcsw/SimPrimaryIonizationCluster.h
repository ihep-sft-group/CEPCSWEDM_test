// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_SimPrimaryIonizationCluster_H
#define cepcsw_SimPrimaryIonizationCluster_H

#include "cepcsw/SimPrimaryIonizationClusterConst.h"
#include "cepcsw/SimPrimaryIonizationClusterObj.h"

#include "edm4hep/Vector3d.h"
#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class MCParticle;
class ConstMCParticle;
}


namespace cepcsw {


class SimPrimaryIonizationClusterCollection;
class SimPrimaryIonizationClusterCollectionIterator;
class ConstSimPrimaryIonizationCluster;

/** @class SimPrimaryIonizationCluster
 *  Simulated Primary Ionization
 *  @author: Wenxing Fang, IHEP
 */
class SimPrimaryIonizationCluster {

  friend SimPrimaryIonizationClusterCollection;
  friend SimPrimaryIonizationClusterCollectionIterator;
  friend ConstSimPrimaryIonizationCluster;

public:

  /// default constructor
  SimPrimaryIonizationCluster();
  SimPrimaryIonizationCluster(unsigned long long cellID, int size, float time, int type, edm4hep::Vector3d position);

  /// constructor from existing SimPrimaryIonizationClusterObj
  SimPrimaryIonizationCluster(SimPrimaryIonizationClusterObj* obj);

  /// copy constructor
  SimPrimaryIonizationCluster(const SimPrimaryIonizationCluster& other);

  /// copy-assignment operator
  SimPrimaryIonizationCluster& operator=(const SimPrimaryIonizationCluster& other);

  /// support cloning (deep-copy)
  SimPrimaryIonizationCluster clone() const;

  /// destructor
  ~SimPrimaryIonizationCluster();

  /// conversion to const object
  operator ConstSimPrimaryIonizationCluster() const;

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

  /// Set the ID of the sensor that created this hit
  void setCellID(unsigned long long value);

  /// Set the number of electrons created by this primary ionization.
  void setSize(int value);

  /// Set the proper time of the hit in the lab frame in [ns].
  void setTime(float value);

  /// Set the type.
  void setType(int value);

  /// Set the the hit position in [mm].
  void setPosition(edm4hep::Vector3d value);
  /// Get reference to the hit position in [mm].
  edm4hep::Vector3d& position();


  /// Set the MCParticle that caused the hit.
  void setMCParticle(::edm4hep::ConstMCParticle value);




  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimPrimaryIonizationClusterObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const SimPrimaryIonizationCluster& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstSimPrimaryIonizationCluster& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const SimPrimaryIonizationCluster& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimPrimaryIonizationClusterObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstSimPrimaryIonizationCluster& value);

} // namespace cepcsw


#endif
