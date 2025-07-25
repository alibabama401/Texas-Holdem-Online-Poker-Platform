#include "Timer.h"
#include "RobotManager.h"
#include "PushRobotManager.h"

Timer::Timer()
{

}

Timer::~Timer()
{

}

//加入时钟
int Timer::addTimer(CTimerDataPtr ptr)
{
#if 0
    //参数错误
    if(ptr->szCmd.length() == 0)
        //|| ptr->ptr == (long int)NULL)
    {
        ROLLLOG_ERROR << "add timer parameter err, szCmd len: " << ptr->szCmd.length() << endl;
        //<< (ptr->ptr == (long int)NULL ? "null" : "not null") << endl;
        return -1;
    }

    //日志
    ROLLLOG_DEBUG << "add timer, " << ptr->uin << ", " << ptr->szCmd << ", " << ptr->parameter
                  << ", " << ptr->tick << ", " << ptr->retrieveTime << ", " << ptr->keepaliveTime << endl;
#endif

    //添加队列
    if (ptr != (long int)NULL)
    {
        m_data.push_back(ptr);
    }

    return 0;
}

//时钟
int Timer::onTimer()
{
    //命令字处理时钟
    return onCmdTimer();
}

//命令字处理时钟
int Timer::onCmdTimer()
{
    vector<CTimerDataPtr>::iterator iter = m_data.begin();
    while (iter != m_data.end())
    {
        (*iter)->tick--;
        if ((*iter)->tick <= 0)
        {
#if 0
            if((long int)NULL != (*iter)->ptr)
            {
                (*iter)->ptr->handleCmd((*iter)->szCmd, (*iter)->parameter);
                pushRobotManagerSingleton::getInstance()->handleCmd((*iter)->uin, (*iter)->szCmd, (*iter)->parameter);
            }
#endif
            //pushRobotManagerSingleton::getInstance()->handleCmd((*iter)->uin, (*iter)->szCmd, (*iter)->parameter);
            pushRobotManagerSingleton::getInstance()->handleCmd((*iter)->uin, (*iter)->cmd, (*iter)->parameter);
            //删除
            iter = m_data.erase(iter);
        }
        else
        {
            ++iter;
        }
    }

    return 0;
}
