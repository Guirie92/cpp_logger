/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:40:47 by guillsan          #+#    #+#             */
/*   Updated: 2026/07/20 14:45:21 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_HPP
#define LOG_HPP

#include <string>
#include <stdbool.h>

class Log
{
public:
	enum Color { DEFAULT, RED, YLW, GRN, BLUE, MAG, CYAN, COLOR_COUNT };
	enum Flags
	{
		NONE          = 1 << 0, // 0001
		NO_ENDL       = 1 << 1, // 0010
		FLUSH         = 1 << 2, // 0100
		BOLD          = 1 << 3, // 1000
		ITALIC        = 1 << 4, // 0001 0000
		UNDERLINE     = 1 << 5, // 0010 0000
		RST_BOLD      = 1 << 6, // 0100 0000
		RST_ITALIC    = 1 << 7, // 1000 0000
		RST_UNDERLINE = 1 << 8, // 0001 0000 0000
	};
	
	~Log();
	
	template <typename T>
	Log& operator<<(const T& val);
	Log& operator<<(Color color);
	Log& operator<<(Flags flags);
	
	static Log print(Color color = DEFAULT, Flags flags = NONE);
	static Log print(Flags flags);
	
	static Log error(Color color = RED, Flags flags = NONE);
	static Log error(Flags flags);
	
	static Log warn(Color color = YLW, Flags flags = NONE);
	static Log warn(Flags flags);
	
private:
	struct FlagInfo
	{
		Flags flag;
		const char* txt;
	};
	enum LogType { LOG_NORMAL, LOG_WARN, LOG_ERROR };
	static const char* const s_colors[COLOR_COUNT];
	static const FlagInfo s_flagInfo[];
	
	std::ostream* _os;
	mutable bool _hasOwnership;
	mutable Flags _flags;
	
	Log();
	explicit Log(std::ostream& os, Color color = DEFAULT,
		Flags flags = NONE, LogType logType = LOG_NORMAL);
	Log(const Log& other);
	Log& operator=(const Log& other);
};

Log::Flags operator|(Log::Flags lhs, Log::Flags rhs);

#include "Log.tpp"

#endif /* LOG_HPP */
