
#pragma once

#include <unistd.h>

namespace Build
{
	namespace System
	{
		struct Execute : public Rule
		{
			using Rule::Rule;
			
			template <typename... ArgumentsT>
			void operator()(ArgumentsT... arguments) const
			{
				std::vector<const char *> argv{arguments...};
				
				pid_t pid = fork();
				
				if (pid == -1) {
					throw std::runtime_error("failed to fork");
				} if (pid > 0) {
					// Parent waits for child:
					int status = -1;
					
					waitpid(pid, &status, 0);
					
					if (status != 0)
						throw std::runtime_error("child non-zero exit status");
				} else {
					// Child executes command:
					execve(argv[0], const_cast<char *const *>(argv.data()), environment.envp);
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
		};
	};
};
