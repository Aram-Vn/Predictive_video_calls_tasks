cmake_minimum_required(VERSION 3.5)

project(Basic_Form_with_Validation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)
configure_file(my_suppressions.supp ${CMAKE_CURRENT_BINARY_DIR}/my_suppressions.supp COPYONLY)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Basic_Form_with_Validation
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Basic_Form_with_Validation APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Basic_Form_with_Validation SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Basic_Form_with_Validation
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Basic_Form_with_Validation PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Basic_Form_with_Validation)
endif()
set_target_properties(Basic_Form_with_Validation PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Basic_Form_with_Validation
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Basic_Form_with_Validation)
endif()


# Enable testing in CMake
enable_testing()

# # Add a test that runs the executable with Memcheck for memory leak checking
# add_test(
#     NAME MemoryLeakTest
#     COMMAND valgrind --tool=memcheck --leak-check=full --error-exitcode=1 $<TARGET_FILE:Basic_Form_with_Validation>
# )

# # Optionally, you can specify a working directory for the test
# set_tests_properties(MemoryLeakTest PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Add a test that runs the executable with Memcheck for memory leak checking
add_test(
    NAME MemoryLeakTest
    COMMAND valgrind --tool=memcheck --leak-check=full --error-exitcode=1 --suppressions=${CMAKE_CURRENT_SOURCE_DIR}/my_suppressions.supp $<TARGET_FILE:Basic_Form_with_Validation>
)

# Optionally, you can specify a working directory for the test
set_tests_properties(MemoryLeakTest PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
