/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:39:22 by guillsan          #+#    #+#             */
/*   Updated: 2026/07/17 22:21:50 by guillsan         ###   ########.fr       */
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
