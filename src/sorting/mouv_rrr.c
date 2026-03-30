/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 21:18:29 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/30 21:31:05 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
/*
rotate :
ra -> first node is put at the end of the list, 2nd node takes first place 
and all the others node mouve up the chaine too in stackA
rb ->first node is put at the end of the list, 2nd node takes first place 
and all the others node mouve up the chaine too in stackB
rr -> rr and rb at the same time


reverse rotate rr
rra -> last node is put at the begenning of the list,
and all the others node mouve down the chaine too in stackA
rrb -> last node is put at the begenning of the list,
and all the others node mouve down the chaine too in stackB
rrr -> rrr and rrb at the same time
*/

