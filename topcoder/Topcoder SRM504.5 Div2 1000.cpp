class TheTicketsDivTwo{
	public:	double find(int n, int m, int k){
//		if(k<0) return 0;
		if(n==1) return 1;
		if(m-k > 1) return 0;//not possible with k dice droppings
		double p=0;
		if(m == 1) 
			p += (1.0/6 + 0.5 * this->find(n, n, k-1));//selected 1/6 + moved to last 1/2 * probablity to be chosen from last pos
		else if(m==2 && k==1)
			p += 5.0/6;
		else
			p += (0.5 * this->find(n, m-1, k-1) + (1.0/3)* this->find(n-1, m-1, k-1));//moved faltu person to last 1/2 * find(n, m-1, k-1) + moved faltu person to home 1/3 * find(n-1, m-1, k-1)
		return p;
	}
};