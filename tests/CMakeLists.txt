# add new tests to this list
LIST(APPEND TESTS	transformation_di_00
					psi_mech_00
					psi_elec_00
					psi_surf_00
					delta_eta_00
					psi_mech_01
					psi_elec_01
					delta_eta_01
					psi_incompressibility_00
					psi_incompressibility_01)

FOREACH(TEST ${TESTS})
  ADD_EXECUTABLE(${TEST} ${TEST}.cc)
  ADD_TEST(${TEST} ${TEST})
  IF (WIN32)
   STRING(REPLACE "${DEMODEL_INSTALL_PATH_LIBRARIES}/lib${DEMODEL_TARGET}.dll" "${CMAKE_BINARY_DIR}/lib${DEMODEL_TARGET}.dll" TEST_LIBRARIES ${DEMODEL_LIBRARIES})
  ELSE()
   STRING(REPLACE "${DEMODEL_INSTALL_PATH_LIBRARIES}/lib${DEMODEL_TARGET}.so" "${CMAKE_BINARY_DIR}/lib${DEMODEL_TARGET}.so" TEST_LIBRARIES ${DEMODEL_LIBRARIES})
  ENDIF()
  TARGET_LINK_LIBRARIES(${TEST} ${TEST_LIBRARIES})
  CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/tests/${TEST}.log ${PROJECT_BINARY_DIR}/tests/${TEST}.log COPYONLY)
ENDFOREACH(TEST)