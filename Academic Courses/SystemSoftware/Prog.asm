test start
begin balr 15,0
	 using begin+2,15
	 sr 4,4
	 l 3,=f'10'
loop l 2,data(4)
	 a 2,=f'49'
	 st 2,data(4)
	 a 4,=f'4'
	 bct 3,*-16
	 br 14
	 ltorg
data dc f'1,3,3,3,3,4,5,9,0'
