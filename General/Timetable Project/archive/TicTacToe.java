/*
	Title: Tic-Tac-Toe Game
	Created: October 5, 2008
	Last Edited: October 11, 2008
	Author: Blmaster
	Changes:
		See Below...
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

public class TicTacToe implements ActionListener        {
	final String VERSION = "2.0";
//Setting up ALL the variables
	JFrame window = new JFrame("Tic-Tac-Toe " + VERSION);
	
	JMenuBar mnuMain = new JMenuBar();
	JMenuItem 	mnuNewGame = new JMenuItem("New Game"),	
					mnuInstruction = new JMenuItem("Instructions"),
					mnuExit = new JMenuItem("Exit"), 
					mnuAbout = new JMenuItem("About");
	
	JButton 	btn1v1 = new JButton("Player vs Player"),
				btn1vCPU = new JButton("Player vs Computer"),
				btnQuit = new JButton("Quit"),
				btnSetName = new JButton("Set Player Names"),
				btnContinue = new JButton("Continue..."),
				btnTryAgain = new JButton("Try Again?");
	JButton btnEmpty[] = new JButton[10];
	
	JPanel 	pnlNewGame = new JPanel(),
				pnlMenu = new JPanel(),
				pnlMain = new JPanel(),
				pnlTop = new JPanel(),
				pnlBottom = new JPanel(),
				pnlQuitNTryAgain = new JPanel(),
				pnlPlayingField = new JPanel();
				
	JLabel 	lblTitle = new JLabel("Tic-Tac-Toe"),
				lblTurn = new JLabel(),
				lblStatus = new JLabel("", JLabel.CENTER);
	JTextArea txtMessage = new JTextArea();
	
	final int winCombo[][] = new int[][]	{
		{1, 2, 3}, 			{1, 4, 7}, 		{1, 5, 9},
		{4, 5, 6}, 			{2, 5, 8}, 		{3, 5, 7},
		{7, 8, 9}, 			{3, 6, 9}
/*Horizontal Wins*/	/*Vertical Wins*/ /*Diagonal Wins*/
	};
	final int X = 535, Y = 342,
		mainColorR = 190, mainColorG = 50, mainColorB = 50,
		btnColorR = 70, btnColorG = 70, btnColorB = 70;
	Color clrBtnWonColor = new Color(190, 190, 190);
	int 	turn = 1, 
			player1Won = 0, 
			player2Won = 0,
			wonNumber1 = 1, 
			wonNumber2 = 1, 
			wonNumber3 = 1;
	int option;
	boolean inGame = false;
	boolean win = false;
	boolean btnEmptyClicked = false;
	String message, whoTurn, 
		Player1 = "Player 1", Player2 = "Player 2";
	

	public TicTacToe()	{	//Setting game properties and layout and sytle...
	//Setting window properties:
		window.setSize(X, Y);
		window.setLocation(350, 260);
		window.setResizable(false);
		window.setLayout(new BorderLayout());
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	//Setting Menu, Main, Top, Bottom Panel Layout/Backgrounds
		pnlMenu.setLayout(new FlowLayout(FlowLayout.CENTER));
		pnlTop.setLayout(new FlowLayout(FlowLayout.CENTER));
		pnlBottom.setLayout(new FlowLayout(FlowLayout.CENTER));
		
		pnlNewGame.setBackground(new Color(mainColorR - 50, mainColorG - 50, mainColorB- 50));
		pnlMenu.setBackground(new Color((mainColorR - 50), (mainColorG - 50), (mainColorB- 50)));
		pnlMain.setBackground(new Color(mainColorR, mainColorG, mainColorB));
		pnlTop.setBackground(new Color(mainColorR, mainColorG, mainColorB));
		pnlBottom.setBackground(new Color(mainColorR, mainColorG, mainColorB));
		
	//Setting up Panel QuitNTryAgain
		pnlQuitNTryAgain.setLayout(new GridLayout(1, 2, 2, 2));
		pnlQuitNTryAgain.add(btnTryAgain);
		pnlQuitNTryAgain.add(btnQuit);
		
	//Adding menu items to menu bar
		mnuMain.add(mnuNewGame);
		mnuMain.add(mnuInstruction);
		mnuMain.add(mnuAbout);
		mnuMain.add(mnuExit);//	Menu Bar is Complete
		
	//Adding buttons to NewGame panel
		pnlNewGame.setLayout(new GridLayout(4, 1, 2, 10));
		pnlNewGame.add(btnContinue);
		pnlNewGame.add(btn1v1);
		pnlNewGame.add(btn1vCPU);
		pnlNewGame.add(btnSetName);
	
	//Setting Button propertied
		btnTryAgain.setEnabled(false);
		btnContinue.setEnabled(false);
	
	//Setting txtMessage Properties
		txtMessage.setBackground(new Color(mainColorR-30, mainColorG-30, mainColorB-30));
		txtMessage.setForeground(Color.white);
		txtMessage.setEditable(false);
		
	//Adding Action Listener to all the Buttons and Menu Items
		mnuNewGame.addActionListener(this);
		mnuExit.addActionListener(this);
		mnuInstruction.addActionListener(this);
		mnuAbout.addActionListener(this);
		btn1v1.addActionListener(this);
		btn1vCPU.addActionListener(this);
		btnQuit.addActionListener(this);
		btnSetName.addActionListener(this);
		btnContinue.addActionListener(this);
		btnTryAgain.addActionListener(this);
	
	//Setting up the playing field
		pnlPlayingField.setLayout(new GridLayout(3, 3, 2, 2));
		pnlPlayingField.setBackground(Color.black);
		for(int i=1; i<=9; i++)	{
			btnEmpty[i] = new JButton();
			btnEmpty[i].setBackground(new Color(btnColorR, btnColorG, btnColorB));
			btnEmpty[i].addActionListener(this);
			pnlPlayingField.add(btnEmpty[i]);//	Playing Field is Compelte
		}

	//Adding everything needed to pnlMenu and pnlMain
		pnlMenu.add(mnuMain);
		pnlMain.add(lblTitle);
		
	//Adding to window and Showing window
		window.add(pnlMenu, BorderLayout.NORTH);
		window.add(pnlMain, BorderLayout.CENTER);
		window.setVisible(true);
	}
	
	public static void main(String[] args)	{
		new TicTacToe();//	Calling the cl*** construtor.
							//		PROGRAM STARTS HERE!
	}



/*
		-------------------------
		Start of all METHODS.	|
		-------------------------
*/
	public void showGame()	{	//	Shows the Playing Field
										//	*IMPORTANT*- Does not start out brand new (meaning just shows what it had before)
		clearPanelSouth();
		pnlMain.setLayout(new BorderLayout());
		pnlTop.setLayout(new BorderLayout());
		pnlBottom.setLayout(new BorderLayout());
		pnlTop.add(pnlPlayingField);
		pnlBottom.add(lblTurn, BorderLayout.WEST);
		pnlBottom.add(lblStatus, BorderLayout.CENTER);
		pnlBottom.add(pnlQuitNTryAgain, BorderLayout.EAST);
		pnlMain.add(pnlTop, BorderLayout.CENTER);
		pnlMain.add(pnlBottom, BorderLayout.SOUTH);
		pnlPlayingField.requestFocus();
		inGame = true;
		checkTurn();
		checkWinStatus();
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public void new1v1Game()	{	//	Sets all the game required variables to default
											//	and then shows the playing field.
											//	(Basically: Starts a new 1v1 Game)
		btnEmpty[wonNumber1].setBackground(new Color(btnColorR, btnColorG, btnColorB));
		btnEmpty[wonNumber2].setBackground(new Color(btnColorR, btnColorG, btnColorB));
		btnEmpty[wonNumber3].setBackground(new Color(btnColorR, btnColorG, btnColorB));
		for(int i=1; i<10; i++)	{
			btnEmpty[i].setText("");
			btnEmpty[i].setEnabled(true);
		}
		turn = 1;
		win = false;
		showGame();
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public void goBack()	{
		clearPanelSouth();
		pnlMain.setLayout(new FlowLayout(FlowLayout.CENTER));
		pnlMain.add(lblTitle);
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public void checkWin()	{	//	checks if there are 3 symbols in a row vertically, diagonally, or horizontally.
										//	then shows a message and disables buttons. If the game is over then it asks
										//	if you want to play again.
		for(int i=0; i<8; i++)	{
			if(
				!btnEmpty[winCombo[i][0]].getText().equals("") &&
				btnEmpty[winCombo[i][0]].getText().equals(btnEmpty[winCombo[i][1]].getText()) &&
				//								if {1 == 2 && 2 == 3}
				btnEmpty[winCombo[i][1]].getText().equals(btnEmpty[winCombo[i][2]].getText()))	{
				/*
					The way this checks the if someone won is:
					First: it checks if the btnEmpty[x] is not equal to an empty string-	x being the array number 
						inside the multi-dementional array winCombo[checks inside each of the 7 sets][the first number]
					Secong: it checks if btnEmpty[x] is equal to btnEmpty[y]- x being winCombo[each set][the first number]
						y being winCombo[each set the same as x][the second number] (So basically checks if the first and
						second number in each set is equal to each other)
					Third: it checks if btnEmtpy[y] is eual to btnEmpty[z]- y being the same y as last time and z being
						winCombo[each set as y][the third number]
					Conclusion:	So basically it checks if it is equal to the btnEmpty is equal to each set of numbers
				*/
				win = true;
				wonNumber1 = winCombo[i][0];
				wonNumber2 = winCombo[i][1];
				wonNumber3 = winCombo[i][2];
				btnEmpty[wonNumber1].setBackground(clrBtnWonColor);
				btnEmpty[wonNumber2].setBackground(clrBtnWonColor);
				btnEmpty[wonNumber3].setBackground(clrBtnWonColor);
				break;
			}
		}
		if(win || (!win && turn>9))	{
			if(win)	{
				if(turn % 2 == 0)	{
					message = Player1 + " has won";
					player1Won++;
				}
				else	{
					message = Player2 + " has won";
					player2Won++;
				}
				win = false;
			}	else if(!win && turn>9)
				message = "Both players have tied!\nBetter luck next time.";
			showMessage(message);
			for(int i=1; i<=9; i++)	{
				btnEmpty[i].setEnabled(false);
			}
			btnTryAgain.setEnabled(true);
			checkWinStatus();
		} else
			checkTurn();
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public void checkTurn()	{
		if(!(turn % 2 == 0))	{
			whoTurn = Player1 + " [X]";
		}	else	{
			whoTurn = Player2 + " [O]";
		}
		lblTurn.setText("Turn: " + whoTurn);
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public void checkWinStatus()	{
		lblStatus.setText(Player1 + ": " + player1Won + " | " + Player2 + ": " + player2Won);	
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public void askUserForPlayerNames()	{
		String temp = Player2;
		
		temp = getInput("Enter player 1 name:", Player1);
		if(temp == null)	{/*Do Nothing*/}
		else if(temp.equals(""))
			showMessage("Invalid Name!");
		else if(temp.equals(Player2))	{
			option = askMessage("Player 1 name matches Player 2's\nDo you want to continue?", "Name Match", JOptionPane.YES_NO_OPTION);
			if(option == JOptionPane.YES_OPTION)
				Player1 = temp;
		} else if(temp != null)	{
			Player1 = temp;
		}
		
		temp = getInput("Enter player 2 name:", Player2);
		if(temp == null)	{/*Do Nothing*/}
		else if(temp.equals(""))
			showMessage("Invalid Name!");
		else if(temp.equals(Player1))	{
			option = askMessage("Player 2 name matches Player 1's\nDo you want to continue?", "Name Match", JOptionPane.YES_NO_OPTION);
			if(option == JOptionPane.YES_OPTION)
				Player2 = temp;
		} else if(temp != null)	{
			Player2 = temp;
		}
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public void setDefaultLayout()	{
		pnlMain.setLayout(new GridLayout(2, 1, 2, 5));
		pnlTop.setLayout(new FlowLayout(FlowLayout.CENTER));
		pnlBottom.setLayout(new FlowLayout(FlowLayout.CENTER));
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public int askMessage(String message, String title, int option)	{
		return JOptionPane.showConfirmDialog(null, message, title, option);
	}
//-----------------------------------------------------------------------------------------------------------------------------------
	public String getInput(String message, String setText)	{
		return JOptionPane.showInputDialog(null, message, setText);
	}
//-----------------------------------------------------------------------------------------------------------------------------------
	public void showMessage(String message)	{
		JOptionPane.showMessageDialog(null, message);
	}
//-----------------------------------------------------------------------------------------------------------------------------------	
	public void clearPanelSouth()	{	//Removes all the possible panels 
												//that pnlMain, pnlTop, pnlBottom
												//could have.
		pnlMain.remove(lblTitle);
		pnlMain.remove(pnlTop);
		pnlMain.remove(pnlBottom);
		pnlTop.remove(pnlNewGame);
		pnlTop.remove(txtMessage);
		pnlTop.remove(pnlPlayingField);
		pnlBottom.remove(lblTurn);
		pnlBottom.remove(pnlQuitNTryAgain);
	}
/*
		-------------------------------------
		End of all non-Abstract METHODS.		|
		-------------------------------------
*/

//-------------------ACTION PERFORMED METHOD (Button Click --> Action?)-------------------------//	
	public void actionPerformed(ActionEvent click)	{
		Object source = click.getSource();
		for(int i=1; i<=9; i++)	{
			if(source == btnEmpty[i] && turn <	10)	{
				btnEmptyClicked = true;
				if(!(turn % 2 == 0))
					btnEmpty[i].setText("X");
				else
					btnEmpty[i].setText("O");
				btnEmpty[i].setEnabled(false);
				pnlPlayingField.requestFocus();
				turn++;
			}
		}
		if(btnEmptyClicked)	{
			checkWin();
			btnEmptyClicked = false;
		}
		if(source == mnuNewGame || source == mnuInstruction || source == mnuAbout)	{
			clearPanelSouth();
			setDefaultLayout();
			
			if(source == mnuNewGame)	{//NewGame
				pnlTop.add(pnlNewGame);
			}	
			else if(source == mnuInstruction || source == mnuAbout)	{
				if(source == mnuInstruction)	{// Instructions
					message = 	"Instructions:\n\n" +
									"Your goal is to be the first player to get 3 X's or O's in a\n" +
									"row. (horizontally, diagonally, or vertically)\n" +
									Player1 + ": X\n" +
									Player2 + ": O\n";
				} else	{//About
					message = 	"About:\n\n" +
									"Title: Tic-Tac-Toe\n" +
									"Creator: Blmaster\n" +
									"Version: " + VERSION + "\n";
				}
				txtMessage.setText(message);
				pnlTop.add(txtMessage);
			}	
			pnlMain.add(pnlTop);
		}
		else if(source == btn1v1 || source == btn1vCPU)	{
			if(inGame)	{
				option = askMessage("If you start a new game," +
					"your current game will be lost..." + "\n" +
					"Are you sure you want to continue?", 
					"Quit Game?" ,JOptionPane.YES_NO_OPTION
				);
				if(option == JOptionPane.YES_OPTION)
					inGame = false;
			}
			if(!inGame)	{
				if(source == btn1v1)	{// 1 v 1 Game
					btnContinue.setEnabled(true);
					new1v1Game();
				} else	{// 1 v CPU Game
					showMessage("Coming Soon!");
				}
			}
		}
		else if(source == btnContinue)	{
			checkTurn();
			showGame();
		}
		else if(source == btnSetName)	{
			askUserForPlayerNames();
		}
		else if(source == mnuExit)	{
			option = askMessage("Are you sure you want to exit?", "Exit Game", JOptionPane.YES_NO_OPTION);
			if(option == JOptionPane.YES_OPTION)
				System.exit(0);
		}
		else if(source == btnTryAgain)	{
			new1v1Game();
			btnTryAgain.setEnabled(false);
		}
		else if(source == btnQuit)	{
			inGame = false;
			btnContinue.setEnabled(false);
			goBack();
		}
		pnlMain.setVisible(false);
		pnlMain.setVisible(true);
	}
//-------------------END OF ACTION PERFORMED METHOD-------------------------//
}
/* Future Plans:
	-Add AI
*/
/*	Changes:
	2.0- changes below: bug fixes [Stable]
		1.95- fixed bug: TryAgain Button takes over Status Label
		1.9- added Label that shows Player 1 and Player 2 wins
		1.8- removed Try Again pop-up. Added Try Again Button
		1.7- removed Back Button. Added Continue Button
		1.6-	fixed bugs below...
			fixed bug: Same name for both players.
			fixed bug: Names updated in game if user changes.
			fixed bug: Names are null if user presses cancel.
		1.5- 	added function to set Player Names.
		1.4- 	program more efficient/faster.
		1.35- fixed bugs, added turn status to status bar.
		1.3- 	added Status bar with quit button during gameplay.
		1.2- 	changed theme.
		1.15- fixed bug: one win combo not working.
		1.1- 	added play again function.
	1.0- 	changes below: (problems gone!) [Stable]
		0.9- 	added back button, added comments.
		0.8- 	added dynamic win message.
		0.7- 	added game function- game playable.
		0.6- 	changed menu layout.
		0.5- 	basic functions with menu and nice GUI.
*/


/*	LAYOUT OF THE GAME:
	
	THE WINDOW: (pnlMenu/pnlMain)
	pnlMenu: (THE MENU)
	pnlMain:	(pnlTop/pnlBottom)
	pnlTop:	(pnlPlayingField/INSTRUCTIONS/ABOUT/NEW GAME)
	pnlBottom:(STATUS BAR/BACK BUTTON)

	/////////////////////////////////////////////////--------------|
	/						pnlMenu								/					|
	/																/					|
	/////////////////////////////////////////////////-----|			|
	/																/		|			|
	/																/		|			|
	/																/		|			|
	/						pnlTop								/		|			|
	/																/		|			|- MAIN WINDOW
	/																/		|-			|
	/																/		|pnlMain	|
	/																/		|			|
	/																/		|			|
	/																/		|			|
	/																/		|			|
	/																/		|			|		
	/////////////////////////////////////////////////		|			|
	/						pnlBottom							/		|			|
	/////////////////////////////////////////////////-----|--------|
	
*/
