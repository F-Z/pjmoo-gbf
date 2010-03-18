#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 355;
	static const long REVISION = 2027;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 396;
	#define RC_FILEVERSION 0,9,355,2027
	#define RC_FILEVERSION_STRING "0, 9, 355, 2027\0"
	static const char FULLVERSION_STRING[] = "0.9.355.2027";
	
	//SVN Version
	static const char SVN_REVISION[] = "161";
	static const char SVN_DATE[] = "2010-03-13T14:31:21.388932Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 355;
	

}
#endif //VERSION_h
