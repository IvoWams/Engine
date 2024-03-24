file(REMOVE_RECURSE
  "libengine.a"
  "libengine.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/engine.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
