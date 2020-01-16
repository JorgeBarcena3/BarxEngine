#include "..\headers\BDispacher.hpp"
#include "..//headers/BMessage.hpp"
#include "..//headers/BObserver.hpp"
 
shared_ptr< BDispacher > BDispacher::d = shared_ptr<BDispacher>(nullptr);


  void BDispacher::Send(BMessage& m)
  {
      auto list = observers.find(m.getId());

      if (list != observers.end())
      {
          for (auto& o : list->second) //Cogemos el valor del pair
          {
              o->handle(m);
          }
      }
  }
