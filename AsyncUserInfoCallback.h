#ifndef _ASYNC_USER_INFO_CB_H_
#define _ASYNC_USER_INFO_CB_H_

#include "HallServant.h"
#include "Robot.h"

using namespace userinfo;
using namespace hall;

/**
 * 操作类型
*/
enum eumActType
{
    E_ACT_TYPE_OFFLINE     = 1,  //机器人下线
    E_ACT_TYPE_MODIFY_COIN = 2,  //修改机器人货币
};

/**
 * 异步用户信息回调类
 */
class AsyncUserInfoCallback : public HallServantPrxCallback
{
public:
    /**
     *
    */
    AsyncUserInfoCallback(const userinfo::GetUserBasicReq &req);

    /**
     *
    */
    AsyncUserInfoCallback(const userinfo::GetUserAccountReq &req, const CBatchRobotDataPtr &ptr,
                          const CRobotPtr &robotPtr, eumActType actType);

    /**
     *
    */
    AsyncUserInfoCallback(const userinfo::ModifyUserAccountReq &req, const CBatchRobotDataPtr &ptr,
                          const CRobotPtr &robotPtr, eumActType actType);

    /**
     *
    */
    ~AsyncUserInfoCallback();

public:
    //获取用户个人信息
    void callback_getUserBasic(tars::Int32 ret, const userinfo::GetUserBasicResp &resp);
    void callback_getUserBasic_exception(tars::Int32 ret);

    //获取用户账号财富信息
    void callback_getUserAccount(tars::Int32 ret, const userinfo::GetUserAccountResp &resp);
    void callback_getUserAccount_exception(tars::Int32 ret);

    //修改用户账号财富信息
    void callback_modifyUserAccount(tars::Int32 ret);
    void callback_modifyUserAccount_exception(tars::Int32 ret);

public:
    //随机取数
    long int nnrand(long int max, long int min = 0)
    {
        srand(TNOWMS);
        return min + rand() % (max - min + 1);
    }

private:
    GetUserBasicReq         m_reqGUB;  //用户基本信息
    GetUserAccountReq       m_reqGUA;  //用户账户信息
    ModifyUserAccountReq    m_reqMUA;  //变更用户账户

private:
    CBatchRobotDataPtr robotDataPtr;  //机器人数据
    CRobotPtr m_robotPtr;             //机器人对象
    eumActType m_actType;             //操作类型
};

#endif  // _ASYNC_USER_INFO_CB_H_