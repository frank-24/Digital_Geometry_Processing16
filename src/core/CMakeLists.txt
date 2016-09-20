set(NAME core)

set(HEADERS
  Faces.hpp
  Graph.hpp
  GraphTraversal.hpp
  Partition.hpp
  PolygonMesh.hpp
  PriorityQueueFloat.hpp
  QueueInt.hpp
  SplittablePartition.hpp
) # HEADERS    

set(SOURCES
  Faces.cpp
  Graph.cpp
  GraphTraversal.cpp
  Partition.cpp
  PolygonMesh.cpp
  PriorityQueueFloat.cpp
  QueueInt.cpp
  SplittablePartition.cpp
) # SOURCES

qt5_wrap_ui(FORMS
) # FORMS

qt5_add_resources(ASSETS
) # ASSETS

add_library(${NAME}
    ${HEADERS}
    ${SOURCES}
    ${FORMS}
    ${ASSETS}
) # add_library

target_compile_features(${NAME} PRIVATE cxx_lambdas)

target_link_libraries(${NAME} ${LIB_LIST})


