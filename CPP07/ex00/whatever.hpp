/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:50:22 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/14 14:00:13 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

template <typename T>
T min(T a, T b) {
    if (a <= b)
        return (a);
    return b;
}

template <typename T>
T max(T a, T b) {
    if (a <= b)
        return (b);
    return a;
}