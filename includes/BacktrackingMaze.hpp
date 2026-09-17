/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BacktrackingMaze.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:51:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/17 18:25:05 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKINGMAZE_HPP
#define BACKTRACKINGMAZE_HPP

#include "mapGenerator.hpp"

typedef struct s_movePossibility
{
    int x;
    int y;
} t_move;

typedef struct s_wallPosition
{
    int y1;
    int x1;
    int y2;
    int x2;
} t_wallPos;

enum
{
    WALL,
    UNEXPLORED,
    EXPLORED,
    VALID,
    POT_WALL,
};

enum 
{
    TOP,
    RIGHT,
    BOT,
    LEFT,
};

class BacktrackingMaze
{
private:
    int x;
    int y;
    int size;
    std::vector<std::vector<int>> maze;

public:
    BacktrackingMaze(int size);
    ~BacktrackingMaze();

    void generation();
    void initMaze();
    void backtrack(int end);
    std::vector<t_move> getMovePossibility();
    std::vector<t_move> checkMovePossibility( std::vector<t_move> move_list);
    int getNextMoveDirection(int y, int x);
};

#endif