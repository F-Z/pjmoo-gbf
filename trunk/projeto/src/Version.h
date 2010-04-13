#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 904;
	static const long REVISION = 5107;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1008;
	#define RC_FILEVERSION 0,9,904,5107
	#define RC_FILEVERSION_STRING "0, 9, 904, 5107\0"
	static const char FULLVERSION_STRING[] = "0.9.904.5107";
	
	//SVN Version
	static const char SVN_REVISION[] = "210";
	static const char SVN_DATE[] = "2010-04-05T19:48:47.526032Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 82;
	

}
#endif //VERSION_h
