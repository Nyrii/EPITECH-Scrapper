//
// namedPipe.hh for namedPipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:18:42 2016 Nyrandone Noboud-Inpeng
// Last update Wed Apr  6 16:12:52 2016 Nyrandone Noboud-Inpeng
//

#ifndef NAMEDPIPE_HH_
# define NAMEDPIPE_HH_

# include <map>
# include <vector>
# include "ICommunication.hpp"

class					namedPipe : public ICommunication
{
public:
  namedPipe();
  ~namedPipe();
  namedPipe(namedPipe const &);
  namedPipe				&operator=(namedPipe const &);

  int					create(int);
  int					destroy() const;
  std::string				read() const;
  int					write(std::string const &) const;

  int					getId() const;

  private:
  int					_id;
  std::string				_path;
};

std::ostream				&operator<<(std::ostream &, namedPipe const &);
std::string const			&operator>>(std::string const &command, namedPipe const &namedPipe);

#endif /* !NAMEDPIPE_HH_ */