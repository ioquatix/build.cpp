
Build::Source::Git git("git://git@github.com/kurocha")

Build::Configuration([](auto & configuration){
	configuration.public();
	
	configuration.source = git;
	
	configuration.require("variant")
	configuration.require("standard-c++")
});

Build::Configuration("development", [](auto & configuration){
	
});
