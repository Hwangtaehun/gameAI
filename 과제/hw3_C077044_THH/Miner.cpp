#include "Miner.h"

bool Miner::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}


void Miner::Update()
{
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);

  m_Hungry += 1;
  
  m_pStateMachine->Update();
}



void Miner::AddToCurrentCode(const int val)
{
  m_CurrentCode += val;

  if (m_CurrentCode < 0) m_CurrentCode = 0;
}

void Miner::AddToWealth(const int val)
{
  m_WholeCode += val;

  if (m_WholeCode < 0) m_WholeCode = 0;
}

bool Miner::Hungry()const
{
  if (m_Hungry >= HungryLevel){return true;}

  return false;
}

bool Miner::Fatigued()const
{
  if (m_Fatigue > TirednessThreshold)
  {
    return true;
  }

  return false;
}
