

taskflow_dep = dependency('taskflow', fallback :['taskflow', 'taskflow_dep'])

exe = executable(
    'process_files',
    sources : ['process_files.cpp'],
    dependencies : [anltk_dep, taskflow_dep, dependency('threads')]
)