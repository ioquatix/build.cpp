
context.package("build", [](Package & package){
	package.target("build-library", [&](Target & target){
		target.provides("lib/libBuild.a", [&](Environment & environment){
			auto compiler = environment.fetch<Compile::Compiler>();
			compiler.add_include_path(package.root_path + "source");
			
			auto linker = environment.fetch<Link::Linker>();
			linker.add_local_library("libBuild.a");
		});
		
		target.build([&](Task & task){
			// auto source_paths = Glob(package.root_path, "source/**/*.{cpp}");
			auto source_paths = Paths{
				"source/Build/Context.cpp",
				"source/Build/Environment.cpp",
				"source/Build/Package.cpp",
				"source/Build/Rule.cpp",
				"source/Build/Target.cpp",
				"source/Build/Task.cpp",
			};
			
			auto linker = task.environment.fetch<Link::Linker>();
			auto library_path = linker.library_prefix(task.environment) + "libBuild.a";
			
			task.invoke<Build::Compile::Archive>(source_paths, library_path);
		});
	});
	
	package.target("build-executable", [&](Target & target){
		target.depends("lib/libBuild.a");
		target.provides("bin/build");
		
		target.build([&](Task & task){
			auto source_paths = Paths{
				"build.cpp",
			};
			
			auto linker = task.environment.fetch<Link::Linker>();
			auto library_path = linker.executable_prefix(task.environment) + "build";
			
			task.invoke<Build::Compile::Executable>(source_paths, library_path);
		});
	});
	
	package.target("build-test", [&](Target & target){
		target.depends("lib/libBuild.a");
		
		target.provides("test/build");
	});
	
	//Build::Standard::Clang(package);
});
