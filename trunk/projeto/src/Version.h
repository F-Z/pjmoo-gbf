#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 916;
	static const long REVISION = 5178;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1016;
	#define RC_FILEVERSION 0,9,916,5178
	#define RC_FILEVERSION_STRING "0, 9, 916, 5178\0"
	static const char FULLVERSION_STRING[] = "0.9.916.5178";
	
	//SVN Version
	static const char SVN_REVISION[] = "213";
	static const char SVN_DATE[] = "2010-04-13T00:31:39.099307Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 94;
	

}
#endif //VERSION_H
