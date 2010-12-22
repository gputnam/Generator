//____________________________________________________________________________
/*
 Copyright (c) 2003-2010, GENIE Neutrino MC Generator Collaboration
 For the full text of the license visit http://copyright.genie-mc.org
 or see $GENIE/LICENSE

 Author: Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         STFC, Rutherford Appleton Laboratory - October 03, 2005

 For the class documentation see the corresponding header file.

 Important revisions after version 2.0.0 :

*/
//____________________________________________________________________________

#include "Utils/CmdLineArgParserException.h"

using std::endl;
using namespace genie::exceptions;

//___________________________________________________________________________
namespace genie {
 namespace exceptions {
   ostream & operator<< (ostream& stream, const CmdLineArgParserException & e)
   {
      e.Print(stream);
      return stream;
   }
 }
}
//___________________________________________________________________________
CmdLineArgParserException::CmdLineArgParserException()
{
  this->Init();
}
//___________________________________________________________________________
CmdLineArgParserException::CmdLineArgParserException(
                                       const CmdLineArgParserException & exc)
{
  this->Copy(exc);
}
//___________________________________________________________________________
CmdLineArgParserException::~CmdLineArgParserException()
{

}
//___________________________________________________________________________
void CmdLineArgParserException::Init(void)
{
  this->fReason    = "";
  this->fArgFound  = true;

}
//___________________________________________________________________________
void CmdLineArgParserException::Copy(const CmdLineArgParserException & e)
{
  this->fReason   = e.fReason;
  this->fArgFound = e.fArgFound;
}
//___________________________________________________________________________
void CmdLineArgParserException::Print(ostream & stream) const
{
  stream << "**EXCEPTION Reason: " << this->ShowReason() << endl;
}
//___________________________________________________________________________