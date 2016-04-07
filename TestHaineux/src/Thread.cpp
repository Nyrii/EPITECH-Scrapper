//
// Thread.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 20:57:09 2016 guillaume wilmot
// Last update Wed Apr  6 23:39:24 2016 guillaume wilmot
//

#include <pthread.h>
#include "Thread.hpp"

Thread::Thread()
{
  _started = false;
}

void		Thread::start(void *(*ptr)(void *), void *arg)
{
  pthread_create(&_thread, NULL, ptr, arg);
  _started = true;
}

void		Thread::join()
{
  pthread_join(_thread, NULL);
}

bool		Thread::getStatus() const
{
  return (_started);
}
