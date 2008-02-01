#include <fstream>
#include <iostream>
#include "Utils.h"

namespace Passenger {

using namespace std;

ostream *_debugStream = NULL;

void
initDebugging(const char *logFile) {
	#ifdef PASSENGER_DEBUG
		if (logFile != NULL) {
			ostream *stream = new ofstream(logFile, ios_base::out | ios_base::app);
			if (stream->fail()) {
				delete stream;
			} else {
				_debugStream = stream;
			}
		} else {
			_debugStream = &cerr;
		}
	#endif
}

} // namespace Passenger
