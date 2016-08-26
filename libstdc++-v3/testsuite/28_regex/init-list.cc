// { dg-do run { target c++11 } }

// Copyright (C) 2008-2016 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.
//

#include <regex>
#include <testsuite_hooks.h>

using namespace std;

int test01(void)
{
  bool test = true;

  regex r = { 'a', 'b', 'c' };
  cmatch res;
  VERIFY(regex_match ("abc", res, r));
  VERIFY(!regex_match ("ab", res, r));

  r = { 'd', 'e', 'f' };
  VERIFY(regex_match ("def", res, r));
  VERIFY(!regex_match ("abc", res, r));

  return test;
}

int main()
{
  __gnu_test::set_memory_limits();
  test01();
  return 0;
}
