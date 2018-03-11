
context.package("variants", [](Package & package){
	package.target("variant-debug", [&](Target & target){
		target.provides("variant/debug", [&](Environment & environment){
			auto & variant = environment.fetch<Variant>();
		});
		
		target.depends("variant/generic");
		//target.provides("variant", "variant/debug")
	});
});
