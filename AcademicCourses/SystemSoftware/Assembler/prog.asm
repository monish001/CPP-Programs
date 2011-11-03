test start
begin balr 15,0
	 using begin+2,15
	 sr 4,4
	 l 3,=f'10'
loop l 2,data(4)
	 a 2,=f'49'
	 st 2,data(4)
	 ltorg
	 a 4,=f'4'
	 bct 3,*-16
	 br 14
data dc f'10,7'
data2 dc f'112'
	 end