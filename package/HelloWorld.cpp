
Build::Package test("hello-world", [](Build::Package & package){
	package.target("run-hello-world", [](Target & target){
		target.provides("Run/HelloWorld");
		
		target.build([&](Task & task) {
			std::cerr << "Hello World" << std:endl;
		});
	});
});
