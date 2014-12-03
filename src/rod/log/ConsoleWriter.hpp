#pragma once


#if defined( _MSC_VER )
#include <Windows.h>
#endif

#include <iostream>




namespace rod {
namespace log {

	struct ConsoleWriter
	{
		inline
		void
		operator () (
			const std::string& level,
			const std::string& cls,
			const std::string& message )
		{
			#if defined( _MSC_VER )
			std::string		logMessage;
			logMessage += level;
			logMessage += " ";
			logMessage += cls;
			logMessage += " ";
			logMessage += message;
			logMessage += '\n';
			OutputDebugString( std::wstring( logMessage.begin(), logMessage.end() ).c_str() );
			#else
			std::clog
				<< level
				<< " "
				<< cls
				<< " "
				<< message
				<< std::endl;
			#endif
		}
	};
	
}}