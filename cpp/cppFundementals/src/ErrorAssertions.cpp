/*
From Game Engine Architecture (Gregory) chapter 3
Uses an assertion within your code to catch errors (more efficient than try-catch)
Can be removed from release builds with preprocessing macros
can define multiple levels of assertions (e.g slow_assertion for particularily intensive checks)
*/

//example
#if ASSERTIONS_ENABLED
	//define inline assembly that causes a break into the debugger
	#define debugBreak() asm {int 3} 

	//check the expression and fail if it is false
#define ASSERT(expr) //the expression to evaluate 
	if(expr) {} //if true don't do anything
	else  //if false report the failure
	{ 
		reportAssertionFailure(#expr, \__FILE__, __LINE__); //reports the file and line number of the error :), the #expr turns the expression into a string
		debugBreak(); //stop the program
	}
#else
	#define ASSERT(expr) //evals to nothing
#endif

/*
Think of them as bug landmines in your code meant to catch anything that slips through as you develop

*/