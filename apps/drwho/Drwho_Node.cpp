// $Id$

#include "Drwho_Node.h"

Drwho_Node::Drwho_Node (const char *h_name, Drwho_Node *n)
     : next (n),
       inactive_count (0),
       active_count (0),
       key_name1 (h_name),
       key_name2 (0)
{}

Drwho_Node::Drwho_Node (void)
     : next (0),
       inactive_count (0),
       active_count (0),
       key_name1 (0),
       tty_name (0),
       idle_time (0),
       key_name2 (0)
{}

char *
Drwho_Node::get_login_name (void)
{
  return this->key_name1;
}

char *
Drwho_Node::set_login_name (const char *str)
{
  this->key_name1 = str;
  return str;
}

char *
Drwho_Node::get_real_name (void)
{
  return this->key_name2;
}

char *
Drwho_Node::set_real_name (const char *str)
{
  this->key_name2 = str;
  return str;
}

char *
Drwho_Node::get_host_name (void)
{
  return this->key_name1;
}

char *
Drwho_Node::set_host_name (const char *str)
{
  this->key_name1 = str;
  return str;
}

int
Drwho_Node::get_active_count (void)
{
  return this->active_count;
}

int
Drwho_Node::get_inactive_count (void)
{
  return this->inactive_count;
}

int
Drwho_Node::set_active_count (int count)
{
  return this->active_count = count;
}

int
Drwho_Node::set_inactive_count (int count)
{
  return this->inactive_count = count;
}

int
Drwho_Node::set_idle_time (int idle_time)
{
  return this->idle_time = idle_time;
}

int
Drwho_Node::get_idle_time (void)
{
  return this->idle_time;
}
