/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BacktrackingMaze.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:51:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/17 16:16:58 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BacktrackingMaze.hpp"

BacktrackingMaze::BacktrackingMaze(int size) : size(size + 2), maze(this->size, std::vector<int>(this->size))
{
}

BacktrackingMaze::~BacktrackingMaze()
{
}

void BacktrackingMaze::generation()
{
    initMaze();
}

void BacktrackingMaze::initMaze()
{
    for (int y = 0; y < this->size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (y == 0 || (y != 0 && (x == 0 || x == this->size - 1)))
                this->maze[y][x] = WALL;
            else
                this->maze[y][x] = UNEXPLORED;
        }
    }
}