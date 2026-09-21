/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BacktrackingMaze.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:51:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/21 19:30:07 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BacktrackingMaze.hpp"

BacktrackingMaze::BacktrackingMaze(int size) : x(0), y(0), size(size), maze(this->size, std::vector<int>(this->size, 0)), wall(this->size, std::vector<int>(this->size, 15)), finalMaze((this->size * 2) + 1, std::vector<int>((this->size * 2) + 1, 0))
{
}

BacktrackingMaze::~BacktrackingMaze()
{
}

void BacktrackingMaze::generation()
{
    backtrack();
    creatMaze();
    printTabInt(finalMaze, (this->size * 2) + 1);
}

void BacktrackingMaze::backtrack()
{
    int rand;
    int caseX = this->x;
    int caseY = this->y;
    std::vector<t_move> move_list;

    move_list = checkMovePossibility(getMovePossibility());
    while (move_list.size() != 0)
    {
        rand = randomInt(0, move_list.size() - 1);
        t_move next_move = move_list[rand];
        if (this->maze[next_move.y][next_move.x] == UNEXPLORED)
            setWalls(next_move.y, next_move.x);
        if (this->maze[this->y][this->x] != EXPLORED)
            this->maze[this->y][this->x] = EXPLORED;
        this->y = next_move.y;
        this->x = next_move.x;
        move_list.erase(move_list.begin() + rand);
        backtrack();
        this->x = caseX;
        this->y = caseY;
    }
    this->maze[caseY][caseX] = VALID;
}

std::vector<t_move> BacktrackingMaze::getMovePossibility()
{
    std::vector<t_move> move_list;

    if (y - 1 != -1)
        move_list.push_back(t_move(this->x, this->y - 1));
    if (y + 1 != this->size)
        move_list.push_back(t_move(this->x, this->y + 1));
    if (x - 1 != -1)
        move_list.push_back(t_move(this->x - 1, this->y));
    if (x + 1 != this->size)
        move_list.push_back(t_move(this->x + 1, this->y));
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

void BacktrackingMaze::setWalls(int y, int x)
{
    if (y < this->y)
    {
        this->wall[this->y][this->x] &= ~NORTH;
        this->wall[y][x] &= ~SOUTH;
    }
    else if (y > this->y)
    {
        this->wall[this->y][this->x] &= ~SOUTH;
        this->wall[y][x] &= ~NORTH;
    }
    else if (x < this->x)
    {
        this->wall[this->y][this->x] &= ~WEST;
        this->wall[y][x] &= ~EAST;
    }
    else if (x > this->x)
    {
        this->wall[this->y][this->x] &= ~EAST;
        this->wall[y][x] &= ~WEST;
    }
}

void BacktrackingMaze::creatMaze()
{
    int wallY = 1;
    int wallX;

    buildArroundWall();
    for (int y = 0; y < this->size; y++)
    {
        wallX = 1;
        for (int x = 0; x < this->size; x++)
        {
            this->finalMaze[wallY][wallX] = 2;
            if (this->wall[y][x] & EAST)
                this->finalMaze[wallY][wallX + 1] = 1;
            else
                this->finalMaze[wallY][wallX + 1] = 2;
            if (this->wall[y][x] & SOUTH)
                this->finalMaze[wallY + 1][wallX] = 1;
            else
                this->finalMaze[wallY + 1][wallX] = 2;
            wallX += 2;
        }
        wallY += 2;
    }
    patchMaze();
}

void BacktrackingMaze::buildArroundWall()
{
    for (int y = 0; y < (this->size * 2) + 1; y++)
    {
        for (int x = 0; x < (this->size * 2) + 1; x++)
        {
            if (y == 0 || y == (this->size * 2) || x == 0 || x == (this->size * 2))
            {
                this->finalMaze[y][x] = 1;
            }
        }
    }
}

void BacktrackingMaze::patchMaze()
{
    for (int y = 0; y < this->size * 2; y++)
    {
        for (int x = 0; x < this->size * 2; x++)
        {
            if (this->finalMaze[y][x] == 0)
                this->finalMaze[y][x] = 1;
        }
    }
}