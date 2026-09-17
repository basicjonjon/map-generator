/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:59:27 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/21 19:38:27 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

template <typename T>
class Vector2
{
public:
    T x;
    T y;

    Vector2(T x, T y) : x(x), y(y) {}
    ~Vector2() = default;
};
#endif