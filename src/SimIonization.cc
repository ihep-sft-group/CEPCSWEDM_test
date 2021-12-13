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


SimIonization::SimIonization() : m_obj(new SimIonizationObj()) {
  m_obj->acquire();
}

SimIonization::SimIonization(unsigned long long cellID, float time, int type, edm4hep::Vector3d position) : m_obj(new SimIonizationObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.time = time;
  m_obj->data.type = type;
  m_obj->data.position = position;
}

SimIonization::SimIonization(const SimIonization& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

SimIonization& SimIonization::operator=(const SimIonization& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

SimIonization::SimIonization( SimIonizationObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

SimIonization SimIonization::clone() const {
  return {new SimIonizationObj(*m_obj)};
}

SimIonization::~SimIonization() {
  if (m_obj) m_obj->release();
}
SimIonization::operator ConstSimIonization() const { return ConstSimIonization(m_obj); }

const unsigned long long& SimIonization::getCellID() const { return m_obj->data.cellID; }
const float& SimIonization::getTime() const { return m_obj->data.time; }
const int& SimIonization::getType() const { return m_obj->data.type; }
const edm4hep::Vector3d& SimIonization::getPosition() const { return m_obj->data.position; }

const edm4hep::ConstMCParticle SimIonization::getMCParticle() const {
  if (!m_obj->m_MCParticle) {
    return edm4hep::ConstMCParticle(nullptr);
  }
  return edm4hep::ConstMCParticle(*(m_obj->m_MCParticle));
}

const ConstSimPrimaryIonizationCluster SimIonization::getPrimaryIonization() const {
  if (!m_obj->m_PrimaryIonization) {
    return cepcsw::ConstSimPrimaryIonizationCluster(nullptr);
  }
  return cepcsw::ConstSimPrimaryIonizationCluster(*(m_obj->m_PrimaryIonization));
}


void SimIonization::setCellID(unsigned long long value) { m_obj->data.cellID = value; }
void SimIonization::setTime(float value) { m_obj->data.time = value; }
void SimIonization::setType(int value) { m_obj->data.type = value; }
void SimIonization::setPosition(edm4hep::Vector3d value) { m_obj->data.position = value; }
edm4hep::Vector3d& SimIonization::position() { return m_obj->data.position; }

void SimIonization::setMCParticle(edm4hep::ConstMCParticle value) {
  if (m_obj->m_MCParticle) delete m_obj->m_MCParticle;
  m_obj->m_MCParticle = new edm4hep::ConstMCParticle(value);
}

void SimIonization::setPrimaryIonization(cepcsw::ConstSimPrimaryIonizationCluster value) {
  if (m_obj->m_PrimaryIonization) delete m_obj->m_PrimaryIonization;
  m_obj->m_PrimaryIonization = new ConstSimPrimaryIonizationCluster(value);
}







bool SimIonization::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID SimIonization::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool SimIonization::operator==(const ConstSimIonization& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstSimIonization& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " position : " << value.getPosition() << '\n';

  o << " MCParticle : " << value.getMCParticle().id() << '\n';
  o << " PrimaryIonization : " << value.getPrimaryIonization().id() << '\n';


  return o;
}

} // namespace cepcsw

