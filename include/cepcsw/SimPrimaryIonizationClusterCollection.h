// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef cepcsw_SimPrimaryIonizationClusterCollection_H
#define cepcsw_SimPrimaryIonizationClusterCollection_H

// datamodel specific includes
#include "cepcsw/SimPrimaryIonizationClusterData.h"
#include "cepcsw/SimPrimaryIonizationCluster.h"
#include "cepcsw/SimPrimaryIonizationClusterObj.h"

// podio specific includes
#include "podio/ICollectionProvider.h"
#include "podio/CollectionBase.h"
#include "podio/CollectionIDTable.h"

#include <string>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <ostream>

namespace cepcsw {


using SimPrimaryIonizationClusterDataContainer = std::vector<SimPrimaryIonizationClusterData>;
using SimPrimaryIonizationClusterObjPointerContainer = std::deque<SimPrimaryIonizationClusterObj*>;

class SimPrimaryIonizationClusterCollectionIterator {
public:
  SimPrimaryIonizationClusterCollectionIterator(int index, const SimPrimaryIonizationClusterObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  bool operator!=(const SimPrimaryIonizationClusterCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  const SimPrimaryIonizationCluster operator*() const;
  const SimPrimaryIonizationCluster* operator->() const;
  const SimPrimaryIonizationClusterCollectionIterator& operator++() const;

private:
  mutable int m_index;
  mutable SimPrimaryIonizationCluster m_object;
  const SimPrimaryIonizationClusterObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class SimPrimaryIonizationClusterCollection : public podio::CollectionBase {

public:
  using const_iterator = const SimPrimaryIonizationClusterCollectionIterator;

  SimPrimaryIonizationClusterCollection();
//  SimPrimaryIonizationClusterCollection(const SimPrimaryIonizationClusterCollection& ) = delete; // deletion doesn't work w/ ROOT IO ! :-(
//  SimPrimaryIonizationClusterCollection(SimPrimaryIonizationClusterVector* data, int collectionID);
  ~SimPrimaryIonizationClusterCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  SimPrimaryIonizationClusterCollection* operator->() { return (SimPrimaryIonizationClusterCollection*) this; }

  /// Append a new object to the collection, and return this object.
  SimPrimaryIonizationCluster create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  SimPrimaryIonizationCluster create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("cepcsw::SimPrimaryIonizationCluster"); }

  /// Returns the const object of given index
  const SimPrimaryIonizationCluster operator[](unsigned int index) const;
  /// Returns the object of a given index
  SimPrimaryIonizationCluster operator[](unsigned int index);
  /// Returns the const object of given index
  const SimPrimaryIonizationCluster at(unsigned int index) const;
  /// Returns the object of given index
  SimPrimaryIonizationCluster at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstSimPrimaryIonizationCluster object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (SimPrimaryIonizationClusterObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
    );
  };

  unsigned getID() const override final {
    return m_collectionID;
  }

  bool isValid() const override final {
    return m_isValid;
  }

  // support for the iterator protocol
  const const_iterator begin() const {
    return const_iterator(0, &m_entries);
  }
  const const_iterator end() const {
    return const_iterator(m_entries.size(), &m_entries);
  }

  /// returns the address of the pointer to the data buffer
  void* getBufferAddress() override final { return (void*)&m_data; }

  /// Returns the pointer to the data buffer
  std::vector<SimPrimaryIonizationClusterData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<unsigned long long, arraysize> cellID() const;
  template<size_t arraysize>
  const std::array<int, arraysize> size() const;
  template<size_t arraysize>
  const std::array<float, arraysize> time() const;
  template<size_t arraysize>
  const std::array<int, arraysize> type() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3d, arraysize> position() const;

private:
  bool m_isValid;
  bool m_isReadFromFile{false};
  int m_collectionID;
  SimPrimaryIonizationClusterObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstMCParticle>* m_rel_MCParticle; ///< Relation buffer for read / write

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections;
  podio::VectorMembersInfo m_vecmem_info;
  SimPrimaryIonizationClusterDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const SimPrimaryIonizationClusterCollection& v);

template<typename... Args>
SimPrimaryIonizationCluster SimPrimaryIonizationClusterCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new SimPrimaryIonizationClusterObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return SimPrimaryIonizationCluster(obj);
}

template<size_t arraysize>
const std::array<unsigned long long, arraysize> SimPrimaryIonizationClusterCollection::cellID() const {
  std::array<unsigned long long, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.cellID;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> SimPrimaryIonizationClusterCollection::size() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.size;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> SimPrimaryIonizationClusterCollection::time() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.time;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> SimPrimaryIonizationClusterCollection::type() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.type;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3d, arraysize> SimPrimaryIonizationClusterCollection::position() const {
  std::array<edm4hep::Vector3d, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.position;
  }
  return tmp;
}


} // namespace cepcsw


#endif
