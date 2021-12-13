// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "cepcsw/SimIonizationCollection.h"

#include "edm4hep/MCParticleCollection.h"
#include "cepcsw/SimPrimaryIonizationClusterCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace cepcsw {


SimIonizationCollection::SimIonizationCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_MCParticle(new std::vector<edm4hep::ConstMCParticle>()),
  m_rel_PrimaryIonization(new std::vector<cepcsw::ConstSimPrimaryIonizationCluster>()),
  m_data(new SimIonizationDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

SimIonizationCollection::~SimIonizationCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_MCParticle) delete m_rel_MCParticle;
  if (m_rel_PrimaryIonization) delete m_rel_PrimaryIonization;
}

const SimIonization SimIonizationCollection::operator[](unsigned int index) const {
  return SimIonization(m_entries[index]);
}

const SimIonization SimIonizationCollection::at(unsigned int index) const {
  return SimIonization(m_entries.at(index));
}

SimIonization SimIonizationCollection::operator[](unsigned int index) {
  return SimIonization(m_entries[index]);
}

SimIonization SimIonizationCollection::at(unsigned int index) {
  return SimIonization(m_entries.at(index));
}

size_t SimIonizationCollection::size() const {
  return m_entries.size();
}

SimIonization SimIonizationCollection::create() {
  auto obj = m_entries.emplace_back(new SimIonizationObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return SimIonization(obj);
}

void SimIonizationCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  for (auto& item : (*m_rel_MCParticle)) { item.unlink(); }
  m_rel_MCParticle->clear();

  for (auto& item : (*m_rel_PrimaryIonization)) { item.unlink(); }
  m_rel_PrimaryIonization->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void SimIonizationCollection::prepareForWrite() {
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

  for (auto& obj : m_entries) {
    if (obj->m_PrimaryIonization) {
      m_refCollections[1]->emplace_back(obj->m_PrimaryIonization->getObjectID());
    } else {
       m_refCollections[1]->push_back({podio::ObjectID::invalid, podio::ObjectID::invalid});
    }
  }

}

void SimIonizationCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new SimIonizationObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isValid = true;
  m_isReadFromFile = true;
}

bool SimIonizationCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
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

  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[1])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      cepcsw::SimPrimaryIonizationClusterCollection* tmp_coll = static_cast<cepcsw::SimPrimaryIonizationClusterCollection*>(coll);
      m_entries[i]->m_PrimaryIonization = new ConstSimPrimaryIonizationCluster((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_PrimaryIonization = nullptr;
    }
  }


  return true; //TODO: check success
}

void SimIonizationCollection::push_back(ConstSimIonization object) {
  const int size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void SimIonizationCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<SimIonizationDataContainer*>(address);
}

const SimIonization SimIonizationCollectionIterator::operator*() const {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

const SimIonization* SimIonizationCollectionIterator::operator->() const {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

const SimIonizationCollectionIterator& SimIonizationCollectionIterator::operator++() const {
  ++m_index;
  return *this;
}

std::ostream& operator<<(std::ostream& o, const SimIonizationCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:        time:        type:                 position [ x, y, z]:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getCellID() << " "
      << std::setw(12) << v[i].getTime() << " "
      << std::setw(12) << v[i].getType() << " "
      << std::setw(12) << v[i].getPosition() << " "
      << std::endl;


    o << "      MCParticle : ";
    o << v[i].getMCParticle().id() << std::endl;
    o << "      PrimaryIonization : ";
    o << v[i].getPrimaryIonization().id() << std::endl;


  }

  o.flags(old_flags);
  return o;
}

} // namespace cepcsw

