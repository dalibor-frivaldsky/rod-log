#pragma once


#include <rod/log/Level.hpp>
#include <rod/log/Blob.hpp>




namespace rod {
namespace log
{

	template< typename ClassToLog >
	class Logger
	{
	public:
		Blob< ClassToLog >
		operator () ( int ) const
		{
			return Blob< ClassToLog >();
		}
	};
	
}}