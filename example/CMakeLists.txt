add_executable(wxFFmpegPlayer
    main.cc
    )

target_link_libraries(wxFFmpegPlayer PRIVATE
    wxFFmpeg
    )
