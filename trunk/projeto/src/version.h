#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 751;
	static const long REVISION = 4265;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 822;
	#define RC_FILEVERSION 0,9,751,4265
	#define RC_FILEVERSION_STRING "0, 9, 751, 4265\0"
	static const char FULLVERSION_STRING[] = "0.9.751.4265";
	
	//SVN Version
	static const char SVN_REVISION[] = "198";
	static const char SVN_DATE[] = "2010-03-24T23:21:17.947964Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 91;
	

}
#endif //VERSION_h
