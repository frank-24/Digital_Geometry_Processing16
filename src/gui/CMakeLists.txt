set(NAME dgp2016)

set(HEADERS
        GuiAboutDialog.hpp
        GuiMainWindow.hpp
        GuiToolsWidget.hpp
        GuiGLWidget.hpp
        GuiGLBuffer.hpp
        GuiGLShader.hpp
        GuiGLHandles.hpp
        GuiViewerData.hpp
        GuiQtLogo.hpp
        GuiStrings.hpp
) # HEADERS    

set(SOURCES
        GuiAboutDialog.cpp
        GuiViewerApp.cpp
        GuiMainWindow.cpp
        GuiToolsWidget.cpp
        GuiGLWidget.cpp
        GuiGLBuffer.cpp
        GuiGLShader.cpp
        GuiGLHandles.cpp
        GuiViewerData.cpp
        GuiQtLogo.cpp
) # SOURCES

qt5_wrap_ui(FORMS
) # FORMS

qt5_add_resources(ASSETS
) # ASSETS

if (APPLE)
  set(APP_ICON ${ASSETS_DIR}/bunny.icns)
  set_source_files_properties(${APP_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
  add_executable(${NAME} MACOSX_BUNDLE ${APP_ICON}
      ${HEADERS}
      ${SOURCES}
      ${FORMS}
      ${ASSETS}
  ) # add_executable
  set(MACOSX_BUNDLE_ICON_FILE "bunny.icns" )
else(APPLE)
  add_executable(${NAME}
      ${HEADERS}
      ${SOURCES}
      ${FORMS}
      ${ASSETS}
  ) # add_executable
endif(APPLE)

target_compile_features(${NAME} PRIVATE cxx_right_angle_brackets cxx_lambdas)

target_link_libraries(${NAME} ${LIB_LIST})
