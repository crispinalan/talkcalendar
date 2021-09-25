talkcalendar_src = [  
  'dbmanager.c',      
  'main.c',  
]
compiler = meson.get_compiler('c')

talkcalendar_deps = [
  
 compiler.find_library('m', required : false), 
 compiler.find_library('flite', required : true),
 compiler.find_library('flite_cmu_us_kal', required : true),
 compiler.find_library('flite_usenglish', required : true),
 compiler.find_library('flite_cmulex', required : true),
 compiler.find_library('asound', required : true),  
  
  dependency('gtk+-3.0', version : '>=3.22'),  
  dependency('sqlite3', version : '>= 3.27.2'),
 
  
]

executable(
  'talkcalendar', talkcalendar_src,  
  dependencies: talkcalendar_deps, 
  gui_app: true
)

