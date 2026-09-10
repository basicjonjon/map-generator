/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PerlinNoise.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:55:50 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/10 18:36:12 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PerlinNoise.hpp"

PerlinNoise::PerlinNoise(int size) : size(size), perlinCells(this->size + 1, std::vector<Vector2>(this->size + 1, Vector2(0, 0)))
{
}

PerlinNoise::~PerlinNoise()
{
}

void deplacementPoint(float y, float x)
{
    int cellX = floor(x);
    int cellY = floor(y);
    float localX = x - cellX;
    float localY = y - cellY;

}

void PerlinNoise::genPerlinCells()
{
    float randValue;

    for (int y = 0; y < this->size + 1; y++)
    {
        for (int x = 0; x < this->size + 1; x++)
        {
            randValue = randomFloat(0, 2 * std::numbers::pi);
            this->perlinCells[y][x].x = cos(randValue);
            this->perlinCells[y][x].y = sin(randValue);
        }
    }
}

void PerlinNoise::printPerlinCells()
{
    for (int y = 0; y < this->size + 1; y++)
    {
        for (int x = 0; x < this->size + 1; x++)
        {
            std::cout << "(" << perlinCells[y][x].x << "," << perlinCells[y][x].y << ")";
            if (x != this->size)
            {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}
