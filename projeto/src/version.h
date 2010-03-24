#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 724;
	static const long REVISION = 4110;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 799;
	#define RC_FILEVERSION 0,9,724,4110
	#define RC_FILEVERSION_STRING "0, 9, 724, 4110\0"
	static const char FULLVERSION_STRING[] = "0.9.724.4110";
	
	//SVN Version
	static const char SVN_REVISION[] = "195";
	static const char SVN_DATE[] = "2010-03-22T00:31:42.888145Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 64;
	

}
#endif //VERSION_h
