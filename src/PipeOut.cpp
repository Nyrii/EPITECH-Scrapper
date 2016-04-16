//
// PipeOut.cpp for PipeOut in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:05:28 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr 16 15:29:47 2016 Nyrandone Noboud-Inpeng
//

#include <unistd.h>
#include <fcntl.h>
#include "PipeOut.hh"
#include "CommunicationError.hh"

PipeOut::PipeOut(std::string path) : _path(path)
{
  _readFd = (open(_path.c_str(), O_RDONLY | O_NONBLOCK));
  if (_readFd == -1)
    throw CommunicationError("Error: opening of a named pipe to read in it failed.");
}

PipeOut::~PipeOut()
{
  this->destroy();
}

PipeOut::PipeOut(PipeOut const &src)
{
  _readFd = src.getReadFd();
}

PipeOut		&PipeOut::operator=(PipeOut const &src)
{
  if (this != &src)
    {
      _readFd = src.getReadFd();
    }
  return (*this);
}

void		PipeOut::destroy() const
{
  close(_readFd);
}

int		PipeOut::write(t_processState &) const
{
  return (-1);
}

int			PipeOut::read(t_processState &state)
{
  int			return_value;
  struct timeval	timeout;
  // if ((return_value = ::read(_readFd, &state, sizeof(t_processState))) <= 0)
  //   {
  //     std::cout << return_value << std::endl;
  //     return (-1);
  //   }
  // return (0);
  FD_ZERO(&_readSelect);
  FD_SET(_readFd, &_readSelect);
  timeout.tv_sec = 5;
  timeout.tv_usec = 0;
  return_value = select(_readFd + 1, &_readSelect, NULL, NULL, &timeout);
  if (return_value > 0)
    {
      if (FD_ISSET(_readFd, &_readSelect))
	{
	  if (::read(_readFd, &state, sizeof(t_processState)) <= 0)
	    return (-1);
	  return (0);
	}
    }
  else if (return_value == 0)
    throw CommunicationError("Timeout");
  return (-1);
}

int		PipeOut::getReadFd() const
{
  return (_readFd);
}

void		PipeOut::setReadFd(int const &newFd)
{
  _readFd = newFd;
}

int		PipeOut::getWriteFd() const
{
  return (-1);
}

void		PipeOut::setWriteFd(int const &)
{

}
