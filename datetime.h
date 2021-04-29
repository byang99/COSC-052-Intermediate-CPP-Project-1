/*
 * datetime.h
 * Copyright (c) 2019 Mark Maloof.  All Rights Reserved.  See LICENSE.
 */

#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * A class for storing dates and times.  Dates are in the format
 * MM/DD/YY, and times are in the twelve-hour format, HH:MM [AM|PM].
 *
 * @author Mark Maloof (maloof at cs georgetown edu)
 * @version 1.1, 11/28/12
 */

class DateTime
{

  friend ostream& operator<<( ostream& out, const DateTime& dt );
  friend istream& operator>>( istream& in, DateTime& dt ) throw ( invalid_argument );

  public:
    DateTime();
    DateTime( int mm, int dd, int yy, int h, int m, string period ) throw ( invalid_argument );
    bool operator==( const DateTime& dt ) const;
    bool operator!=( const DateTime& dt ) const;
    bool operator<( const DateTime& dt ) const;
    bool operator>( const DateTime& dt ) const;
    void print( ostream& out = cout ) const;
    void setDate( int mm, int dd, int yy ) throw ( invalid_argument );
    void setTime( int h, int m, string period ) throw ( invalid_argument );

  private:
    int mm;
    int dd;
    int yy;
    int h;
    int m;
    string period;

    unsigned long toLong() const;

}; // DateTime

#endif
