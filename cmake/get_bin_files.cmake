function(_msg_if_lib_doesnt_exist name)
    message("
[CMAKE] : Can't find external lib. Details :
- name : ${name}
[CMAKE] : Starting its installation..")
endfunction()

set(TMP_DIR_PATH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/.temp")


function(get_bin_files files_to_extract name ext full_path url_path)
    set(need_to_downoload FALSE)

    foreach(FILE_PATH ${ARGV0})
        get_filename_component(FILENAME "${FILE_PATH}" NAME)

        if(NOT EXISTS "${full_path}/${FILENAME}")
            set(need_to_downoload TRUE)
        endif()
    endforeach ()
    
    
    if(need_to_downoload)
        _msg_if_lib_doesnt_exist("${name}")

        # set(TMP_DIR_PATH "${CMAKE_CURRENT_BINARY_DIR}/.temp_unpack")
        file(MAKE_DIRECTORY "${TMP_DIR_PATH}")

        set(TMP_ARCHIVE "${TMP_DIR_PATH}/archive.${ext}")

        file(DOWNLOAD
            "${url_path}"
            "${TMP_ARCHIVE}"
            SHOW_PROGRESS
        )

        message("[CMAKE] : Extracting..")
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E tar -xf "${TMP_ARCHIVE}"
            WORKING_DIRECTORY "${TMP_DIR_PATH}"
        )

        message("[CMAKE] : Moving result..")
        foreach(FILE_PATH ${ARGV0})
            file(
                COPY "${TMP_DIR_PATH}/${FILE_PATH}"
                DESTINATION "${full_path}"
            )
        endforeach()
        file(REMOVE_RECURSE "${TMP_DIR_PATH}")

    endif()
endfunction()