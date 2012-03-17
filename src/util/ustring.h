/*
    Mosh: the mobile shell
    Copyright 2012 Keith Winstein

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef USTRING_HPP
#define USTRING_HPP

#include <wchar.h>
#include <vector>

/* Some platforms like Android lack wstring.  And Mosh does not need
   many wstring features.  So we use a tiny home-grown replacement
   instead. */

class ustring {
public:
  ustring()
    : vec()
  {}

  ustring( const wchar_t *str )
    : vec() {

    const wchar_t *end = str;
    while ( *end != L'\0' ) {
      end++;
    }
    vec = std::vector<wchar_t>( str, end );
  }

  const std::vector<wchar_t>& as_vector() const {
    return vec;
  }

  wchar_t *as_new_cstr() const {
    // The spec requires that vector elements are contiguous.
    // http://www.open-std.org/jtc1/sc22/wg21/docs/lwg-defects.html#69

    wchar_t *arr = new wchar_t[ vec.size() + 1 ];
    memcpy( arr, &vec[ 0 ], vec.size() * sizeof( wchar_t ) );
    arr[ vec.size() ] = L'\0';
    return arr;
  }

  bool operator==( const ustring &other ) const {
    return vec == other.vec;
  }

  bool empty() const {
    return vec.empty();
  }

private:
  std::vector<wchar_t> vec;
};

#endif
