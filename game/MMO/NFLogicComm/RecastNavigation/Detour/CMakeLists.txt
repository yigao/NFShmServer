include_directories(Include/)

aux_source_directory(Source _SOURCES)
set(CODE_SOURCES ${CODE_SOURCES} ${_SOURCES})

add_library(detour${OUTPUT_SUFFIX} ${CODE_SOURCES})
