/*
** create_list.c for create in /home/gwendal.bazin/CPE_2016_Pushswap
**
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.net>
**
** Started on  Sat Nov 19 11:05:43 2016 Gwendal Bazin
** Last update Mon Jan  9 22:01:36 2017 Gwendal Bazin
*/

#include <stdlib.h>
#include "my.h"

t_node		*create(int nb)
{
  t_node	*node;
  node = malloc(sizeof(t_node));
  node->nb = nb;
  node->next = NULL;
  node->previous = NULL;
  return (node);
}

void		append(t_node *node, int nb)
{
  while (node->next != NULL)
    node = node->next;
  node->next = malloc(sizeof(t_node));
  node->next->previous = node;
  node = node->next;
  node->nb = nb;
  node->next = NULL;
}

void	insert(t_node *node, int nb)
{
  t_node	*new;

  new = malloc(sizeof(t_node));
  new->nb = nb;
  new->next = node->next;
  node->next = new;
  new->previous = node;
  new->next->previous = new;
}

t_node	*getlast(t_node *node)
{
  while (node->next != NULL)
    node = node->next;
  return (node);
}
