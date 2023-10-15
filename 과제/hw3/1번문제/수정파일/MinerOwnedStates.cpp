#include "MinerOwnedStates.h"
#include "fsm/State.h"
#include "Miner.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif


//------------------------------------------------------------------------methods for WriteCode
WriteCode* WriteCode::Instance()
{
  static WriteCode instance;

  return &instance;
}


void WriteCode::Enter(Miner* pMiner)
{
  //if the miner is not already located at the goldmine, he must
  //change location to the gold mine
  if (pMiner->Location() != goldmine)
  {
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Think about what to write down code";

    pMiner->ChangeLocation(goldmine);
  }
}


void WriteCode::Execute(Miner* pMiner)
{  
  pMiner->AddToCurrentCode(1);

  pMiner->IncreaseFatigue();

  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Writing variable and method";

  //if enough gold mined, go and put it in the bank
  if (pMiner->CodeFull())
  {
    pMiner->GetFSM()->ChangeState(BackUpCode::Instance());
  }

  if (pMiner->Hungry())
  {
    pMiner->GetFSM()->ChangeState(EatSnack::Instance());
  }
}


void WriteCode::Exit(Miner* pMiner)
{
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " 
       << "'Compling Success' Code OK";
}


bool WriteCode::OnMessage(Miner* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}

//------------------------------------------------------------------------methods for BackUpCode

BackUpCode* BackUpCode::Instance()
{
  static BackUpCode instance;

  return &instance;
}

void BackUpCode::Enter(Miner* pMiner)
{  
  //on entry the miner makes sure he is located at the bank
  if (pMiner->Location() != bank)
  {
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Running github program";

    pMiner->ChangeLocation(bank);
  }
}


void BackUpCode::Execute(Miner* pMiner)
{
  //deposit the gold
  pMiner->AddToWealth(pMiner->CurrentCode());
    
  pMiner->SetCurrentCode(0);

  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " 
       << "Push Code. Total Code now: "<< pMiner->Wealth();

  //wealthy enough to have a well earned rest?
  if (pMiner->Wealth() >= CodeLevel)
  {
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " 
         << "I finish homework. now I send to e-mail";
      
    pMiner->GetFSM()->ChangeState(SendEmail::Instance());      
  }

  //otherwise get more gold
  else 
  {
    pMiner->GetFSM()->ChangeState(WriteCode::Instance());
  }
}


void BackUpCode::Exit(Miner* pMiner)
{
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Push commit";
}


bool BackUpCode::OnMessage(Miner* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}
//------------------------------------------------------------------------methods for SendEmail

SendEmail* SendEmail::Instance()
{
  static SendEmail instance;

  return &instance;
}

void SendEmail::Enter(Miner* pMiner)
{
  if (pMiner->Location() != shack)
  {
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Open the website";

    pMiner->ChangeLocation(shack); 

    //let the wife know I'm home
    Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pMiner->ID(),        //ID of sender
                              ent_Elsa,            //ID of recipient
                              Msg_HiHoneyImHome,   //the message
                              NO_ADDITIONAL_INFO);    
  }
}

void SendEmail::Execute(Miner* pMiner)
{ 
  //if miner is not fatigued start to dig for nuggets again.
  if (!pMiner->Fatigued())
  {
     cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " 
          << "Hello Professor .......";

     pMiner->GetFSM()->ChangeState(WriteCode::Instance());
  }

  else 
  {
    //sleep
    pMiner->DecreaseFatigue();

    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Free Time";
  } 
}

void SendEmail::Exit(Miner* pMiner)
{ 
}


bool SendEmail::OnMessage(Miner* pMiner, const Telegram& msg)
{
   SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

   switch(msg.Msg)
   {
   case Msg_StewReady:

     cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID()) 
     << " at time: " << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(pMiner->ID()) 
          << ": a few hours later";

     pMiner->GetFSM()->ChangeState(MeetTime::Instance());
      
     return true;

   }//end switch

   return false; //send message to global message handler
}

//------------------------------------------------------------------------EatSnack

EatSnack* EatSnack::Instance()
{
  static EatSnack instance;

  return &instance;
}

void EatSnack::Enter(Miner* pMiner)
{
  if (pMiner->Location() != saloon)
  {    
    pMiner->ChangeLocation(saloon);

    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Open the chocolate box";
  }
}

void EatSnack::Execute(Miner* pMiner)
{
  pMiner->EatAChocolate();

  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Eating the chocolate";

  pMiner->GetFSM()->ChangeState(WriteCode::Instance());  
}


void EatSnack::Exit(Miner* pMiner)
{ 
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "I feel happy. I'm not hungry";
}


bool EatSnack::OnMessage(Miner* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}

//------------------------------------------------------------------------MeetTime

MeetTime* MeetTime::Instance()
{
  static MeetTime instance;

  return &instance;
}


void MeetTime::Enter(Miner* pMiner)
{
  cout << "\n" << "A few days later, Today is meeting day";
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Hello, professor.";
}

void MeetTime::Execute(Miner* pMiner)
{
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "In meeting";

  pMiner->GetFSM()->RevertToPreviousState();
}

void MeetTime::Exit(Miner* pMiner)
{ 
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Bye, professor. See you next time.";
}


bool MeetTime::OnMessage(Miner* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}


