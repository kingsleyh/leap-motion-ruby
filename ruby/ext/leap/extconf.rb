# require 'mkmf'
require 'mkmf-rice'

# RbConfig::MAKEFILE_CONFIG['CC'] = ENV['CC'] if ENV['CC']

extension_name = 'example'


dir_config(".", "../../include", "../../lib/x64")
#   append_library("Leap");
# have_library("../lib/x64/libLeap.so")
create_makefile('leap')

