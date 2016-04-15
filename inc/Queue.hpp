//
// Queue.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 23:32:47 2016 guillaume wilmot
// Last update Thu Apr 14 17:43:40 2016 guillaume wilmot
//

#ifndef QUEUE_HPP_
# define QUEUE_HPP_

# include "Information.hh"

class	ThreadPool;

typedef struct s_queue  t_queue;

typedef struct          s_args {
  ThreadPool            *callback;
  Information           order;
  std::string           file;
}                       t_args;

struct                  s_queue {
  t_args                *args;
  void                  *(*ptr)(void *);
};

#endif /*!QUEUE_HPP_ */