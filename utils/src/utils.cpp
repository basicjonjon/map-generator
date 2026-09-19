/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:29:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/19 17:07:00 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int randomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

float randomFloat(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(generator);
}

void printTabInt(std::vector<std::vector<int>> tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int y = 0; y < size; y++)
        {
            int pos = tab[i][y];
            if (pos == 1)
                std::cout << BBLUE;
            if (pos == 2)
                std::cout << BGREEN;
            std::cout << tab[i][y] << " ";
            std::cout << NC;
        }
        std::cout << std::endl;
    }
}