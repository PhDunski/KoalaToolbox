
# Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.

find_path( CATCH_INCLUDE_DIRS catch.hpp HINTS "${PROJECT_SOURCE_DIR}/extlib/catch/include" "/usr/include" "/usr/local/include" "/opt/local/include" )

if ( CATCH_INCLUDE_DIRS )
    set( CATCH_FOUND TRUE )

    message( STATUS "${Green}Found Catch include at: ${CATCH_INCLUDE_DIRS}${Reset}" )
else ( )
    message( FATAL_ERROR "${Red}Failed to locate Catch dependency.${Reset}" )
endif ( )
