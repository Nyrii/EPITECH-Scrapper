//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Mon Apr 18 16:14:04 2016 Florian Saurs
//

#ifndef SERVEURSOCKETLOCAL_HPP_
# define SERVEURSOCKETLOCAL_HPP_

# include "ASocket.hpp"

class	ServeurSocketLocal : public ASocket
{
public:
  ServeurSocketLocal(std::string);
  ~ServeurSocketLocal();

  int		destroy() const;
  int		read(char &) const;
  int		write(char &) const;
};

#endif /* !SERVEURSOCKETLOCAL_HPP_ */
