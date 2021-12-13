// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_SimPrimaryIonizationClusterDATA_H
#define cepcsw_SimPrimaryIonizationClusterDATA_H

#include "edm4hep/Vector3d.h"

namespace cepcsw {


/** @class SimPrimaryIonizationClusterData
 *  Simulated Primary Ionization
 *  @author: Wenxing Fang, IHEP
 */
class SimPrimaryIonizationClusterData {
public:
  unsigned long long cellID; ///< ID of the sensor that created this hit
  int size; ///< number of electrons created by this primary ionization.
  float time; ///< proper time of the hit in the lab frame in [ns].
  int type; ///< type.
  ::edm4hep::Vector3d position; ///< the hit position in [mm].

};

} // namespace cepcsw


#endif
