/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BacktrackingMaze.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:51:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/17 18:25:06 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BacktrackingMaze.hpp"

BacktrackingMaze::BacktrackingMaze(int size) : x(1), y(1), size(size + 2), maze(this->size, std::vector<int>(this->size))
{
}

BacktrackingMaze::~BacktrackingMaze()
{
}

void BacktrackingMaze::generation()
{
    initMaze();
    backtrack(5);
    printTabInt(this->maze, this->size);
}

void BacktrackingMaze::initMaze()
{
    for (int y = 0; y < this->size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if ((y == 0 || y == this->size - 1) || (y != 0 && (x == 0 || x == this->size - 1)))
                this->maze[y][x] = WALL;
            else
                this->maze[y][x] = UNEXPLORED;
        }
    }
}

void BacktrackingMaze::backtrack(int end)
{
    std::vector<t_move> move_list;
    int rand;

    move_list = checkMovePossibility(getMovePossibility());

    // for (size_t i = 0; i < move_list.size(); i++)
    // {
    //     std::cout << "[" << move_list[i].y << "][" << move_list[i].x << "]" << std::endl;
    // }
    // while (move_list.size() != 0)
    // {
    rand = randomInt(0, move_list.size() - 1);
    t_move next_move = move_list[rand];
    std::cout << BBLUE << "next move : [" << next_move.y << "][" << next_move.x << "]" << NC << std::endl;
    move_list.erase(move_list.begin() + rand);
    this->maze[this->y][this->x] = EXPLORED;
    this->y = next_move.y;
    this->x = next_move.x;
    if (end != 0)
    {
        backtrack(end - 1);
    }
    
    // for (size_t i = 0; i < move_list.size(); i++)
    // {
    //     std::cout << "[" << move_list[i].y << "][" << move_list[i].x << "]" << std::endl;
    // }
    // }
}

std::vector<t_move> BacktrackingMaze::getMovePossibility()
{
    std::vector<t_move> move_list;
    t_move move;

    if (y - 1 != 0)
    {
        move.x = this->x;
        move.y = this->y - 1;
        move_list.push_back(move);
    }
    if (y + 1 != this->size - 1)
    {
        move.x = this->x;
        move.y = this->y + 1;
        move_list.push_back(move);
    }
    if (x - 1 != 0)
    {
        move.x = this->x - 1;
        move.y = this->y;
        move_list.push_back(move);
    }
    if (x + 1 != this->size - 1)
    {
        move.x = this->x + 1;
        move.y = this->y;
        move_list.push_back(move);
    }
    return (move_list);
}

std::vector<t_move> BacktrackingMaze::checkMovePossibility(std::vector<t_move> move_list)
{
    int pos;
    std::vector<t_move> valid_move;

    for (size_t i = 0; i < move_list.size(); i++)
    {
        pos = this->maze[move_list[i].y][move_list[i].x];
        std::cout << BRED << pos << NC << std::endl;
        if (pos != WALL && pos != EXPLORED && pos != VALID)
        {
            // std::cout << BGREEN << "pos " << pos << std::endl;
            valid_move.push_back(move_list[i]);
        }
    }
    return (valid_move);
}

int BacktrackingMaze::getNextMoveDirection(int y, int x)
{
    if (y > this->y)
    {
        
    }
}