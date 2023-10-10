include_directories(Include/)

aux_source_directory(Source _SOURCES)
set(CODE_SOURCES ${CODE_SOURCES} ${_SOURCES})

add_library(detourcrowd${OUTPUT_SUFFIX} ${CODE_SOURCES})
