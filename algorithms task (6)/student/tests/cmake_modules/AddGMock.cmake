macro(add_gmock)
    set(ZIPNAME release-1.10.0)
    set(ZIPFILE ${LESSONS_ROOT}/${ZIPNAME}.zip)
    set(MOCKDIR ${LESSONS_ROOT}/googletest-${ZIPNAME})

    if(NOT IS_DIRECTORY ${MOCKDIR})
        if(NOT EXISTS ${ZIPFILE})
            message(STATUS "Downloading googletest...")
            execute_process(COMMAND wget -nv -P ${LESSONS_ROOT} https://github.com/google/googletest/archive/${ZIPNAME}.zip)
        endif()
        message(STATUS "Extracting ${ZIPNAME}...")
        execute_process(COMMAND unzip -q ${ZIPFILE} -d ${LESSONS_ROOT})
    endif()

    if(IS_DIRECTORY ${MOCKDIR})
        add_subdirectory(${MOCKDIR} ${LESSONS_ROOT}/gmock EXCLUDE_FROM_ALL)
    else()
        message(FATAL_ERROR "No ${MOCKDIR} found, can't add googletest")
    endif()
endmacro()
