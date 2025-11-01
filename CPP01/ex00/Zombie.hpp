/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 04:19:20 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 04:19:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {

private:
    std::string name;

public:
    Zombie(std::string zombieName);
    ~Zombie(void);
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif