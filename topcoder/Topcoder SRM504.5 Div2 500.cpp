class TheNumbersWithLuckyLastDigit{
	public: int find(int n){
		int na = n%10;
		switch(na){
			case 0:
				if(n < 20) return -1;
				else return 5;
			case 1:
				if(n < 11) return -1;
				else return 2;
			case 2:
				if(n < 12) return -1;
				else return 3;
			case 3:
				if(n < 23) return -1;
				else return 5;
			case 4:
				if(n < 4) return -1;
				else return 1;
			case 5:
				if(n < 15) return -1;
				else return 3;
			case 6:
				if(n < 16) return -1;
				else return 4;
			case 7:
				if(n < 7) return -1;
				else return 1;
			case 8:
				if(n < 8) return -1;
				else return 2;
			case 9:
				if(n < 19) return -1;
				else return 4;
		}
		return -1;
	}
};
