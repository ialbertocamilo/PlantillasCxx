cmake_minimum_required(VERSION 3.5)

project(Qtc LANGUAGES CXX)

  # Tell CMake to run moc when necessary:
  set(CMAKE_AUTOMOC ON)
  # As moc files are generated in the binary dir, tell CMake
  # to always look for includes there:
  set(CMAKE_INCLUDE_CURRENT_DIR ON)


  set(Qt5_DIR "C:\\Users\\lobo_\\Documents\\qt-5.13static\\qt-5.13.0\\lib\\cmake\\Qt5")
  # Widgets finds its own dependencies (QtGui and QtCore).
  find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)

  # The Qt5Widgets_INCLUDES also includes the include directories for
  # dependencies QtCore and QtGui
  include_directories(${Qt5Widgets_INCLUDES})

  # We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
  add_definitions(${Qt5Widgets_DEFINITIONS})

  # Executables fail to build with Qt 5 in the default configuration
  # without -fPIE. We add that here.
  set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

  add_executable(Qtc main.cpp mainwindow.cpp)

  # The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
  target_link_libraries(Qtc ${Qt5Widgets_LIBRARIES})
  set_target_properties(Qtc PROPERTIES COMPILE_OPTIONS "-m64" LINK_FLAGS "-m64")