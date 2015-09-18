set(DimReduction_HDR 
DimensionalityReduction.h
#IsoMap.h
KernelPCA.h
RandomProjection.h
LocallyLinearEmbedding.h
)

set(DimReduction_SRC
#IsoMap.cpp
KernelPCA.cpp
RandomProjection.cpp
LocallyLinearEmbedding.cpp
)

add_library(DimReduction ${DimReduction_SRC} ${DimReduction_HDR})
target_link_libraries(DimReduction GraphLayout Common )

