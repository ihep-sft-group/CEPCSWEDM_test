

include_directories("./include")
include_directories("${podio_INCLUDE_DIR}")
set(headers ./include/cepcsw/SimPrimaryIonizationCluster.h;./include/cepcsw/SimPrimaryIonizationClusterCollection.h;./include/cepcsw/SimPrimaryIonizationClusterConst.h;./include/cepcsw/SimPrimaryIonizationClusterData.h;./include/cepcsw/SimPrimaryIonizationClusterObj.h;./include/cepcsw/SimIonization.h;./include/cepcsw/SimIonizationCollection.h;./include/cepcsw/SimIonizationConst.h;./include/cepcsw/SimIonizationData.h;./include/cepcsw/SimIonizationObj.h)


set(sources ./src/SimPrimaryIonizationCluster.cc;./src/SimPrimaryIonizationClusterCollection.cc;./src/SimPrimaryIonizationClusterConst.cc;./src/SimPrimaryIonizationClusterObj.cc;./src/SimIonization.cc;./src/SimIonizationCollection.cc;./src/SimIonizationConst.cc;./src/SimIonizationObj.cc)
message("head= ${headers}, src=${sources}")
PODIO_ADD_DATAMODEL_CORE_LIB(cepcEdm "${headers}" "${sources}")

target_include_directories(cepcEdm
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)



PODIO_ADD_ROOT_IO_DICT(cepcEdmDict cepcEdm "${headers}" src/selection.xml)
add_library(cepcsw::cepcEdmDict ALIAS cepcEdmDict )

list(APPEND CEPCSWEDM_INSTALL_LIBS cepcEdm cepcEdmDict)


install(TARGETS ${CEPCSWEDM_INSTALL_LIBS}
  EXPORT CEPCSWTargets
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" COMPONENT bin
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}" COMPONENT shlib
  COMPONENT dev)

# Modules
gaudi_add_module(ExamplesCepcEDM
                 SOURCES test/EdmReadDCAlg.cpp
                         test/EdmWriteDCAlg.cpp
                 LINK k4FWCore::k4FWCore
                      Gaudi::GaudiAlgLib Gaudi::GaudiKernel
                      ${LCIO_LIBRARIES} 
                      ${DD4hep_COMPONENT_LIBRARIES}
                      EDM4HEP::edm4hep EDM4HEP::edm4hepDict
                      ${podio_LIBRARIES} podio::podioRootIO
                      cepcEdm
)

install(TARGETS ExamplesCepcEDM
  EXPORT CEPCSWTargets
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" COMPONENT bin
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}" COMPONENT shlib
  COMPONENT dev)
