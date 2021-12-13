// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "cepcsw/SimPrimaryIonizationCluster.h"
#include "cepcsw/SimPrimaryIonizationClusterConst.h"
#include "cepcsw/SimPrimaryIonizationClusterObj.h"
#include "cepcsw/SimPrimaryIonizationClusterData.h"
#include "cepcsw/SimPrimaryIonizationClusterCollection.h"

#include "edm4hep/MCParticle.h"

#include <ostream>

namespace cepcsw {


ConstSimPrimaryIonizationCluster::ConstSimPrimaryIonizationCluster() : m_obj(new SimPrimaryIonizationClusterObj()) {
  m_obj->acquire();
}

ConstSimPrimaryIonizationCluster::ConstSimPrimaryIonizationCluster(unsigned long long cellID, int size, float time, int type, edm4hep::Vector3d position) : m_obj(new SimPrimaryIonizationClusterObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.size = size;
  m_obj->data.time = time;
  m_obj->data.type = type;
  m_obj->data.position = position;
}

ConstSimPrimaryIonizationCluster::ConstSimPrimaryIonizationCluster(const ConstSimPrimaryIonizationCluster& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstSimPrimaryIonizationCluster& ConstSimPrimaryIonizationCluster::operator=(const ConstSimPrimaryIonizationCluster& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstSimPrimaryIonizationCluster::ConstSimPrimaryIonizationCluster( SimPrimaryIonizationClusterObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstSimPrimaryIonizationCluster ConstSimPrimaryIonizationCluster::clone() const {
  return {new SimPrimaryIonizationClusterObj(*m_obj)};
}

ConstSimPrimaryIonizationCluster::~ConstSimPrimaryIonizationCluster() {
  if (m_obj) m_obj->release();
}
const unsigned long long& ConstSimPrimaryIonizationCluster::getCellID() const { return m_obj->data.cellID; }
const int& ConstSimPrimaryIonizationCluster::getSize() const { return m_obj->data.size; }
const float& ConstSimPrimaryIonizationCluster::getTime() const { return m_obj->data.time; }
const int& ConstSimPrimaryIonizationCluster::getType() const { return m_obj->data.type; }
const edm4hep::Vector3d& ConstSimPrimaryIonizationCluster::getPosition() const { return m_obj->data.position; }

const edm4hep::ConstMCParticle ConstSimPrimaryIonizationCluster::getMCParticle() const {
  if (!m_obj->m_MCParticle) {
    return edm4hep::ConstMCParticle(nullptr);
  }
  return edm4hep::ConstMCParticle(*(m_obj->m_MCParticle));
}






bool ConstSimPrimaryIonizationCluster::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstSimPrimaryIonizationCluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstSimPrimaryIonizationCluster::operator==(const SimPrimaryIonizationCluster& other) const {
  return m_obj == other.m_obj;
}

} // namespace cepcsw

