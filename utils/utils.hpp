/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:28:59 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/22 16:58:29 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>
#include <iostream>
#include <fstream>

#include "Vector2.hpp"
#include "color.h"

int randomInt(int min, int max);
float randomFloat(float min, float max);

void printTabInt(std::vector<std::vector<int>> tab, int size);
void printTabInFile(std::string filename, std::vector<std::vector<int>> tab);

#endif