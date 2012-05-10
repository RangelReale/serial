find_path(serial_INCLUDE_DIRS serial/serial.h /usr/include 
          /usr/local/include "$ENV{NAMER_ROOT}")

find_library(serial_LIBRARIES serial /usr/lib /usr/local/lib
             "$ENV{NAMER_ROOT}")

set(serial_FOUND TRUE)

if (NOT serial_INCLUDE_DIRS)
    set(serial_FOUND FALSE)
endif (NOT serial_INCLUDE_DIRS)

if (NOT serial_LIBRARIES)
    set(serial_FOUND FALSE)
endif (NOT serial_LIBRARIES)