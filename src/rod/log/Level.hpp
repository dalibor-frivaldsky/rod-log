#pragma once


#include <climits>




namespace rod {
namespace log {
namespace level
{

	enum
	{
		All = INT_MIN,
		Trace = 0,
		Debug = 10000,
		Info = 20000,
		Warn = 30000,
		Error = 40000,
		Fatal = 50000,
		Off = INT_MAX
	};
	
}}}