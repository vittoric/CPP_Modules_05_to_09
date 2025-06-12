#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "Base.hpp" // For Base*
# include "A.hpp"    // For class A
# include "B.hpp"    // For class B
# include "C.hpp"    // For class C
# include <iostream>  // For std::cout
# include <cstdlib>   // For rand() and srand()
# include <ctime>     // For time()
# include <exception> // For std::bad_cast

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
