////TT1.java : has a 'Back button' only to go back to page1 and hide page2.
//frame2.java
import java.sql.*;
//import javax.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class myFrame3 extends JFrame{
	public static void main(String args[])
	{
		new myFrame3("teacher");
	}
    myFrame3(String tableName){
		innerBox.frame2Caller = this;
		innerBox.tableName = tableName;
        setTitle("Administrator Screen");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		setResizable(false); 
		JdbcConnection myCon = new JdbcConnection();
		try
		{
			Connection con = myCon.conn();//Get a Connection object
			stmt = con.createStatement();//Get a Statement object				
		}
		catch(SQLException e)
		{
			System.out.println("1.)Error in con or stmt "+e.toString());
		}		
		btnHead.setEnabled(false);
		btnFoot.setEnabled(false);
		add(btnHead, BorderLayout.NORTH);
		add(btnFoot, BorderLayout.SOUTH);
		JLabel northLabel = new JLabel(tableName+"s:");
		JComboBox northCBox = new JComboBox(myFrame.initialOptions(tableName, "id"));
		JPanel row1CenterPanel = new JPanel();
		row1CenterPanel.add(northLabel);
		row1CenterPanel.add(northCBox);
		JPanel daysCenterPanel = new JPanel();
		daysCenterPanel.setLayout(new GridLayout(5,9));
		for(int count=0; count<=5*9; count++)
			daysCenterPanel.add(new innerBox().getPanel());
		JPanel centerPanel = new JPanel();
		centerPanel.add(row1CenterPanel);
		centerPanel.add(daysCenterPanel);
	}
	public boolean isEntrySaved(int day, int period)
	{
		qry = "";
	}
	static JButton btnHead = new JButton("Welcome to page 2");
	static JButton btnFoot = new JButton("Waiting for any event");
	static Statement stmt;
	static ResultSet rset;
	static String qry;

}
class innerBox
{
	innerBox()
	{
		System.out.println("In innerBox constructor with day and period ="+day+" "+period);
		panel = new JPanel();
		myFrame3.isEntrySaved(d, p);
		
		btn = new JButton("");
		
		panel.add(btn1);
		panel.add(btn2);
		panel.add(btn3);
		panel.add(btn4);
	}
	JPanel getPanel(){
		return (this.panel);
	}
	boolean state = false;// true if entry is there for corr. day and period
	String strBtn1;
	String strBtn2;
	String strBtn3;
	String strBtn4;
	JButton btn1;
	JButton btn2;
	JButton btn3;
	JButton btn4;
	JPanel panel;
	int day=0;
	int period=0;
	static int d=0;
	static int p=0;
	static String tableName;
	static frame2Caller;
	static
	{
		if(p==9)
		{
			d++;
			p=1;
		}
		else
			p++;
	}
}