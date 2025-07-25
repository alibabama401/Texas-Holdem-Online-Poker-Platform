#ifndef _BATCH_ROBOT_DATA_DEF_H_
#define _BATCH_ROBOT_DATA_DEF_H_

#include "globe.h"

#include <util/tc_singleton.h>
#include <util/tc_autoptr.h>

#include <wbl/pthread_util.h>

///
#include "RobotConfig.h"

using namespace std;
using namespace tars;
using namespace wbl;
//using namespace JFGame;
using namespace ai;

/**
 * 批次机器人状态
 * **/
typedef enum _enu_batch_robot_status
{
    E_BATCH_ROBOT_STATUS_IDEL  = 0,  //空闲
    E_BATCH_ROBOT_STATUS_ENTRY = 1,  //进入
    E_BATCH_ROBOT_STATUS_LEAVE = 2,  //离开
} enu_batch_robot_status;

/**
 * 批次机器人数据
 * **/
class BatchRobotData : public TC_HandleBase
{
public:
    BatchRobotData(): batch_status(E_BATCH_ROBOT_STATUS_IDEL)
    {

    }
    virtual ~BatchRobotData()
    {

    }

public:
    //设置批次信息
    void setRobotConf(const TRobotConf &conf)
    {
        robotConf = conf;
    }
    //取配置信息
    const TRobotConf &getRobotConf()
    {
        return robotConf;
    }
    //配置信息一致
    bool checkRobotConfEqual(const TRobotConf &conf)
    {
        return (robotConf.iGameID == conf.iGameID)
               && (robotConf.sRoomID == conf.sRoomID)
               && (robotConf.iBatchID == conf.iBatchID)
               && (robotConf.iRobotCount == conf.iRobotCount)
               && (robotConf.eServiceType == conf.eServiceType)
               && (robotConf.iEntryTime == conf.iEntryTime)
               && (robotConf.iLeaveTime == conf.iLeaveTime)
               && (robotConf.iMinCoins == conf.iMinCoins)
               && (robotConf.iMaxCoins == conf.iMaxCoins)
               && (robotConf.iEntryMinInterval == conf.iEntryMinInterval)
               && (robotConf.iEntryMaxInterval == conf.iEntryMaxInterval)
               && (robotConf.iMinRound == conf.iMinRound)
               && (robotConf.iMaxRound == conf.iMaxRound)
               && (robotConf.iMinPlayTime == conf.iMinPlayTime)
               && (robotConf.iMaxPlayTime == conf.iMaxPlayTime)
               && (robotConf.iMinWinningRatio == conf.iMinWinningRatio)
               && (robotConf.iMaxWinningRatio == conf.iMaxWinningRatio);
    }

public:
    //设置机器人充值配置信息
    void setRechargeConfig(const vector<TRobotRechargeConfig> &conf)
    {
        robotRechargeConf.clear();
        robotRechargeConf = conf;
    }
    //取机器人充值配置信息
    const vector<TRobotRechargeConfig> &getRechargeConfig()
    {
        return robotRechargeConf;
    }

public:
    //设置批次机器人状态
    void setBatchRobotStatus(enu_batch_robot_status eStatus)
    {
        batch_status = eStatus;
    }
    //取批次机器人状态
    enu_batch_robot_status getBatchRobotStatus()
    {
        return batch_status;
    }

private:
    //批次信息
    TRobotConf robotConf;
    //机器人充值配置信息
    vector<TRobotRechargeConfig> robotRechargeConf;

private:
    //批次机器人状态
    enu_batch_robot_status batch_status;
};

///
typedef TC_AutoPtr<BatchRobotData> CBatchRobotDataPtr;

#endif