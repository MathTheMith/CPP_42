/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:41:38 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 20:50:19 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

class MutanStack
{
    private:
        

    public:
        MutanStack();
        MutanStack(const MutanStack& other);
        MutanStack& operator=(const MutanStack& other);
        ~MutanStack();
};

#endif