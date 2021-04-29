/*
 * event.h
 * Copyright (c) 2019 Mark Maloof.  All Rights Reserved.  See LICENSE.
 */

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "datetime.h"

/**
 * A class for storing information about a calendar event.  An Event
 * consists of a status, a unique identifier, a name, a location,
 * a start date and time, an end date and time, and a date and time
 * of the event's last modification.  The class include methods for
 * reading and writing events in both external and internal formats.
 * That is, the internal format consists of all information, which
 * is required for transfer, storage, and synchronization.  The external
 * format consists of information required for a user view: the name,
 * location, and start and end times of the event.
 *
 * @author Mark Maloof (maloof cs georgetown edu)
 * @version 1.1, 11/28/12
 * @version 1.2, 11/10/16
 * @version 1.3, 01/07/19
 */

class Event
{

  friend ostream& operator<<( ostream& out, const Event& e );
  friend istream& operator>>( istream& in, Event& e ) throw ( invalid_argument );

  public:
    Event();
    string getName() const;
    string getLocation() const;
    char getStatus() const;
    bool matchNameOrLocation( const string& query ) const;
    bool operator==( const Event& e ) const;
    bool operator!=( const Event& e ) const;
    bool operator<( const Event& e ) const;
    bool operator>( const Event& e ) const;
    void print( ostream& out = cout ) const;
    void setStatus( char status ) throw ( invalid_argument );

  private:
    char status;
    string id;
    string name;
    string location;
    DateTime start;
    DateTime end;
    DateTime modified;

    string readDoubleQuotedString( istream& in ) const;

}; // Event class

#endif

