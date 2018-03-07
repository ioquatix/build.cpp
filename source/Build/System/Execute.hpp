
#pragma once

#include <unistd.h>
#include <iostream>

namespace Build
{
	namespace System
	{
		struct Execute : public Rule
		{
			using Rule::Rule;
			
			template <typename... ArgumentsT>
			void operator()(ArgumentsT && ...arguments) const
			{
				std::vector<const char *> argv;
				
				flatten(argv, std::forward<ArgumentsT>(arguments)...);
				
				bool first = true;
				for (auto && arg : argv) {
					if (first) first = false;
					else std::cerr << ' ';
					
					if (arg)
						std::cerr << arg;
				}
				
				std::cerr << std::endl;
				
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
					execve(argv[0], const_cast<char * const *>(argv.data()), nullptr);
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			
		private:
			template <typename VectorT>
			void flatten(VectorT & vector) const
			{
				vector.push_back(nullptr);
			}
			
			template <typename VectorT, typename ElementT, typename... TailT>
			void flatten(VectorT & vector, const std::vector<ElementT> & head, const TailT & ...tail) const
			{
				for (auto && value : head) {
					vector.push_back(value.c_str());
				}
				
				flatten(vector, tail...);
			}
			
			template <typename VectorT, typename HeadT, typename... TailT>
			void flatten(VectorT & vector, const HeadT & head, const TailT & ...tail) const
			{
				vector.push_back(head);
				
				flatten(vector, tail...);
			}
		};
	}
}
