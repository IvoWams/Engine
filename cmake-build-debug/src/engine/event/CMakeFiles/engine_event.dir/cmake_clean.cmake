file(REMOVE_RECURSE
  "libengine_event.a"
  "libengine_event.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/engine_event.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
