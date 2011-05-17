#include<algorithm>
#include<vector>
using namespace std;

class TheJackpotDivTwo{
	int haha;
 	public: vector<int> find(vector<int> money, int jackpot)
 	{
		if(money.size() == 1){
			money[0] += jackpot;
			jackpot =0;
			return money;
		}
		while(jackpot > 0){//loop till jackpot > 0
			sort(money.begin(), money.end());//			sort
			int dif = money[1] - money[0] + 1;
			if(dif < jackpot){
				money[0] += dif;
				jackpot -= dif;
			}else{
				money[0] += jackpot;
				jackpot =0;
			}
		}
		sort(money.begin(), money.end());//			sort
		return money;
	}
};
