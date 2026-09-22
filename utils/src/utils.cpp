/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:29:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/22 16:58:35 by jle-doua         ###   ########.fr       */
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

void printTabInt(std::vector<std::vector<int>> tab)
{
    for (size_t i = 0; i < tab.size(); i++)
    {
        for (size_t y = 0; y < tab.size(); y++)
            std::cout << tab[i][y] << " ";
        std::cout << std::endl;
    }
}

void printTabInFile(std::string filename, std::vector<std::vector<int>> tab)
{
    std::ofstream outfile(filename);

    if (!outfile.is_open())
    {
        std::cout << BRED << "ERROR : can't create file" << NC << std::endl;
        return;
    }
    for (size_t i = 0; i < tab.size(); i++)
    {
        for (size_t y = 0; y < tab.size(); y++)
            outfile << tab[i][y] << " ";
        outfile << std::endl;
    }
    outfile << std::endl;
    outfile.close();
}