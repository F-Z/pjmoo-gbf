#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 792;
	static const long REVISION = 4512;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 868;
	#define RC_FILEVERSION 0,9,792,4512
	#define RC_FILEVERSION_STRING "0, 9, 792, 4512\0"
	static const char FULLVERSION_STRING[] = "0.9.792.4512";
	
	//SVN Version
	static const char SVN_REVISION[] = "200";
	static const char SVN_DATE[] = "2010-03-26T01:00:40.705717Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 0;
	

}
#endif //VERSION_h
