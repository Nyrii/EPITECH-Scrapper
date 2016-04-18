//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Mon Apr 18 16:14:00 2016 Florian Saurs
//

#ifndef CLIENTSOCKETLOCAL_HPP_
# define CLIENTSOCKETLOCAL_HPP_

# include "ASocket.hpp"

class	ClientSocketLocal : public ASocket
{
public:
  ClientSocketLocal(std::string);
  ~ClientSocketLocal();

  int		destroy() const;
  int		read(char &) const;
  int		write(char &) const;
};

#endif /* !CLIENTSOCKETLOCAL_HPP_ */
