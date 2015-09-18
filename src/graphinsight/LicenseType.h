/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/
#ifndef LICENSE_TYPE_H
#define LICENSE_TYPE_H
#include <string>

enum LicenseTypeEnum
{  TrialLicense=0,
   AcademicLicense=1,
   ProfessionalLicense=2
};

#ifdef Trial
static LicenseTypeEnum LicenseType=TrialLicense;
#endif

#ifdef Academic
static LicenseTypeEnum LicenseType=AcademicLicense;
#endif

#ifdef Pro
static LicenseTypeEnum LicenseType=ProfessionalLicense;
#endif

/*
static const unsigned int getRevisionNumber()
{
#ifdef REVISION_NUMBER
   return atoi(REVISION_NUMBER);
#else
   return 0;
#endif
}
*/

static std::string getVersionNumber()
{  std::string version("xxx");

#ifdef GRAPHINSIGHT_VERSION
   version = std::string(GRAPHINSIGHT_VERSION);
#endif
   return version;
}

static std::string getLicenseType()
{
    switch (LicenseType)
   {  case TrialLicense:
         return std::string("Trial");
         break;
      case AcademicLicense:
         return std::string("Academic");
         break;
      case ProfessionalLicense:
         return std::string("Pro");
         break;
   }

   return std::string("Non specified license");
}

#endif
