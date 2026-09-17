/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:28:59 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/17 16:23:51 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>
#include <iostream>

#include "Vector2.hpp"
#include "color.h"

int randomInt(int min, int max);
float randomFloat(float min, float max);

void printTabInt(std::vector<std::vector<int>> tab, int size);



#endif