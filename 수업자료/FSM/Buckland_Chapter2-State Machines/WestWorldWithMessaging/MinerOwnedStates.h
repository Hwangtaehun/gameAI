#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinerOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Miner class.
//          Note that a global state has not been implemented.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class Miner;
struct Telegram;




//------------------------------------------------------------------------
//
//  In this state the miner will walk to a goldmine and pick up a nugget
//  of gold. If the miner already has a nugget of gold he'll change state
//  to BackUpCode. If he gets thirsty he'll change state
//  to EatSnack
//------------------------------------------------------------------------
class WriteCode : public State<Miner>
{
private:
  
  WriteCode(){}

  //copy ctor and assignment should be private
  WriteCode(const WriteCode&);
  WriteCode& operator=(const WriteCode&);
 
public:

  //this is a singleton
  static WriteCode* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);

};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  miner is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class BackUpCode : public State<Miner>
{
private:
  
  BackUpCode(){}

  //copy ctor and assignment should be private
  BackUpCode(const BackUpCode&);
  BackUpCode& operator=(const BackUpCode&);
 
public:

  //this is a singleton
  static BackUpCode* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  miner will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class SendEmail : public State<Miner>
{
private:
  
  SendEmail(){}

  //copy ctor and assignment should be private
  SendEmail(const SendEmail&);
  SendEmail& operator=(const SendEmail&);
 
public:

  //this is a singleton
  static SendEmail* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  miner changes location to the saloon and keeps buying Whiskey until
//  his thirst is quenched. When satisfied he returns to the goldmine
//  and resumes his quest for nuggets.
//------------------------------------------------------------------------
class EatSnack : public State<Miner>
{
private:
  
  EatSnack(){}

  //copy ctor and assignment should be private
  EatSnack(const EatSnack&);
  EatSnack& operator=(const EatSnack&);
 
public:

  //this is a singleton
  static EatSnack* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  this is implemented as a state blip. The miner eats the stew, gives
//  Elsa some compliments and then returns to his previous state
//------------------------------------------------------------------------
class MeetTime : public State<Miner>
{
private:
  
  MeetTime(){}

  //copy ctor and assignment should be private
  MeetTime(const MeetTime&);
  MeetTime& operator=(const MeetTime&);
 
public:

  //this is a singleton
  static MeetTime* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};




#endif