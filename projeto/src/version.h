#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 660;
	static const long REVISION = 3722;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 728;
	#define RC_FILEVERSION 0,9,660,3722
	#define RC_FILEVERSION_STRING "0, 9, 660, 3722\0"
	static const char FULLVERSION_STRING[] = "0.9.660.3722";
	
	//SVN Version
	static const char SVN_REVISION[] = "241";
	static const char SVN_DATE[] = "2009-08-15T01:26:48.777071Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 0;
	

}
#endif //VERSION_h
