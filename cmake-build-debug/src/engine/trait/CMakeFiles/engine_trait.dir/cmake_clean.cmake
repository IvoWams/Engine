file(REMOVE_RECURSE
  "libengine_trait.a"
  "libengine_trait.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/engine_trait.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
