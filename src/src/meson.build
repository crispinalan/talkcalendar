
talkcalendar_src = [  
  'dbmanager.c', 
  'wavplay.c', 
  'wavcat.c',    
  'main.c',  
]
compiler = meson.get_compiler('c')

talkcalendar_deps = [
  compiler.find_library('m', required : false),
  dependency('gtk+-3.0', version : '>=3.22'),
  dependency('libnotify'),
  dependency('sqlite3', version : '>= 3.27.2'),
  dependency('alsa', version : '>=0.9.1')
  
]

executable(
  'talkcalendar', talkcalendar_src,  
  dependencies: talkcalendar_deps, 
  gui_app: true
)

