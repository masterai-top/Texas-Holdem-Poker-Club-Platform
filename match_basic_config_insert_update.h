#ifndef __MATCH_BASIC_CONFIG_INSERT_UPDATE_H__
#define __MATCH_BASIC_CONFIG_INSERT_UPDATE_H__
class MatchBasicConfigInsertUpdateRequest
{
public:
	MatchBasicConfigInsertUpdateRequest(const string& json) {
		this->Deserialize(json);
	}
	template <typename Writer>
	void Serialize(Writer& writer) const {
		writer.StartObject();
		SERIALIZE_MEMBER(writer,id);
		SERIALIZE_MEMBER(writer,area);
		SERIALIZE_MEMBER(writer,matchName);
		SERIALIZE_MEMBER(writer,maxNumber);
		SERIALIZE_MEMBER(writer,minNumber);
		SERIALIZE_MEMBER(writer,type);
		SERIALIZE_MEMBER(writer,beginTime);
		SERIALIZE_MEMBER(writer,timeType);
		SERIALIZE_MEMBER(writer,attendFee);
		SERIALIZE_MEMBER(writer,attendCharge);
		SERIALIZE_MEMBER(writer,delayFee);
		SERIALIZE_MEMBER(writer,delayCharge);
		SERIALIZE_MEMBER(writer,scoreboard);
		SERIALIZE_MEMBER(writer,tableNumber);
		SERIALIZE_MEMBER(writer,reBuildCount);
		SERIALIZE_MEMBER(writer,reBuildScore);
		SERIALIZE_MEMBER(writer,reBuildFee);
		SERIALIZE_MEMBER(writer,reBuildCharge);
		SERIALIZE_MEMBER(writer,increaseCount);
		SERIALIZE_MEMBER(writer,increaseScore);
		SERIALIZE_MEMBER(writer,increaseFee);
		SERIALIZE_MEMBER(writer,increaseCharge);
		SERIALIZE_MEMBER(writer,riseBlind);
		SERIALIZE_MEMBER(writer,ruleId);
		SERIALIZE_MEMBER(writer,rewardId);
		SERIALIZE_MEMBER(writer,optUser);
		SERIALIZE_MEMBER(writer,createDate);

		writer.EndObject();
	}

	void toString(std::string& json) {
		StringBuffer sb;
		Writer<StringBuffer> writer(sb);
		Serialize(writer);
		json = sb.GetString();
	}

	void Deserialize(const string& json)
	{
		Document d;
		if (d.Parse(json.c_str()).HasParseError()){
			throw logic_error("parse json error. raw data : " + json);
		}
		SET_DOC_MEMBER(d,id);
		SET_DOC_MEMBER(d,area);
		SET_DOC_MEMBER(d,matchName);
		SET_DOC_MEMBER(d,maxNumber);
		SET_DOC_MEMBER(d,minNumber);
		SET_DOC_MEMBER(d,type);
		SET_DOC_MEMBER(d,beginTime);
		SET_DOC_MEMBER(d,timeType);
		SET_DOC_MEMBER(d,attendFee);
		SET_DOC_MEMBER(d,attendCharge);
		SET_DOC_MEMBER(d,delayFee);
		SET_DOC_MEMBER(d,delayCharge);
		SET_DOC_MEMBER(d,scoreboard);
		SET_DOC_MEMBER(d,tableNumber);
		SET_DOC_MEMBER(d,reBuildCount);
		SET_DOC_MEMBER(d,reBuildScore);
		SET_DOC_MEMBER(d,reBuildFee);
		SET_DOC_MEMBER(d,reBuildCharge);
		SET_DOC_MEMBER(d,increaseCount);
		SET_DOC_MEMBER(d,increaseScore);
		SET_DOC_MEMBER(d,increaseFee);
		SET_DOC_MEMBER(d,increaseCharge);
		SET_DOC_MEMBER(d,riseBlind);
		SET_DOC_MEMBER(d,ruleId);
		SET_DOC_MEMBER(d,rewardId);
		SET_DOC_MEMBER(d,optUser);
		SET_DOC_MEMBER(d,createDate);

	}

	static tars::Int32 handler(const vector<tars::Char>& reqBuf, const map<std::string, std::string>& extraInfo, vector<tars::Char>& rspBuf)
	{
	    return 0;
	}
private:
	CInteger       	_id             ;  //主键
	CString        	_area           ;  //区域：台湾、东南亚、欧洲、大陆等。
	CString        	_matchName      ;  //比赛名称
	CInteger       	_maxNumber      ;  //最大参赛人数
	CInteger       	_minNumber      ;  //最小参赛人数
	CString        	_type           ;  //比赛类型 (MTT SNG)
	CString        	_beginTime      ;  //开赛时间
	CInteger       	_timeType       ;  //比赛时间类型 (0:每天循环 , 1：单次)
	CString        	_attendFee      ;  //报名费用，格式：  道具ID:数量
	CInteger       	_attendCharge   ;  //报名服务费
	CString        	_delayFee       ;  //延迟报名费用，格式：  道具ID:数量
	CInteger       	_delayCharge    ;  //延迟报名服务费
	CInteger       	_scoreboard     ;  //初始记分牌
	CInteger       	_tableNumber    ;  //每个游戏桌子人数上限
	CInteger       	_reBuildCount   ;  //重构次数
	CInteger       	_reBuildScore   ;  //重购记分牌
	CString        	_reBuildFee     ;  //重购消耗，格式：  道具ID:数量
	CInteger       	_reBuildCharge  ;  //重购服务费
	CInteger       	_increaseCount  ;  //增购次数
	CInteger       	_increaseScore  ;  //增购记分牌
	CString        	_increaseFee    ;  //增购消耗，格式：  道具ID:数量
	CInteger       	_increaseCharge ;  //增购服务费
	CInteger       	_riseBlind      ;  //涨盲时间(秒)
	CInteger       	_ruleId         ;  //比赛规则配置Id
	CInteger       	_rewardId       ;  //比赛奖励配置Id
	CString        	_optUser        ;  //操作者
	CString        	_createDate     ;  //创建时间

};
class MatchBasicConfigInsertUpdateResponse
{
public:
	MatchBasicConfigInsertUpdateResponse(const string& json) {
		this->Deserialize(json);
	}
	template <typename Writer>
	void Serialize(Writer& writer) const {
		writer.StartObject();
		SERIALIZE_MEMBER(writer,id);
		SERIALIZE_MEMBER(writer,area);
		SERIALIZE_MEMBER(writer,matchName);
		SERIALIZE_MEMBER(writer,maxNumber);
		SERIALIZE_MEMBER(writer,minNumber);
		SERIALIZE_MEMBER(writer,type);
		SERIALIZE_MEMBER(writer,beginTime);
		SERIALIZE_MEMBER(writer,timeType);
		SERIALIZE_MEMBER(writer,attendFee);
		SERIALIZE_MEMBER(writer,attendCharge);
		SERIALIZE_MEMBER(writer,delayFee);
		SERIALIZE_MEMBER(writer,delayCharge);
		SERIALIZE_MEMBER(writer,scoreboard);
		SERIALIZE_MEMBER(writer,tableNumber);
		SERIALIZE_MEMBER(writer,reBuildCount);
		SERIALIZE_MEMBER(writer,reBuildScore);
		SERIALIZE_MEMBER(writer,reBuildFee);
		SERIALIZE_MEMBER(writer,reBuildCharge);
		SERIALIZE_MEMBER(writer,increaseCount);
		SERIALIZE_MEMBER(writer,increaseScore);
		SERIALIZE_MEMBER(writer,increaseFee);
		SERIALIZE_MEMBER(writer,increaseCharge);
		SERIALIZE_MEMBER(writer,riseBlind);
		SERIALIZE_MEMBER(writer,ruleId);
		SERIALIZE_MEMBER(writer,rewardId);
		SERIALIZE_MEMBER(writer,optUser);
		SERIALIZE_MEMBER(writer,createDate);

		writer.EndObject();
	}

	void toString(std::string& json) {
		StringBuffer sb;
		Writer<StringBuffer> writer(sb);
		Serialize(writer);
		json = sb.GetString();
	}

	void Deserialize(const string& json)
	{
		Document d;
		if (d.Parse(json.c_str()).HasParseError()){
			throw logic_error("parse json error. raw data : " + json);
		}
		SET_DOC_MEMBER(d,id);
		SET_DOC_MEMBER(d,area);
		SET_DOC_MEMBER(d,matchName);
		SET_DOC_MEMBER(d,maxNumber);
		SET_DOC_MEMBER(d,minNumber);
		SET_DOC_MEMBER(d,type);
		SET_DOC_MEMBER(d,beginTime);
		SET_DOC_MEMBER(d,timeType);
		SET_DOC_MEMBER(d,attendFee);
		SET_DOC_MEMBER(d,attendCharge);
		SET_DOC_MEMBER(d,delayFee);
		SET_DOC_MEMBER(d,delayCharge);
		SET_DOC_MEMBER(d,scoreboard);
		SET_DOC_MEMBER(d,tableNumber);
		SET_DOC_MEMBER(d,reBuildCount);
		SET_DOC_MEMBER(d,reBuildScore);
		SET_DOC_MEMBER(d,reBuildFee);
		SET_DOC_MEMBER(d,reBuildCharge);
		SET_DOC_MEMBER(d,increaseCount);
		SET_DOC_MEMBER(d,increaseScore);
		SET_DOC_MEMBER(d,increaseFee);
		SET_DOC_MEMBER(d,increaseCharge);
		SET_DOC_MEMBER(d,riseBlind);
		SET_DOC_MEMBER(d,ruleId);
		SET_DOC_MEMBER(d,rewardId);
		SET_DOC_MEMBER(d,optUser);
		SET_DOC_MEMBER(d,createDate);

	}

	static tars::Int32 handler(const vector<tars::Char>& reqBuf, const map<std::string, std::string>& extraInfo, vector<tars::Char>& rspBuf)
	{
	    return 0;
	}
private:
	CInteger       	_id             ;  //主键
	CString        	_area           ;  //区域：台湾、东南亚、欧洲、大陆等。
	CString        	_matchName      ;  //比赛名称
	CInteger       	_maxNumber      ;  //最大参赛人数
	CInteger       	_minNumber      ;  //最小参赛人数
	CString        	_type           ;  //比赛类型 (MTT SNG)
	CString        	_beginTime      ;  //开赛时间
	CInteger       	_timeType       ;  //比赛时间类型 (0:每天循环 , 1：单次)
	CString        	_attendFee      ;  //报名费用，格式：  道具ID:数量
	CInteger       	_attendCharge   ;  //报名服务费
	CString        	_delayFee       ;  //延迟报名费用，格式：  道具ID:数量
	CInteger       	_delayCharge    ;  //延迟报名服务费
	CInteger       	_scoreboard     ;  //初始记分牌
	CInteger       	_tableNumber    ;  //每个游戏桌子人数上限
	CInteger       	_reBuildCount   ;  //重构次数
	CInteger       	_reBuildScore   ;  //重购记分牌
	CString        	_reBuildFee     ;  //重购消耗，格式：  道具ID:数量
	CInteger       	_reBuildCharge  ;  //重购服务费
	CInteger       	_increaseCount  ;  //增购次数
	CInteger       	_increaseScore  ;  //增购记分牌
	CString        	_increaseFee    ;  //增购消耗，格式：  道具ID:数量
	CInteger       	_increaseCharge ;  //增购服务费
	CInteger       	_riseBlind      ;  //涨盲时间(秒)
	CInteger       	_ruleId         ;  //比赛规则配置Id
	CInteger       	_rewardId       ;  //比赛奖励配置Id
	CString        	_optUser        ;  //操作者
	CString        	_createDate     ;  //创建时间

};
#endif