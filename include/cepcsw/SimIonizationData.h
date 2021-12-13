// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_SimIonizationDATA_H
#define cepcsw_SimIonizationDATA_H

#include "edm4hep/Vector3d.h"

namespace cepcsw {


/** @class SimIonizationData
 *  Simulated Ionization
 *  @author: Wenxing Fang, IHEP
 */
class SimIonizationData {
public:
  unsigned long long cellID; ///< ID of the sensor that created this hit
  float time; ///< proper time of the hit in the lab frame in [ns].
  int type; ///< type.
  ::edm4hep::Vector3d position; ///< the hit position in [mm].

};

} // namespace cepcsw


#endif
