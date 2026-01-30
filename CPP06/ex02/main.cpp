/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:51:25 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 11:16:55 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    srand((unsigned)time(0));
    Base base;
    Base* obj = base.generate();
    base.identify(obj);
    base.identify(*obj);
    delete obj;
}