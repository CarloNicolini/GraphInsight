#ifndef CUSTOMOBJECT_H
#define CUSTOMOBJECT_H
#include <QObject>
#include "PythonQt.h"
#include "PythonQtCppWrapperFactory.h"

//------------------------------------------------------------------------------------------------
// alternative: we create a wrapper factory, which creates a wrapper object for each CPP instance:
//------------------------------------------------------------------------------------------------

// declare our own custom object
class CustomObject2
{
public:
   CustomObject2() {}
   CustomObject2(const QString& first, const QString& last);

   QString _firstName;
   QString _lastName;

};


// add a decorator that allows to access the CustomObject from PythonQt
class CustomObject2Wrapper : public QObject
{

   Q_OBJECT

public:
   CustomObject2Wrapper(CustomObject2* obj);

public slots:
   // add access methods
   QString firstName();

   QString lastName();

   void setFirstName(const QString& name);

   void setLastName(const QString& name);

private:
   CustomObject2* _ptr;
};

// additional constructor/destructor for CustomObject2 (optional)
class CustomObject2Constructor : public QObject
{  Q_OBJECT
public slots:
   // add a constructor
   CustomObject2* new_CustomObject2(const QString& first, const QString& last);
   // add a destructor
   void delete_CustomObject2(CustomObject2* o);
};

// a factory that can create wrappers for CustomObject2
class CustomFactory : public PythonQtCppWrapperFactory
{
public:
   virtual QObject* create(const QByteArray& name, void *ptr);
};
#endif // CUSTOMOBJECT_H
