/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:39:22 by guillsan          #+#    #+#             */
/*   Updated: 2026/07/17 21:05:03 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"
#include <iostream>

template <typename T>
inline Log& Log::operator<<(const T &val)
{
	*(_os) << val;
	return *this;
}

inline Log::e_flags operator|(Log::e_flags lhs, Log::e_flags rhs)
{
	return static_cast<Log::e_flags>(
		static_cast<int>(lhs) | static_cast<int>(rhs)
	);
}
