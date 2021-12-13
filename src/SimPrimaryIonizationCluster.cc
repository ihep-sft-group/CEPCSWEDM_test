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


SimPrimaryIonizationCluster::SimPrimaryIonizationCluster() : m_obj(new SimPrimaryIonizationClusterObj()) {
  m_obj->acquire();
}

SimPrimaryIonizationCluster::SimPrimaryIonizationCluster(unsigned long long cellID, int size, float time, int type, edm4hep::Vector3d position) : m_obj(new SimPrimaryIonizationClusterObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.size = size;
  m_obj->data.time = time;
  m_obj->data.type = type;
  m_obj->data.position = position;
}

SimPrimaryIonizationCluster::SimPrimaryIonizationCluster(const SimPrimaryIonizationCluster& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

SimPrimaryIonizationCluster& SimPrimaryIonizationCluster::operator=(const SimPrimaryIonizationCluster& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

SimPrimaryIonizationCluster::SimPrimaryIonizationCluster( SimPrimaryIonizationClusterObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

SimPrimaryIonizationCluster SimPrimaryIonizationCluster::clone() const {
  return {new SimPrimaryIonizationClusterObj(*m_obj)};
}

SimPrimaryIonizationCluster::~SimPrimaryIonizationCluster() {
  if (m_obj) m_obj->release();
}
SimPrimaryIonizationCluster::operator ConstSimPrimaryIonizationCluster() const { return ConstSimPrimaryIonizationCluster(m_obj); }

const unsigned long long& SimPrimaryIonizationCluster::getCellID() const { return m_obj->data.cellID; }
const int& SimPrimaryIonizationCluster::getSize() const { return m_obj->data.size; }
const float& SimPrimaryIonizationCluster::getTime() const { return m_obj->data.time; }
const int& SimPrimaryIonizationCluster::getType() const { return m_obj->data.type; }
const edm4hep::Vector3d& SimPrimaryIonizationCluster::getPosition() const { return m_obj->data.position; }

const edm4hep::ConstMCParticle SimPrimaryIonizationCluster::getMCParticle() const {
  if (!m_obj->m_MCParticle) {
    return edm4hep::ConstMCParticle(nullptr);
  }
  return edm4hep::ConstMCParticle(*(m_obj->m_MCParticle));
}


void SimPrimaryIonizationCluster::setCellID(unsigned long long value) { m_obj->data.cellID = value; }
void SimPrimaryIonizationCluster::setSize(int value) { m_obj->data.size = value; }
void SimPrimaryIonizationCluster::setTime(float value) { m_obj->data.time = value; }
void SimPrimaryIonizationCluster::setType(int value) { m_obj->data.type = value; }
void SimPrimaryIonizationCluster::setPosition(edm4hep::Vector3d value) { m_obj->data.position = value; }
edm4hep::Vector3d& SimPrimaryIonizationCluster::position() { return m_obj->data.position; }

void SimPrimaryIonizationCluster::setMCParticle(edm4hep::ConstMCParticle value) {
  if (m_obj->m_MCParticle) delete m_obj->m_MCParticle;
  m_obj->m_MCParticle = new edm4hep::ConstMCParticle(value);
}







bool SimPrimaryIonizationCluster::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID SimPrimaryIonizationCluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool SimPrimaryIonizationCluster::operator==(const ConstSimPrimaryIonizationCluster& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstSimPrimaryIonizationCluster& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " size : " << value.getSize() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " position : " << value.getPosition() << '\n';

  o << " MCParticle : " << value.getMCParticle().id() << '\n';


  return o;
}

} // namespace cepcsw

