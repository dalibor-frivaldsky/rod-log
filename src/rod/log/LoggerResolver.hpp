#pragma once


#include <rod/annotation/Resolver.hpp>

#include <rod/log/Logger.hpp>




namespace rod {
namespace log
{

	namespace detail
	{

		template< typename LoggerType >
		struct LoggerSelector;

		template< typename ClassToLog >
		struct LoggerSelector< Logger< ClassToLog > >
		{
			enum { r = true };
		};

		template< typename OtherType >
		struct LoggerSelector
		{
			enum { r = false };
		};
		
	}


	struct LoggerResolver
	{
		using Resolver = rod::annotation::Resolver< detail::LoggerSelector >;

		template< typename LoggerType, typename Context >
		static
		LoggerType
		resolve( Context& )
		{
			return LoggerType();
		}
	};
	
}}