sources = files(
  'main.cpp',
  'instance.cpp',
  'MCF.cpp',
  'solution.cpp',
)

incdir = include_directories('../include')

executable(
  meson.project_name(), 
  sources,
  include_directories: [incdir, incdir_deps],
  dependencies: dependencies,
  install: true
)

