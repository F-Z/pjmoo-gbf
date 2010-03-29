#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 797;
	static const long REVISION = 4532;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 874;
	#define RC_FILEVERSION 0,9,797,4532
	#define RC_FILEVERSION_STRING "0, 9, 797, 4532\0"
	static const char FULLVERSION_STRING[] = "0.9.797.4532";
	
	//SVN Version
	static const char SVN_REVISION[] = "200";
	static const char SVN_DATE[] = "2010-03-26T01:00:40.705717Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 5;
	

}
#endif //VERSION_h
