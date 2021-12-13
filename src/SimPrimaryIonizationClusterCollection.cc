// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "cepcsw/SimPrimaryIonizationClusterCollection.h"

#include "edm4hep/MCParticleCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace cepcsw {


SimPrimaryIonizationClusterCollection::SimPrimaryIonizationClusterCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_MCParticle(new std::vector<edm4hep::ConstMCParticle>()),
  m_data(new SimPrimaryIonizationClusterDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

SimPrimaryIonizationClusterCollection::~SimPrimaryIonizationClusterCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_MCParticle) delete m_rel_MCParticle;
}

const SimPrimaryIonizationCluster SimPrimaryIonizationClusterCollection::operator[](unsigned int index) const {
  return SimPrimaryIonizationCluster(m_entries[index]);
}

const SimPrimaryIonizationCluster SimPrimaryIonizationClusterCollection::at(unsigned int index) const {
  return SimPrimaryIonizationCluster(m_entries.at(index));
}

SimPrimaryIonizationCluster SimPrimaryIonizationClusterCollection::operator[](unsigned int index) {
  return SimPrimaryIonizationCluster(m_entries[index]);
}

SimPrimaryIonizationCluster SimPrimaryIonizationClusterCollection::at(unsigned int index) {
  return SimPrimaryIonizationCluster(m_entries.at(index));
}

size_t SimPrimaryIonizationClusterCollection::size() const {
  return m_entries.size();
}

SimPrimaryIonizationCluster SimPrimaryIonizationClusterCollection::create() {
  auto obj = m_entries.emplace_back(new SimPrimaryIonizationClusterObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return SimPrimaryIonizationCluster(obj);
}

void SimPrimaryIonizationClusterCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  for (auto& item : (*m_rel_MCParticle)) { item.unlink(); }
  m_rel_MCParticle->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void SimPrimaryIonizationClusterCollection::prepareForWrite() {
  const auto size = m_entries.size();
  m_data->reserve(size);
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }


  for (auto& obj : m_entries) {
    if (obj->m_MCParticle) {
      m_refCollections[0]->emplace_back(obj->m_MCParticle->getObjectID());
    } else {
       m_refCollections[0]->push_back({podio::ObjectID::invalid, podio::ObjectID::invalid});
    }
  }

}

void SimPrimaryIonizationClusterCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new SimPrimaryIonizationClusterObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isValid = true;
  m_isReadFromFile = true;
}

bool SimPrimaryIonizationClusterCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::MCParticleCollection* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
      m_entries[i]->m_MCParticle = new edm4hep::ConstMCParticle((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_MCParticle = nullptr;
    }
  }


  return true; //TODO: check success
}

void SimPrimaryIonizationClusterCollection::push_back(ConstSimPrimaryIonizationCluster object) {
  const int size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void SimPrimaryIonizationClusterCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<SimPrimaryIonizationClusterDataContainer*>(address);
}

const SimPrimaryIonizationCluster SimPrimaryIonizationClusterCollectionIterator::operator*() const {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

const SimPrimaryIonizationCluster* SimPrimaryIonizationClusterCollectionIterator::operator->() const {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

const SimPrimaryIonizationClusterCollectionIterator& SimPrimaryIonizationClusterCollectionIterator::operator++() const {
  ++m_index;
  return *this;
}

std::ostream& operator<<(std::ostream& o, const SimPrimaryIonizationClusterCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:        size:        time:        type:                 position [ x, y, z]:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getCellID() << " "
      << std::setw(12) << v[i].getSize() << " "
      << std::setw(12) << v[i].getTime() << " "
      << std::setw(12) << v[i].getType() << " "
      << std::setw(12) << v[i].getPosition() << " "
      << std::endl;


    o << "      MCParticle : ";
    o << v[i].getMCParticle().id() << std::endl;


  }

  o.flags(old_flags);
  return o;
}

} // namespace cepcsw

