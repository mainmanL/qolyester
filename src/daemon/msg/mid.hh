// Copyright (C) 2003, 2004, 2005 Laboratoire de Recherche en Informatique

// This file is part of Qolyester.

// Qolyester is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// Qolyester is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

///
/// @file   msg/mid.hh
/// @author Ignacy Gawedzki
/// @date   Tue Mar 16 17:33:23 2004
///
/// @brief  MID message declaration
///
/// Implemented in accordance with RFC 3626, section 5.1.
///

#include "msg/message.hh"

#ifndef QOLYESTER_DAEMON_MSG_MID_HH
# define QOLYESTER_DAEMON_MSG_MID_HH 1

namespace olsr {

  namespace msg {

    ///
    /// @class MIDMessage
    /// @brief MID message class
    ///
    class MIDMessage : public Message {
      typedef MIDMessage	This;
      typedef Message		Super;
    public:

      ///
      /// The default constructor
      ///
      inline MIDMessage();

      ///
      /// The constructor
      /// @arg d	%Message data buffer
      ///
      inline MIDMessage(const utl::Data& d, const address_t&);

      ///
      /// The destructor
      ///
      virtual ~MIDMessage() {}

      ///
      /// The dumping method
      /// @arg d		Destination data buffer
      /// @arg interface	Source interface address of the packet
      /// @return		true if the message is to be resent
      ///
      virtual inline bool	dump(utl::Data&, const address_t&) const;

      ///
      /// The parsing routine
      /// @arg d		%Message data buffer
      /// @arg mh		%Message header
      ///
      static inline void	parse(const utl::ConstData&,
				      const Message::header&);

      static const ::size_t	min_length = ADDRESS_SIZE; ///< Minimum length of a MID message

    private:
      utl::Data		_data; ///< The message data buffer
    };

  } // namespace msg

} // namespace olsr

# include "mid.hxx"

#endif // ! QOLYESTER_DAEMON_MSG_MID_HH
