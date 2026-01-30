/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:50:22 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 12:22:14 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename T2>
void iter(T &array, int length, void (*function)(T2)) {
    for (int i = 0; i < length; i++)
        function(array[i]);
}
