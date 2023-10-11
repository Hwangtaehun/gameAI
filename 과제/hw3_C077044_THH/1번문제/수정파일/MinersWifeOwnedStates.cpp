#include "MinersWifeOwnedStates.h"
#include "MinerOwnedStates.h"
#include "MinersWife.h"
#include "Locations.h"
#include "Time/CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state

ProfessorGlobalState* ProfessorGlobalState::Instance()
{
  static ProfessorGlobalState instance;

  return &instance;
}


void ProfessorGlobalState::Execute(MinersWife* wife)
{
  //1 in 10 chance of needing the bathroom (provided she is not already
  //in the bathroom)
  if ( (RandFloat() < 0.1) && 
       !wife->GetFSM()->isInState(*WriteMemo::Instance()) )
  {
      switch (RandInt(0, 1))
      {
      case 0:
          cout << "\n" << GetNameOfEntity(wife->ID()) << ": This part is weak";
          wife->GetFSM()->ChangeState(FindReference::Instance());
          break;
      case 1:
          cout << "\n" << GetNameOfEntity(wife->ID()) << ": This part is error";
          wife->GetFSM()->ChangeState(WriteMemo::Instance());
          break;
      }
  }
}

bool ProfessorGlobalState::OnMessage(MinersWife* wife, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

  switch(msg.Msg)
  {
  case Msg_HiHoneyImHome:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(wife->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(wife->ID()) << 
          ": Hi honey. Let me make you some of mah fine country stew";

     wife->GetFSM()->ChangeState(InOffice::Instance());
   }

   return true;

  }//end switch

  return false;
}

//-------------------------------------------------------------------------CheckCode

CheckCode* CheckCode::Instance()
{
  static CheckCode instance;

  return &instance;
}


void CheckCode::Enter(MinersWife* wife)
{
  cout << "\n" << GetNameOfEntity(wife->ID()) << ": Open the file";
}


void CheckCode::Execute(MinersWife* wife)
{
  switch(RandInt(0,2))
  {
  case 0:

    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Reading the code";

    break;

  case 1:

    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Drinking coffee";

    break;

  case 2:

    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Taking a break";

    break;
  }
}

void CheckCode::Exit(MinersWife* wife)
{
}

bool CheckCode::OnMessage(MinersWife* wife, const Telegram& msg)
{
  return false;
}

//------------------------------------------------------------------------WriteMemo

WriteMemo* WriteMemo::Instance()
{
  static WriteMemo instance;

  return &instance;
}


void WriteMemo::Enter(MinersWife* wife)
{  
  cout << "\n" << GetNameOfEntity(wife->ID()) << ": Open the memo"; 
}


void WriteMemo::Execute(MinersWife* wife)
{
  cout << "\n" << GetNameOfEntity(wife->ID()) << ": Write memo";

  wife->GetFSM()->RevertToPreviousState();
}

void WriteMemo::Exit(MinersWife* wife)
{
  cout << "\n" << GetNameOfEntity(wife->ID()) << ": Save memo and close";
}


bool WriteMemo::OnMessage(MinersWife* wife, const Telegram& msg)
{
  return false;
}

//------------------------------------------------------------------------WriteMemo

FindReference* FindReference::Instance()
{
    static FindReference instance;

    return &instance;
}


void FindReference::Enter(MinersWife* wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Research the website";
}


void FindReference::Execute(MinersWife* wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Find reference";

    wife->GetFSM()->ChangeState(WriteMemo::Instance());
}

void FindReference::Exit(MinersWife* wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Copy the web address";
}


bool FindReference::OnMessage(MinersWife* wife, const Telegram& msg)
{
    return false;
}

//------------------------------------------------------------------------InOffice

InOffice* InOffice::Instance()
{
  static InOffice instance;

  return &instance;
}


void InOffice::Enter(MinersWife* wife)
{
  //if not already cooking put the stew in the oven
  if (!wife->Cooking())
  {
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": received mail";
  
    //send a delayed message myself so that I know when to take the stew
    //out of the oven
    Dispatch->DispatchMessage(1.5,                  //time delay
                              wife->ID(),           //sender ID
                              wife->ID(),           //receiver ID
                              Msg_StewReady,        //msg
                              NO_ADDITIONAL_INFO); 

    wife->SetCooking(true);
  }
}


void InOffice::Execute(MinersWife* wife)
{
  cout << "\n" << GetNameOfEntity(wife->ID()) << ": Organize notes and Prepare for a meeting.";
}

void InOffice::Exit(MinersWife* wife)
{
  SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  
  cout << "\n" << GetNameOfEntity(wife->ID()) << ": talking the code";
}


bool InOffice::OnMessage(MinersWife* wife, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

  switch(msg.Msg)
  {
    case Msg_StewReady:
    {
      cout << "\nMessage received by " << GetNameOfEntity(wife->ID()) <<
           " at time: " << Clock->GetCurrentTime();

      SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
      cout << "\n" << GetNameOfEntity(wife->ID()) << ": Hello, Please have a seat here.";

      //let hubby know the stew is ready
      Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
                                wife->ID(),
                                ent_Miner_Bob,
                                Msg_StewReady,
                                NO_ADDITIONAL_INFO);

      wife->SetCooking(false);

      wife->GetFSM()->ChangeState(CheckCode::Instance());               
    }

    return true;

  }//end switch

  return false;
}