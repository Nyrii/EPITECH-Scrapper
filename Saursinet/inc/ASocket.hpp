//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Wed Apr  6 13:33:00 2016 Florian Saurs
// Last update Mon Apr 18 16:31:26 2016 Florian Saurs
//

#ifndef SOCKET_HPP_
# define SOCKET_HPP_

# include <errno.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <sys/un.h>
# include <iostream>

# include "Com.hpp"

# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define closesocket(s) close (s)
# define PORT 8080

class	ASocket : public Com
{
protected:
  int			_socket;
  int			_clientSocket;
  int			_socketError;

  socklen_t		_clientReceiveSize;

  sockaddr_in		_internetSocket;
  sockaddr_in		_clientInternetSocket;

  sockaddr_un		_unixSocket;
  sockaddr_un		_clientUnixSocket;

  std::string		_path;

public:
  virtual		~ASocket() {};
  virtual int		destroy() const = 0;
  virtual int		read(char&) const = 0;
  virtual int		write(char &) const = 0;
};

#endif /* !SOCKET_HPP_ */
