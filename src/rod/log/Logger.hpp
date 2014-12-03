#pragma once


#include <utility>

#include <rod/log/ClassName.hpp>
#include <rod/log/ConsoleWriter.hpp>
#include <rod/log/Level.hpp>




namespace rod {
namespace log
{

	template< typename ClassToLog >
	class Logger
	{
	public:
		template< typename Level, typename... LogElement >
		void
		operator () ( const Level& level, LogElement&&... logElement ) const
		{
			ConsoleWriter()(
				toString( level ),
				toString( ClassName< ClassToLog >() ),
				std::forward< LogElement >( logElement )... );
		}

		template< typename... LogElement >
		void
		trace( LogElement&&... logElement ) const
		{
			(*this)( level::Trace(), std::forward< LogElement >( logElement )... );
		}

		template< typename... LogElement >
		void
		debug( LogElement&&... logElement ) const
		{
			(*this)( level::Debug(), std::forward< LogElement >( logElement )... );
		}

		template< typename... LogElement >
		void
		info( LogElement&&... logElement ) const
		{
			(*this)( level::Info(), std::forward< LogElement >( logElement )... );
		}

		template< typename... LogElement >
		void
		warn( LogElement&&... logElement ) const
		{
			(*this)( level::Warn(), std::forward< LogElement >( logElement )... );
		}

		template< typename... LogElement >
		void
		error( LogElement&&... logElement ) const
		{
			(*this)( level::Error(), std::forward< LogElement >( logElement )... );
		}

		template< typename... LogElement >
		void
		fatal( LogElement&&... logElement ) const
		{
			(*this)( level::Fatal(), std::forward< LogElement >( logElement )... );
		}
	};
	
}}