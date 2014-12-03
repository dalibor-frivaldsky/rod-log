#pragma once


#include <string>

#include <rod/common/TypeName.hpp>




namespace rod {
namespace log
{

	template< typename Class >
	struct ClassName
	{};


	template< typename Class >
	std::string
	toString( const ClassName< Class >& )
	{
		return rod::common::typeName< Class >();
	}
	
}}