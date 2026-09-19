/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BacktrackingMaze.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:51:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/19 18:19:53 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BacktrackingMaze.hpp"

BacktrackingMaze::BacktrackingMaze(int size) : x(0), y(0), size(size), maze(this->size, std::vector<int>(this->size, 0)), wall(this->size, std::vector<int>(this->size, 15))
{
}

BacktrackingMaze::~BacktrackingMaze()
{
}

void BacktrackingMaze::generation()
{

    backtrack();
    printTabInt(this->maze, this->size);
    std::cout << std::endl;
    printTabInt(this->wall, this->size);
    std::cout << BRED << "------------------------" << NC << std::endl;
}

void BacktrackingMaze::backtrack()
{
    // (void) end;
    std::vector<t_move> move_list;
    int rand;
    int caseX = this->x;
    int caseY = this->y;

    move_list = checkMovePossibility(getMovePossibility());

    while (move_list.size() != 0)
    {
        for (size_t i = 0; i < move_list.size(); i++)
            std::cout << "[" << move_list[i].y << "][" << move_list[i].x << "]" << std::endl;
        rand = randomInt(0, move_list.size() - 1);
        t_move next_move = move_list[rand];
        setWall(next_move.y, next_move.x);
        if (this->maze[this->y][this->x] != EXPLORED)
            this->maze[this->y][this->x] = EXPLORED;
        this->y = next_move.y;
        this->x = next_move.x;
        move_list.erase(move_list.begin() + rand);
        printTabInt(maze, this->size);
        std::cout << std::endl;
        printTabInt(wall, this->size);
        std::cout << BRED << "------------------------" << NC << std::endl;
        backtrack();
        this->x = caseX;
        this->y = caseY;
    }
    this->maze[caseY][caseX] = VALID;
    printTabInt(maze, this->size);
    std::cout << std::endl;
    printTabInt(wall, this->size);
    std::cout << BRED << "------------------------" << NC << std::endl;
}

std::vector<t_move> BacktrackingMaze::getMovePossibility()
{
    std::vector<t_move> move_list;
    t_move move;

    if (y - 1 != -1)
    {
        move.x = this->x;
        move.y = this->y - 1;
        move_list.push_back(move);
    }
    if (y + 1 != this->size)
    {
        move.x = this->x;
        move.y = this->y + 1;
        move_list.push_back(move);
    }
    if (x - 1 != -1)
    {
        move.x = this->x - 1;
        move.y = this->y;
        move_list.push_back(move);
    }
    if (x + 1 != this->size)
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
        if (pos != EXPLORED && pos != VALID)
        {
            valid_move.push_back(move_list[i]);
        }
    }
    return (valid_move);
}

void BacktrackingMaze::setWall(int y, int x)
{
    std::cout << BYELLOW << this->wall[this->y][this->x] << NC << std::endl;
    if (y < this->y)
    {
        if (this->maze[this->y][this->x] == UNEXPLORED || this->maze[this->y - 1][this->x] != VALID)
        {
            this->wall[this->y][this->x] -= 1;
        }
        if (this->maze[this->y - 1][this->x] == UNEXPLORED)
        {
            this->wall[this->y - 1][this->x] -= 4;
        }
    }
    if (y > this->y)
    {
        if (this->maze[this->y][this->x] == UNEXPLORED || this->maze[this->y + 1][this->x] != VALID)
        {
            this->wall[this->y][this->x] -= 4;
        }
        if (this->maze[this->y + 1][this->x] == UNEXPLORED)
        {
            this->wall[this->y + 1][this->x] -= 1;
        }
    }
    if (x < this->x)
    {
        if (this->maze[this->y][this->x] == UNEXPLORED || this->maze[this->y][this->x - 1] != VALID)
        {
            this->wall[this->y][this->x] -= 8;
        }
        if (this->maze[this->y][this->x - 1] == UNEXPLORED)
        {
            this->wall[this->y][this->x - 1] -= 2;
        }
    }
    if (x > this->x)
    {
        if (this->maze[this->y][this->x] == UNEXPLORED || this->maze[this->y][this->x + 1] != VALID)
        {
            this->wall[this->y][this->x] -= 2;
        }
        if (this->maze[this->y][this->x + 1] == UNEXPLORED)
        {
            this->wall[this->y][this->x + 1] -= 8;
        }
    }
}


// void BacktrackingMaze::setWall(int y, int x)
// {
//     std::cout << BYELLOW << this->wall[this->y][this->x] << NC << std::endl;
//     if (y < this->y)
//     {
//         this->wall[this->y][this->x] &= ~NORTH;
//         this->wall[this->y - 1][this->x] &= ~SOUTH;
//     }
//     if (y > this->y)
//     {
//         this->wall[this->y][this->x] &= ~SOUTH;
//         this->wall[this->y + 1][this->x] &= ~NORTH;
//     }
//     if (x < this->x)
//     {
//         this->wall[this->y][this->x] &= ~WEST;
//         this->wall[this->y][this->x - 1] &= ~EAST;
//     }
//     if (x > this->x)
//     {
//         this->wall[this->y][this->x] &= ~EAST;
//         this->wall[this->y][this->x + 1] &= ~WEST;
//     }
// }