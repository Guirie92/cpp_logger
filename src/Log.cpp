/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:42:57 by guillsan          #+#    #+#             */
/*   Updated: 2026/07/17 21:12:58 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"

const char* const Log::s_colors[] =
{
	"\033[39m", // DFL (white)
	"\033[31m", // RED
	"\033[33m", // YELLOW
	"\033[32m", // GREEN
	"\033[34m", // BLUE
	"\033[35m", // MAGENTA
	"\033[36m"  // CYAN
};
const Log::SFlagInfo Log::s_flagInfo[] = 
{
	{ Log::NONE,          "\033[0m" },
	{ Log::NO_ENDL,       ""         },
	{ Log::FLUSH,         ""         },
	{ Log::BOLD,          "\033[1m"  },
	{ Log::ITALIC,        "\033[3m"  },
	{ Log::UNDERLINE,     "\033[4m"  },
	{ Log::RST_BOLD,      "\033[22m" },
	{ Log::RST_ITALIC,    "\033[23m" },
	{ Log::RST_UNDERLINE, "\033[24m" }
};

/* ------------------------------ LOG STREAM -------------------------------- */
Log::Log() {}

Log::Log(std::ostream& os, e_color color, e_flags flags,
	e_logType logType)
:
_os(&os),
_hasOwnership(true),
_flags(flags)
{
	size_t len = sizeof(s_flagInfo)/sizeof(SFlagInfo);
	for (size_t i = 0; i < len; i++)
	{
		if (flags & s_flagInfo[i].flag)
			*(_os) << s_flagInfo[i].txt;
	}
	*(_os) << s_colors[color];
	if (logType == LOG_ERROR)
		*(_os) << "[ERROR]: ";
	else if (logType == LOG_WARN)
		*(_os) << "[WARNING]: ";
		
}

Log::Log(const Log& other)
:
_hasOwnership(true),
_flags(other._flags)
{
	other._hasOwnership = false; // needs mutable
	other._flags = NONE;         // needs mutable
}

Log& Log::operator=(const Log& other)
{
	if (this == &other)
		return *this;
	return *this;
}

Log::~Log()
{
	if (_hasOwnership)
	{
		*(_os) << s_colors[DFL];
		if (!(_flags & NO_ENDL))
			*(_os) << "\n";
		if (_flags & FLUSH)
			(*(_os)).flush();
	}
}

Log& Log::operator<<(e_color color)
{
	*(_os) << s_colors[color];
	return *this;
}

Log& Log::operator<<(e_flags flags)
{
	size_t len = sizeof(s_flagInfo)/sizeof(SFlagInfo);
	for (size_t i = 0; i < len; i++)
	{
		if (flags & s_flagInfo[i].flag)
			*(_os) << s_flagInfo[i].txt;
	}
	return *this;
}

/* ---------------------------------- LOG ----------------------------------- */

// Log::Log(const Log& other)
// {
// 	*this = other;
// }

// Log& Log::operator=(const Log &other)
// {
// 	if (this == &other)
// 		return *this;
// 	return *this;
// }

// Log::~Log() {}

/* print */
Log Log::print(e_color color, e_flags flags)
{
	return Log(std::cout, color, flags, LOG_NORMAL);
}

Log Log::print(e_flags flags)
{
	return Log(std::cout, DFL, flags, LOG_NORMAL);
}

/* error */
Log Log::error(e_color color, e_flags flags)
{
	return Log(std::cerr, color, flags, LOG_ERROR);
}

Log Log::error(e_flags flags)
{
	return Log(std::cerr, RED, flags, LOG_ERROR);
}

/* warning */
Log Log::warn(e_color color, e_flags flags)
{
	return Log(std::cout, color, flags, LOG_WARN);
}

Log Log::warn(e_flags flags)
{
	return Log(std::cout, YLW, flags, LOG_WARN);
}
