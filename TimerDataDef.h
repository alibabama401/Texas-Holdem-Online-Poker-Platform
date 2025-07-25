#ifndef _TIMER_DATA_DEF_H_
#define _TIMER_DATA_DEF_H_

#include "globe.h"
//#include "IGameLogic.h"

#include <util/tc_singleton.h>
#include <util/tc_autoptr.h>
#include <wbl/pthread_util.h>

using namespace std;
using namespace tars;
using namespace wbl;

/**
 * 时钟数据
 * **/
class TimerData : public TC_HandleBase
{
public:
    TimerData() : szCmd(""), cmd(0), parameter(""), tick(0), retrieveTime(0), keepaliveTime(0), uin(0)
    {

    }

    virtual ~TimerData()
    {

    }

public:
    //
    string szCmd;
    //
    int cmd;
    //
    string parameter;
    //
    int tick;
    //
    int retrieveTime;
    //
    int keepaliveTime;
    //
    tars::Int64 uin;
};

typedef TC_AutoPtr<TimerData> CTimerDataPtr;

#endif