project(timed-source)

if(MSVC)
		set(timed-source_PLATFORM_DEPS
				w32-pthreads)
endif()

set(timed-source_SOURCES
		timed-media-source.c
		timed-source-plugin.c)

add_library(timed-source MODULE
		${timed-source_SOURCES})

target_link_libraries(timed-source
		libobs
		${timed-source_PLATFORM_DEPS})

install_obs_plugin_with_data(timed-source data)