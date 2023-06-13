/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:02:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/13 13:17:10 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#include <errno.h>
  
void error_message(char *msg, int free_flag, char *line) ;
void all_functions_errors(char *line);
void single_quots_arr(char *line);

# endif