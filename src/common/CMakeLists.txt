# Create a library called "Common"
set(Common_SRC Arcball.cpp  Common.cpp  Statistic.cpp  Timer.cpp)
set(Common_HDR Arcball.h  Common.h  Statistic.h  MatrixLoader.h Timer.h)
add_library(Common ${Common_SRC} ${Common_HDR})
