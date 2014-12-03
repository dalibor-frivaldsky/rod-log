#pragma once


#if defined( _MSC_VER )
#include <Windows.h>
#endif

#include <iostream>

#include <rod/common/TypeName.hpp>




namespace rod {
namespace log {

	template< typename ClassToLog >
	struct Blob
	{
		void
		operator << ( const std::string& message )
		{
			#if defined( _MSC_VER )
			std::string		logMessage;
			logMessage += "DEBUG ";
			logMessage += rod::common::typeName< ClassToLog >();
			logMessage += " ";
			logMessage += message;
			logMessage += '\n';
			OutputDebugString( std::wstring( logMessage.begin(), logMessage.end() ).c_str() );
			#else
			std::clog
				<< "DEBUG "
				<< rod::common::typeName< ClassToLog >()
				<< " "
				<< message
				<< std::endl;
			#endif
		}
	};
	
}}