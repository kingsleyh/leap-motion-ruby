Gem::Specification.new do |s|
  s.name        = 'leap'
  s.version     = '0.0.2'
  s.date        = '2013-09-08'
  s.summary     = "Leap"
  s.description = "Leap"
  s.authors     = ["Kingsley Hendrickse","Zhenhua Chai"]
  s.email       = ['kingsley.hendrickse@gmail.com','chaizhenhua@gmail.com']
 
  s.platform    = Gem::Platform::CURRENT

  s.files       = Dir.glob("ext/leap/*.{cpp,h,i,rb}")
  s.extensions  << 'ext/leap/extconf.rb'
  s.add_development_dependency "rake-compiler"
end

