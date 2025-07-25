#ifndef _TIMER_H_
#define _TIMER_H_

#include <vector>

#include "OuterFactoryImp.h"
#include "LogComm.h"
#include "globe.h"

#include <util/tc_singleton.h>
#include <util/tc_autoptr.h>
#include <wbl/pthread_util.h>
#include "util/tc_thread_mutex.h"

///
#include "IGameLogic.h"
#include "TimerDataDef.h"

using namespace std;
using namespace tars;
using namespace wbl;

/**
*
* 时钟管理对象
**/
class Timer : public TC_HandleBase
{
public:
    Timer();
    virtual ~Timer();

public:
    //加入时钟
    int addTimer(CTimerDataPtr ptr);
    //时钟
    int onTimer();
    //命令字处理时钟
    int onCmdTimer();

public:
    //时钟数据
    vector<CTimerDataPtr> m_data;
};

///
typedef TC_AutoPtr<Timer> CTimerPtr;

#endif