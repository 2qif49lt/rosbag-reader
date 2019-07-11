project('image', 'cpp', default_options: ['cpp_std=c++11'])
incdir = include_directories('/opt/ros/melodic/include/')
deps = []
deps += dependency('liblz4')
deps += dependency('roscpp_serialization')
src = ['image.cpp', 'bag_rdr.cpp']
extra_args = ['-DBAG_RDR_USE_SYSTEM_LZ4=1', '-DDISABLE_BZ2=1']
executable('image-demo', src,  cpp_args: extra_args, include_directories : incdir, dependencies : deps)