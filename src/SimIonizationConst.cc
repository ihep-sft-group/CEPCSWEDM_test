// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "cepcsw/SimIonization.h"
#include "cepcsw/SimIonizationConst.h"
#include "cepcsw/SimIonizationObj.h"
#include "cepcsw/SimIonizationData.h"
#include "cepcsw/SimIonizationCollection.h"

#include "edm4hep/MCParticle.h"
#include "cepcsw/SimPrimaryIonizationCluster.h"

#include <ostream>

namespace cepcsw {


ConstSimIonization::ConstSimIonization() : m_obj(new SimIonizationObj()) {
  m_obj->acquire();
}

ConstSimIonization::ConstSimIonization(unsigned long long cellID, float time, int type, edm4hep::Vector3d position) : m_obj(new SimIonizationObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.time = time;
  m_obj->data.type = type;
  m_obj->data.position = position;
}

ConstSimIonization::ConstSimIonization(const ConstSimIonization& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstSimIonization& ConstSimIonization::operator=(const ConstSimIonization& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstSimIonization::ConstSimIonization( SimIonizationObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstSimIonization ConstSimIonization::clone() const {
  return {new SimIonizationObj(*m_obj)};
}

ConstSimIonization::~ConstSimIonization() {
  if (m_obj) m_obj->release();
}
const unsigned long long& ConstSimIonization::getCellID() const { return m_obj->data.cellID; }
const float& ConstSimIonization::getTime() const { return m_obj->data.time; }
const int& ConstSimIonization::getType() const { return m_obj->data.type; }
const edm4hep::Vector3d& ConstSimIonization::getPosition() const { return m_obj->data.position; }

const edm4hep::ConstMCParticle ConstSimIonization::getMCParticle() const {
  if (!m_obj->m_MCParticle) {
    return edm4hep::ConstMCParticle(nullptr);
  }
  return edm4hep::ConstMCParticle(*(m_obj->m_MCParticle));
}

const ConstSimPrimaryIonizationCluster ConstSimIonization::getPrimaryIonization() const {
  if (!m_obj->m_PrimaryIonization) {
    return cepcsw::ConstSimPrimaryIonizationCluster(nullptr);
  }
  return cepcsw::ConstSimPrimaryIonizationCluster(*(m_obj->m_PrimaryIonization));
}






bool ConstSimIonization::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstSimIonization::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstSimIonization::operator==(const SimIonization& other) const {
  return m_obj == other.m_obj;
}

} // namespace cepcsw

