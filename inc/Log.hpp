/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:40:47 by guillsan          #+#    #+#             */
/*   Updated: 2026/07/17 21:17:24 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_HPP
#define LOG_HPP

#include <string>
#include <stdbool.h>

class Log
{
public:
	enum e_color { DFL, RED, YLW, GRN, BLUE, MAG, CYAN, COLOR_COUNT };
	enum e_flags
	{
		NONE           = 1 << 0, // 0001
		NO_ENDL        = 1 << 1, // 0010
		FLUSH          = 1 << 2, // 0100
		BOLD           = 1 << 3, // 1000
		ITALIC         = 1 << 4, // 0001 0000
		UNDERLINE      = 1 << 5, // 0010 0000
		RST_BOLD       = 1 << 6, // 0100 0000
		RST_ITALIC     = 1 << 7, // 1000 0000
		RST_UNDERLINE  = 1 << 8, // 0001 0000 0000
	};
	struct SFlagInfo
	{
		e_flags flag;
		const char* txt;	
	};
	
	~Log();
	
	template <typename T>
	Log& operator<<(const T& val);
	Log& operator<<(e_color color);
	Log& operator<<(e_flags flags);
	
	static Log print(e_color color = DFL, e_flags flags = NONE);
	static Log print(e_flags flags);
	
	static Log error(e_color color = RED, e_flags flags = NONE);
	static Log error(e_flags flags);
	
	static Log warn(e_color color = YLW, e_flags flags = NONE);
	static Log warn(e_flags flags);
	
private:
	static const char* const s_colors[COLOR_COUNT];
	static const SFlagInfo s_flagInfo[];
	
	enum e_logType { LOG_NORMAL, LOG_WARN, LOG_ERROR };
	std::ostream* _os;
	mutable bool _hasOwnership; 
	mutable e_flags _flags; 
	
	explicit Log(std::ostream& os, e_color color = DFL,
		e_flags flags = NONE, e_logType logType = LOG_NORMAL);

	Log();
	Log(const Log& other);
	Log& operator=(const Log& other);
};

#include "Log.tpp"

#endif /* LOG_HPP */
