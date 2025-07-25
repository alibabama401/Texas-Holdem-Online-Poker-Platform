#include "BatchRobotTimer.h"
#include "PushRobotManager.h"

BatchRobotTimer::BatchRobotTimer(): tick(0)
{

}

BatchRobotTimer::~BatchRobotTimer()
{

}

//加入时钟
int BatchRobotTimer::addTimer(CBatchRobotDataPtr ptr)
{
    if ((long int)NULL == ptr)
    {
        ROLLLOG_ERROR << "batch robot data ptr null." << endl;
        return -1;
    }

    //空闲状态
    if (ptr->getBatchRobotStatus() != E_BATCH_ROBOT_STATUS_IDEL)
    {
        ROLLLOG_ERROR << "batch robot status err, status: " << ptr->getBatchRobotStatus() << endl;
        return -2;
    }

    //时间区间错误
    if (ptr->getRobotConf().iLeaveTime <= ptr->getRobotConf().iEntryTime)
    {
        ROLLLOG_ERROR << "batch robot data time err, leavetime: " << ptr->getRobotConf().iLeaveTime
                      << ", entry time: " << ptr->getRobotConf().iEntryTime << endl;
        return -3;
    }

    ///
    auto it = m_data.find(ptr->getRobotConf().iBatchID);
    if (it != m_data.end())
    {
        bool bEqual = it->second->checkRobotConfEqual(ptr->getRobotConf());
        if (bEqual)
            return 1;

        //离开状态
        it->second->setBatchRobotStatus(E_BATCH_ROBOT_STATUS_LEAVE);
        //发起离开请求
        pushRobotManagerSingleton::getInstance()->handleBatchRobot(it->second);
        //加入配置
        m_data[ptr->getRobotConf().iBatchID] = ptr;
        return 2;
    }
    else
    {
        m_data[ptr->getRobotConf().iBatchID] = ptr;
    }

    return 0;
}

//加入时钟
int BatchRobotTimer::addTimer(const map<int, TRobotConf> &mapData, const map<int, vector<TRobotRechargeConfig> > &mapRechargeData)
{
    int ret = 0;

    //检查剔除的批次
    ret = checkDiscardConf(mapData);
    if (ret != 0)
    {
        ROLLLOG_ERROR << "check discard config err, ret: " << ret << endl;
        return -1;
    }

    //加入新批次
    ret = addAlterConf(mapData, mapRechargeData);
    if (ret != 0)
    {
        ROLLLOG_ERROR << "add alter config err, ret: " << ret << endl;
        return -2;
    }

    return 0;
}

//检查剔除的批次
int BatchRobotTimer::checkDiscardConf(const map<int, TRobotConf> &mapData)
{
    auto it = m_data.begin();
    while (it != m_data.end())
    {
        auto itRobot = mapData.find(it->first);
        if (itRobot == mapData.end())
        {
            //离开状态
            it->second->setBatchRobotStatus(E_BATCH_ROBOT_STATUS_LEAVE);
            //发起离开请求
            pushRobotManagerSingleton::getInstance()->handleBatchRobot(it->second);
            //移除
            m_data.erase(it++);
        }
        else
        {
            ++it;
        }
    }

    return 0;
}

//加入新批次
int BatchRobotTimer::addAlterConf(const map<int, TRobotConf> &mapData, const map<int, vector<TRobotRechargeConfig> > &mapRechargeData)
{
    auto it = mapData.begin();
    for (it = mapData.begin(); it != mapData.end(); ++it)
    {
        auto ptr = new BatchRobotData();
        if (!ptr)
            continue;

        //保存数据
        ptr->setRobotConf(it->second);

        //充值配置
        auto itRecharge = mapRechargeData.find(it->first);
        if (itRecharge != mapRechargeData.end())
        {
            ptr->setRechargeConfig(itRecharge->second);
        }

        //空闲状态
        if (ptr->getBatchRobotStatus() != E_BATCH_ROBOT_STATUS_IDEL)
        {
            ROLLLOG_ERROR << "batch robot status err, status: " << ptr->getBatchRobotStatus() << endl;
            continue;
        }

        //时间区间错误
        if (ptr->getRobotConf().iLeaveTime <= ptr->getRobotConf().iEntryTime)
        {
            ROLLLOG_ERROR << "iLeaveTime:" << ptr->getRobotConf().iLeaveTime
                          << ", iEntryTime:" << ptr->getRobotConf().iEntryTime << endl;
            continue;
        }

        auto itRobot = m_data.find(it->first);
        if (itRobot != m_data.end())
        {
            ROLLLOG_ERROR << "batch_id:" << it->first << endl;

            bool bEqual = itRobot->second->checkRobotConfEqual(ptr->getRobotConf());
            if (!bEqual)
            {
                //离开状态
                itRobot->second->setBatchRobotStatus(E_BATCH_ROBOT_STATUS_LEAVE);
                //发起离开请求
                pushRobotManagerSingleton::getInstance()->handleBatchRobot(itRobot->second);
                //加入配置
                m_data[ptr->getRobotConf().iBatchID] = ptr;
            }
        }
        else
        {
            m_data[ptr->getRobotConf().iBatchID] = ptr;
        }
    }

    return 0;
}

//超时再次推送
const int TICK_TIMEOUT_COUNT = 180;
int BatchRobotTimer::onTimer()
{
    /* tick++;
     auto iter = m_data.begin();
     while (iter != m_data.end())
     {
         if ((tick % TICK_TIMEOUT_COUNT) == 0)
         {
             //checkReentry(iter->second);
         }

         //检查进入时间
         checkEntryTime(iter->second);
         //检查离开时间
         checkLeaveTime(iter->second);
         //移除过期批次机器人
         bool bExpire = checkExpire(iter->second);
         if (bExpire)
             m_data.erase(iter++);
         else
             ++iter;
     }*/

    return 0;
}

int BatchRobotTimer::handRobotEnter(int iBatchID)
{
    auto it = m_data.find(iBatchID);
    if (it != m_data.end())
    {
        //
        it->second->setBatchRobotStatus(E_BATCH_ROBOT_STATUS_IDEL);
        //
        ROLLLOG_DEBUG << "iBatchID: " << iBatchID << ", status: " << it->second->getBatchRobotStatus() << endl;
        //
        checkEntryTime(it->second);
    }

    ROLLLOG_DEBUG << "iBatchID: " << iBatchID << ", data size: " << m_data.size() << endl;
    return 0;
}

//机器人重入
int BatchRobotTimer::checkReentry(const CBatchRobotDataPtr &ptr)
{
    if (ptr->getBatchRobotStatus() != E_BATCH_ROBOT_STATUS_ENTRY)
    {
        return -1;
    }

    //发起重入请求
    pushRobotManagerSingleton::getInstance()->handleRobotReentry(ptr);
    return 0;
}

//检查进入时间
int BatchRobotTimer::checkEntryTime(const CBatchRobotDataPtr &ptr)
{
    if (ptr->getBatchRobotStatus() != E_BATCH_ROBOT_STATUS_IDEL)
    {
        return -1;
    }

    //达到进入时间
    if ((ptr->getRobotConf().iEntryTime <= TNOW) && (ptr->getRobotConf().iLeaveTime >= TNOW))
    {
        //
        ptr->setBatchRobotStatus(E_BATCH_ROBOT_STATUS_ENTRY);
        //发起进入请求
        pushRobotManagerSingleton::getInstance()->handleBatchRobot(ptr);
    }

    return 0;
}

//检查离开时间
int BatchRobotTimer::checkLeaveTime(const CBatchRobotDataPtr &ptr)
{
    if (ptr->getBatchRobotStatus() != E_BATCH_ROBOT_STATUS_ENTRY)
    {
        return -1;
    }

    //达到离开时间
    if (ptr->getRobotConf().iLeaveTime <= TNOW)
    {
        //
        ptr->setBatchRobotStatus(E_BATCH_ROBOT_STATUS_LEAVE);
        //发起离开请求
        pushRobotManagerSingleton::getInstance()->handleBatchRobot(ptr);
    }

    return 0;
}

//移除过期批次机器人
bool BatchRobotTimer::checkExpire(const CBatchRobotDataPtr &ptr)
{
    //离开状态
    if (ptr->getBatchRobotStatus() == E_BATCH_ROBOT_STATUS_LEAVE)
    {
        return true;
    }

    //过期
    if (ptr->getRobotConf().iLeaveTime <= TNOW)
    {
        return true;
    }

    return false;
}

