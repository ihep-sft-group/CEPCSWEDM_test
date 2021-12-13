// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_SimIonization_H
#define cepcsw_SimIonization_H

#include "cepcsw/SimIonizationConst.h"
#include "cepcsw/SimIonizationObj.h"

#include "edm4hep/Vector3d.h"
#include "podio/ObjectID.h"
#include <ostream>

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


class SimIonizationCollection;
class SimIonizationCollectionIterator;
class ConstSimIonization;

/** @class SimIonization
 *  Simulated Ionization
 *  @author: Wenxing Fang, IHEP
 */
class SimIonization {

  friend SimIonizationCollection;
  friend SimIonizationCollectionIterator;
  friend ConstSimIonization;

public:

  /// default constructor
  SimIonization();
  SimIonization(unsigned long long cellID, float time, int type, edm4hep::Vector3d position);

  /// constructor from existing SimIonizationObj
  SimIonization(SimIonizationObj* obj);

  /// copy constructor
  SimIonization(const SimIonization& other);

  /// copy-assignment operator
  SimIonization& operator=(const SimIonization& other);

  /// support cloning (deep-copy)
  SimIonization clone() const;

  /// destructor
  ~SimIonization();

  /// conversion to const object
  operator ConstSimIonization() const;

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

  /// Set the ID of the sensor that created this hit
  void setCellID(unsigned long long value);

  /// Set the proper time of the hit in the lab frame in [ns].
  void setTime(float value);

  /// Set the type.
  void setType(int value);

  /// Set the the hit position in [mm].
  void setPosition(edm4hep::Vector3d value);
  /// Get reference to the hit position in [mm].
  edm4hep::Vector3d& position();


  /// Set the MCParticle that caused the Ionization.
  void setMCParticle(::edm4hep::ConstMCParticle value);
  /// Set the PrimaryIonization that caused the Ionization.
  void setPrimaryIonization(::cepcsw::ConstSimPrimaryIonizationCluster value);




  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimIonizationObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const SimIonization& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstSimIonization& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const SimIonization& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimIonizationObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstSimIonization& value);

} // namespace cepcsw


#endif
