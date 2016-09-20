set(NAME io)

set(HEADERS
  AppLoader.hpp
  AppSaver.hpp
  StrException.hpp
  Loader.hpp
  LoaderWrl.hpp
  LoaderStl.hpp
  Saver.hpp
  SaverWrl.hpp
  SaverStl.hpp
  Tokenizer.hpp
) # HEADERS    

set(SOURCES
  AppLoader.cpp
  AppSaver.cpp
  LoaderWrl.cpp
  LoaderStl.cpp
  SaverWrl.cpp
  SaverStl.cpp
  Tokenizer.cpp
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

