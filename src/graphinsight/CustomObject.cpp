#include "CustomObject.h"

CustomObject2::CustomObject2(const QString& first, const QString& last)
{  _firstName = first;
   _lastName = last;
}

CustomObject2Wrapper::CustomObject2Wrapper(CustomObject2* obj)
{  _ptr = obj;
}

// add access methods
QString CustomObject2Wrapper::firstName()
{  return _ptr->_firstName;
}

QString CustomObject2Wrapper::lastName()
{  return _ptr->_lastName;
}

void CustomObject2Wrapper::setFirstName(const QString& name)
{  _ptr->_firstName = name;
}

void CustomObject2Wrapper::setLastName(const QString& name)
{  _ptr->_lastName = name;
}


// add a constructor
CustomObject2*CustomObject2Constructor:: new_CustomObject2(const QString& first, const QString& last)
{  return new CustomObject2(first, last);
}

// add a destructor
void CustomObject2Constructor::delete_CustomObject2(CustomObject2* o)
{  delete o;
}

// a factory that can create wrappers for CustomObject2
QObject* CustomFactory::create(const QByteArray& name, void *ptr)
{  if (name == "CustomObject2")
   {  return new CustomObject2Wrapper((CustomObject2*)ptr);
   }
   return NULL;
}

