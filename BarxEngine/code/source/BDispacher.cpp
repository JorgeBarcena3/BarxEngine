// File: BDispacher.cpp
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "..\headers\BDispacher.hpp"
#include "..\headers\BMessage.hpp"
#include "..\headers\BObserver.hpp"
 
shared_ptr< BDispacher > BDispacher::_instance = shared_ptr<BDispacher>(nullptr);

shared_ptr<BDispacher> BDispacher::instance()
{
    if(_instance == nullptr)
        BDispacher::_instance = shared_ptr< BDispacher >(new BDispacher);
    return _instance;
}

void BDispacher::add(BOrbserver& o, string id)
{
    observers[id].push_back(&o);
}

void BDispacher::Send(BMessage& m)
  {
      auto list = observers.find(m.getId());

      if (list != observers.end())
      {
          for (auto& o : list->second)
          {
              o->handle(m);
          }
      }
  }
