
context.package("standard-c++", [](Package & package){
	auto source_path = package.root_path + "/source";
	
	package.target("standard-c++", [&](Target & target){
		target.provides("language/c++14", [&](Environment & environment){
			auto && variant = environment.fetch<Variant>();
			
			variant.compiler_flags.push_back("-std=c++14");
		});
	});
});
