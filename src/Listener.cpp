//
// Listener.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:58:38 2016 guillaume wilmot
// Last update Sat Apr 16 15:03:44 2016 guillaume wilmot
//

/**/
#include <unistd.h>
/**/
#include <cstring>
#include <iostream>
#include "Listener.hpp"
#include "ReadAndFind.hh"

Listener::Listener()
{
  _com = NULL;
  _nbThread = 0;
  _timer.setTime(5);
}

void			Listener::init(int nbThread, ICommunication *com)
{
  _nbThread = nbThread;
  _com = com;
}

t_processState		*Listener::getTask(ThreadPool &threadPool)
{
  t_processState	*struc;

  struc = new t_processState;
  memset(struc, 0, sizeof(*struc));
  if (_com->read(*struc) == -1)
    std::cout << "Read Fail" << std::endl;
  if (struc->state == ASSIGN)
    return (struc);
  if (struc->state == FREE)
    {
      if (threadPool.getQueueSize() < _nbThread * 2)
	struc->free = true;
      else
	struc->free = false;
      _com->write(*struc);
    }
  return (NULL);
}

bool			Listener::timeOut()
{
  if (_timer.isElapsed())
    return (true);
  return (false);
}

void			*Listener::listen()
{
  ThreadPool		threadPool(_nbThread);
  t_processState	*struc;

  threadPool.init(&CondThread::begin);
  while (!timeOut())
    if ((struc = getTask(threadPool)))
      {
	_timer.setTime(5);
	threadPool.queue(&ReadAndFind::execute, struc->info, struc->fileName);
	sleep(1);
      }
  struc = new t_processState;
  memset(struc, 0, sizeof(*struc));
  struc->state = DEAD;
  _com->write(*struc);
  delete struc;
  return (NULL);
}

void			*Listener::start(void *args)
{
  Listener		_this;
  t_processArgs		*tab;

  tab = reinterpret_cast<t_processArgs *>(args);
  _this.init(tab->nbThread, tab->com);
  return (_this.listen());
}
