#ifndef _BATCH_ROBOT_TIMER_H_
#define _BATCH_ROBOT_TIMER_H_

#include <vector>

#include "globe.h"
#include "LogComm.h"
#include "OuterFactoryImp.h"

#include <util/tc_singleton.h>
#include <util/tc_autoptr.h>
#include <wbl/pthread_util.h>
#include "util/tc_thread_mutex.h"

///data
#include "BatchRobotDataDef.h"

using namespace std;
using namespace tars;
using namespace wbl;

/**
*
* 批量机器人时钟管理对象
**/
class BatchRobotTimer : public TC_HandleBase
{
public:
    BatchRobotTimer();
    virtual ~BatchRobotTimer();

public:
    //加入时钟
    int addTimer(CBatchRobotDataPtr ptr);
    //加入时钟
    int addTimer(const map<int, TRobotConf> &mapData, const map<int, vector<TRobotRechargeConfig> > &mapRechargeData);
    //检查剔除的批次
    int checkDiscardConf(const map<int, TRobotConf> &mapData);
    //加入新批次
    int addAlterConf(const map<int, TRobotConf> &mapData, const map<int, vector<TRobotRechargeConfig> > &mapRechargeData);
    //时钟
    int onTimer();

public:
    int handRobotEnter(int iBatchID);
    //机器人重入
    int checkReentry(const CBatchRobotDataPtr &ptr);
    //检查进入时间
    int checkEntryTime(const CBatchRobotDataPtr &ptr);
    //检查离开时间
    int checkLeaveTime(const CBatchRobotDataPtr &ptr);
    //移除过期批次机器人
    bool checkExpire(const CBatchRobotDataPtr &ptr);

public:
    //批次机器人数据
    map<int, CBatchRobotDataPtr> m_data;

private:
    //时钟计数
    int tick;
};

///
typedef TC_AutoPtr<BatchRobotTimer> CBatchRobotTimerPtr;

#endif