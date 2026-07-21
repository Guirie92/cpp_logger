/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:39:22 by guillsan          #+#    #+#             */
/*   Updated: 2026/07/21 17:17:53 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_TPP
#define LOG_TPP

template <typename T>
inline Log& Log::operator<<(const T &val)
{
	*(_os) << val;
	return *this;
}

#endif /* LOG_TPP */