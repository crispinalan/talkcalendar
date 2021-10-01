talkcalendar_src = [  
  'dbmanager.c',      
  'main.c',  
]
compiler = meson.get_compiler('c')

talkcalendar_deps = [  
 compiler.find_library('m', required : false), 
 dependency('gtk+-3.0', version : '>=3.22'),  
 dependency('sqlite3', version : '>= 3.27.2') 
]

executable(
  'talkcalendar', talkcalendar_src,  
  dependencies: talkcalendar_deps, 
  gui_app: true
)

