include_directories(Include)

aux_source_directory(Source _SOURCES)
set(CODE_SOURCES ${CODE_SOURCES} ${_SOURCES})

add_library(detourtilecache${OUTPUT_SUFFIX} ${CODE_SOURCES})
