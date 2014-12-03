#pragma once


#include <climits>




namespace rod {
namespace log {

	template< int LevelValue >
	struct Level
	{};


	namespace level
	{

		using All = Level< INT_MIN >;
		using Trace = Level< 0 >;
		using Debug = Level< 10000 >;
		using Info = Level< 20000 >;
		using Warn = Level< 30000 >;
		using Error = Level< 40000 >;
		using Fatal = Level< 50000 >;
		using Off = Level< INT_MAX >;
		
	}


	inline
	std::string
	toString( const level::Trace& )
	{
		return "TRACE";
	}

	inline
	std::string
	toString( const level::Debug& )
	{
		return "DEBUG";
	}

	inline
	std::string
	toString( const level::Info& )
	{
		return "INFO";
	}

	inline
	std::string
	toString( const level::Warn& )
	{
		return "WARN";
	}

	inline
	std::string
	toString( const level::Error& )
	{
		return "ERROR";
	}

	inline
	std::string
	toString( const level::Fatal& )
	{
		return "FATAL";
	}

}}