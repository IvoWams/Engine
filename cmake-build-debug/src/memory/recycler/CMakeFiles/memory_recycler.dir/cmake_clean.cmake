file(REMOVE_RECURSE
  "libmemory_recycler.a"
  "libmemory_recycler.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/memory_recycler.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
