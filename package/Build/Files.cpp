
Build::Package files("build-files", [](Build::Package & package){
	package.depends("system");
	
	package.target("build-files", [](Target & target){
		target.provides("Build/Files", [&](Environment & environment){
			environment.append("BUILD_RULES", "Build/CopyFile.hpp", "Build/CopyFiles.hpp", "Build/CopyHeaders.hpp");
		});
	});
	
	package.configuration([](Configuration & configuration){
		configuration.require("system");
	});
});
